//DAVID SOLODUKHIN
#include "myLib.h"
#include "text.h"
#include <stdlib.h>
#include <stdio.h>
#include "bg.h"
#include "title.h"
#include "go.h"
#include "bandp.h"
#include "bg2.h"
#include "play.h"


OamEntry sprites[128];


u16 currKey, prevKey;


//////////////////GAME VARS/////////////////////////
volatile int score = 0;
volatile int cooldown = 0; //COOLDOWN USED FOR BUTTONS AND REDRAW
volatile int pLax = 0; //BACKGROUND DRAWN WITH PARALLAX
volatile int suspend = 0;
int row = 80; //BIRD Y position
int col = 35; //BIRD X position

int rVel = 1; //BIRD X AND Y VELOCITY
int cVel = 0;
const int g = 1; //VELOCITY ADDEND (ACCELERATION)
char scoreStr[100]; //BUFFER HOLDS STRING VERSION OF SCORE


PIPE pipes[NUMPIPES]; //ARRAY OF PIPES PRESENT AT ONCE
PIPE *cur; //POINTER TO A PIPE OBJ

OamEntry *bird; //BIRD SPRITE OBJ
OamEntry *pipe;
int cSwitch = 0;
GBAState state = START;
int bgRand = 0;
short color = GREEN;
unsigned int seed = 79827348;
/* OLD RENDERING MODE: UNCOMMENT IF SPRITES FAIL
int oldcol = col;
int oldrow = row;
unsigned short *screenBuffer;
*/


int main()
{
    /* OLD RENDERING MODE
    screenBuffer = (unsigned short *)malloc(sizeof(unsigned short)*38400);
    if (NULL == screenBuffer) {
    	screenBuffer = (unsigned short *)0x6000000;
    }
    int bStart[BIRD2_HEIGHT];
    int bWidth[BIRD2_HEIGHT];
    birdSetup(bStart, bWidth, bird2);

    */
	srand(seed);
	bgRand = rand() % 10;
    initGraphics();
    setupOBJS();
    ///////////
    while(1)
    {


        switch(state)
        {
        case START:
            drawImage3(0,0,240,160, title);
            drawString(160/2, 240/2 - 50/2, "PRESS A", YELLOW);
            drawRect(98, 240/2 -60/2 - 2, 33,56, GREEN);
            drawImage3(240/2- 60/2, 100 , 52, 29, play);
            state = START_NODRAW;
            hideSprites();
            renderSprites();
            break;
        case START_NODRAW:
            keyInput(PLAY);
            //delay(10);
            waitForVblank();
            if (cSwitch <= 30) {
            	color = BLUE;
            } else if (cSwitch <= 60){
            	color = RED;
            }
            if (cSwitch > 60) {
            	cSwitch = 0;
            }
            cSwitch++;
            drawRect(98, 240/2 -60/2 - 2, 33,56, color);
            drawImage3(240/2- 60/2, 100 , 52, 29, play);
            
            break;
        case PLAY:

            keyInput(START);
            moveBird();
            movePipes();
            waitForVblank();
            renderSprites();

            if (bgRand & 1) {
            	bgRedraw(bg2);
            } else {
            	bgRedraw(background2);
            }

            
            //sprintf(scoreStr, "x:%dy:%d,1x:%d,1y%d,%d", col, row, pipes[0].col, pipes[0].row, cSwitch );
            //drawString(100, 5, numToChar(score, scoreStr), BLACK);
            //sprintf(scoreStr, "%d", score);
            //drawString(150, 5, scoreStr, YELLOW);

            if (state == GAMEOVER) {
                drawImage3(0,0,240, 160, go);
                //drawString(160/2 + 50, 240/2, numToChar(score, scoreStr), BLUE);
                char * test = "SCORE: ";
                //int x = 0;
                //while (scoreStr[x] != '\0') {
                //	x++;
                //}
                for (int x = 5; x >= 0; x--) { //5 cause a score of 10^4 is impossible
                	scoreStr[x+7] = scoreStr[x]; //7 cause length of score: 
                }
                for (int i = 0; i < 7; i++) {
                	*(scoreStr + (i)) = test[i];
                }
                
                drawString(130, 240/2 - (6 * 10) /2, scoreStr, BLUE);
                hideSprites();
                renderSprites();
            }
            break;
        case GAMEOVER:

            keyInput(START);
            break;
        }
    }


}
void render()
{
    /*DMA[3].src = screenBuffer;
    DMA[3].dst = videoBuffer;
    DMA[3].cnt = 38400 | DMA_SOURCE_INCREMENT | DMA_ON;
    */
}
void hideSprites() {
    for (int i = 0; i < 128; i++) {
        OamEntry *temp = &sprites[i];
        temp->attr0 = temp->attr0 | (2<<8);
    }
}
void renderSprites() {
    DMA[3].src = sprites;
    DMA[3].dst = OAMMEM;
    DMA[3].cnt = 128 | DMA_ON;
}
void initGraphics() {
    REG_DISPCTL = MODE3 | BG2_ENABLE | OBJ_ENABLE | MODE1D;
    initSprites();



}
void initSprites() {
    DMA[3].src = bandp_palette; //SPRITESHEET = BANDP.h
    DMA[3].dst = SPRITEPAL;
    DMA[3].cnt = BANDP_PALETTE_SIZE | DMA_ON;

    DMA[3].src = bandp;
    DMA[3].dst = &CHARBLOCKBASE[5];
    DMA[3].cnt = BANDP_SIZE | DMA_ON;
}
void keyInput(GBAState st) {
	currKey = ~BUTTONS & 0x03FF;
	if(!(currKey & BUTTON_SELECT) && !(currKey & BUTTON_A) && !(currKey & BUTTON_RIGHT))
    {
        cooldown = 0;
    }
    else if(currKey & BUTTON_SELECT && !(prevKey & BUTTON_SELECT)) { //KEY_DOWN_NOW(BUTTON_SELECT)
        state = st;
        if (st == START) {
            resetVars();
        }
        cooldown = 1;
    } else if (currKey & BUTTON_A && !(prevKey & BUTTON_A)) {
    	if (currKey & BUTTON_RIGHT) {
    		cVel = 10;
    	}
    	rVel = -JUMPVEL;
    	cooldown = 1;
    	if (st == PLAY) {
    		state = st;
    	}
    } else if (currKey & BUTTON_RIGHT && !(prevKey & BUTTON_RIGHT)) {
    	cVel = 10;
    	cooldown = 1;
    }
    prevKey = currKey;
}
void setupOBJS() {
    for(int i=0; i<NUMPIPES; i++)
    {
    	cur = &pipes[i];
    	
        cur->row = 110;
        cur->col = 240 + (i * 50) ;
        cur->rd = 0; //maybe some pipes move up and down as well
        cur->cd = -2;
        cur->width = PIPEWIDTH;
        cur->height = PIPEHEIGHT;
        cur->passed = 0;
        pipe = sprites+1+i;
        pipe->attr0 = cur->row | BANDP_PALETTE_TYPE | PIPE2_SPRITE_SHAPE | ATTR0_SQUARE;
        pipe->attr1 = cur->col | (PIPE2_SPRITE_SIZE) | ATTR1_SIZE8;
        pipe->attr2 = PIPE2_PALETTE | PIPE2_ID;
        cur->sp = pipe;
    }

    //BIRD SPRITE SETUP
    bird = sprites + 0;
    bird->attr0 = row | BANDP_PALETTE_TYPE | BIRD2_SPRITE_SHAPE | (0<<8);
    bird->attr1 = col | (BIRD2_SPRITE_SIZE) | ATTR1_SIZE8;
    bird->attr2 = BIRD2_PALETTE | BIRD2_ID;
}
void resetVars() {
    setupOBJS();

    row = 80;
    col = 35;
    pLax = 0;
    score = 0;
    //srand(seed % 7);
    bgRand = rand() % 10;

}
void bgRedraw(unsigned short * bg) {
    if (pLax < -239) {
        pLax = 0;

    }
    drawFragmentMoved(abs(pLax),0,0,0,240+pLax, 160, bg); //DRAW LEFT
     //have to use these weird numbers because of mode 3 : /
    //drawString(150, 0, numToChar(score, scoreStr), BLACK); //HAVE TO DRAW SCORE HERE
    
   

    if (pLax != 0 ) {
        drawFragmentMoved(0,0, 240+pLax -1, 0, abs(pLax), 160, bg); //DRAW RIGHT

    }

		


    pLax--;
    drawString(150, 240/2 - 10, numToChar(score, scoreStr), BLACK);

}
void moveBird() {
    
    
    if (rVel > 0) {
    	if (pLax % 2 == 0) {
			rVel = rVel + g;
    }
    	
    } else {
    	rVel = rVel + g;
    }
    row = row + rVel;

    if (cVel < 0) {
    	if (pLax % 7 == 0) {
    		cVel = cVel - g;
    	}
    	
    } else {
    	cVel = cVel - g;
    }
    
    col = col + cVel;
    if (col < 35) {
    	col = 35;
    	cVel = 0;
    } else if (col > 239) {
    	col = 239;
    }


    if(row > 143-BIRDHEIGHT+1)
    {
        row = 143-BIRDHEIGHT+1;
        rVel = (-1 * rVel) / 2;
    }
    if ( row < -30) {
    	row = -30;
    } 
    bird->attr0 = ((row < 0 && (256 + row) >= 160) ? 256 + row : row) | BANDP_PALETTE_TYPE | BIRD2_SPRITE_SHAPE | (0<<8);
    bird->attr1 = col | (BIRD2_SPRITE_SIZE) | ATTR1_SIZE8 ;

}
void movePipes() {
    for(int i=0; i<NUMPIPES; i++)
    {
        cur = &pipes[i];

        cur->row = cur->row + cur->rd;
        cur->col = cur->col + cur->cd;


        if (cur->col < -64) {
            cur->col = 240 + (i*80) + rand() % 50;
            //cur->col = 400; //if you go too high the sprite will wrap
            
            int type = rand() % 2;
            if (type) {
            	cur->row = 100+rand() % 40;
            	cur->sp->attr2 = PIPE2_PALETTE | PIPE2_ID;
            	cur->height = 144-cur->row-1;
            	/*cur->row = 0; //-rand() % 50
            	cur->sp->attr2 = PIPE3_PALETTE | PIPE3_ID;
            	cur->height = 64;
            	*/
            } else {
            	cur->row = 0 - rand() % 50;
            	cur->sp->attr2 = PIPE3_PALETTE | PIPE3_ID;
            	cur->height = PIPEHEIGHT; //cause the sprite is drawn from the top
            }
            
            
            cur->passed = 0;
        }
        if (cur-> col < col && !cur->passed) {
            score++;
            cur->passed = 1;
        }
        
        if (col + BIRDWIDTH >= cur->col && col <= (cur->col + cur->width)) { //&& col < (cur->col + cur->width)
        	

            if (row+BIRDHEIGHT >= cur->row && row <= cur->row+cur->height)
            {
                state = GAMEOVER;
               

            } 

        	
        }




        cur->sp->attr0 = cur->row < 0 ? 256+cur->row : cur->row | BANDP_PALETTE_TYPE | PIPE2_SPRITE_SHAPE | ATTR0_SQUARE;
        cur->sp->attr1 = ((cur->col < 0 && (512+cur->col) > 400) ? 512+cur->col: cur->col) | (PIPE2_SPRITE_SIZE) | ATTR1_SIZE8;

    }
}

