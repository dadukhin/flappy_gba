#include "myLib.h"
#include "text.h"
#include <stdlib.h>
#include <stdio.h>
#include "bg.h"
#include "bird.h"
#include "pipe2.h"
#include "title.h"
#include "go.h"
#include "bandp.h"



typedef struct {
    u16 attr0;
    u16 attr1;
    u16 attr2;
    u16 fill;
} OamEntry;

typedef struct
{
    int row;
    int col;
    int rd;
    int cd;
    int width;
    int height;
    int passed;
    unsigned short color;
    OamEntry *sp;
} PIPE;

OamEntry sprites[128];



enum GBAState {
    START,
    START_NODRAW,
    PLAY,
    GAMEOVER,
};
unsigned short *screenBuffer;
int main()
{
	screenBuffer = (unsigned short *)malloc(sizeof(unsigned short)*38400);
	if (NULL == screenBuffer) {
		screenBuffer = (unsigned short *)0x6000000;
	} 

    enum GBAState state = START; //

   
    
    PIPE objs[3]; //for now 3 pipes on screen at once
    PIPE oldobjs[3];
    PIPE *cur;

    volatile int score = 0;
    REG_DISPCTL = MODE3 | BG2_ENABLE | OBJ_ENABLE | MODE1D;
    int row = 80;
    int col = 35;
    int oldrow = row;
    int oldcol = col;
    int rdel = 1;
    int cdel = 1;
    volatile int cooldown = 0;
    int g = 2;
    int size = 5;
    char buffer[10];
    int bStart[BIRD2_HEIGHT];
    int bWidth[BIRD2_HEIGHT];
    birdSetup(bStart, bWidth, bird2);
    volatile int delay = 0;
    volatile int oldparallax = 0;
    //int gameOver = 0;

    for(int i=0; i<3; i++)
    {
        objs[i].row = 110;
        objs[i].col = 240 + (i * 50) ;
        objs[i].rd = 0; //maybe some pipes move up and down as well
        objs[i].cd = -4;
        objs[i].color = RED;
        objs[i].width = 25;
        objs[i].height = 50;
        oldobjs[i] = objs[i];
    OamEntry* pipe = sprites+1+i;
    pipe->attr0 = 80 | BANDP_PALETTE_TYPE | PIPE2_SPRITE_SHAPE | ATTR0_SQUARE;
	pipe->attr1 = 500 | (PIPE2_SPRITE_SIZE) | ATTR1_SIZE8;
	pipe->attr2 = PIPE2_PALETTE | PIPE2_ID;
	objs[i].sp = pipe;
    }


    
    //drawImage3(0,0,240, 160, background2);
 	/////////////
    DMA[3].src = bandp_palette;
    DMA[3].dst = SPRITEPAL;
    DMA[3].cnt = BANDP_PALETTE_SIZE | DMA_ON;

	DMA[3].src = bandp;
    DMA[3].dst = &CHARBLOCKBASE[5];
    DMA[3].cnt = BANDP_SIZE | DMA_ON;


	OamEntry* bird = sprites + 0;
    bird->attr0 = row | BANDP_PALETTE_TYPE | BIRD2_SPRITE_SHAPE | (0<<8);
	bird->attr1 = col | (BIRD2_SPRITE_SIZE) | ATTR1_SIZE8;
	bird->attr2 = BIRD2_PALETTE | BIRD2_ID;

	
    
	
	

    ///////////
    while(1)
    {


        switch(state)
        {
        case START:
        	drawImage3(0,0,240,160, title);
        	drawString(160/2, 240/2 - 60/2, "PRESS SELECT", YELLOW);
        	//bird->attr0 = ((row < 0 && (255 + row) >= 160) ? 255 + row : row) | BIRDS_PALETTE_TYPE | BIRD2_SPRITE_SHAPE | (2<<8);
			//bird->attr1 = col | (BIRD2_SPRITE_SIZE) | ATTR1_SIZE8 ;
    		state = START_NODRAW;
    		hideSprites();
    		renderSprites();
            break;
        case START_NODRAW:
        	if(!KEY_DOWN_NOW(BUTTON_SELECT)) {
        		cooldown = 0;
        	}
        	if(KEY_DOWN_NOW(BUTTON_SELECT) && !cooldown) {
        		cooldown = 1;
        		drawImage3(0,0,240, 160, background2);
        		render();
        		//RESETING ALL GAME VARS
				for(int i=0; i<3; i++)
    			{		
        		objs[i].row = 110;
        		objs[i].col = 240 + (i * 50) ;
        		objs[i].rd = 0; //maybe some pipes move up and down as well
        		objs[i].cd = -4;
        		objs[i].color = RED;
        		objs[i].width = 25;
        		objs[i].height = 50;
        		oldobjs[i] = objs[i];
    			}

    			row = 80;
    			col = 35;
    			delay = 0;
    			oldparallax = 0;
    			score = 0;
        		state = PLAY;
        	}
        	break;
        case PLAY:
            if(KEY_DOWN_NOW(BUTTON_SELECT) && !cooldown) {
                state = START;
                cooldown = 1;
            }
            if(KEY_DOWN_NOW(BUTTON_UP) && !cooldown)
            {
                rdel = -JUMPVEL;
                cooldown = 1;
            }

            if(!KEY_DOWN_NOW(BUTTON_UP) && !KEY_DOWN_NOW(BUTTON_SELECT))
            {
                cooldown = 0;
            }
            rdel = rdel +g;
            row = row + rdel;
            // delay(1);
            if(col <0)
            {
                col = 0;
                cdel = -cdel;
            }
            if(col > 239-size+1)
            {
                col = 239-size+1;
                cdel = -cdel;
            }
            if(row < 0)
            {
                //row = 0;
                //rdel = -rdel;
            }
            if(row > 143-BIRD2_HEIGHT+1-10)
            {
                row = 143-BIRD2_HEIGHT+1-10;
                rdel = (-1 * rdel) / 2;
            }
            for(int i=0; i<3; i++)
            {
                cur = &objs[i];
                cur = objs + i;

                cur->row = cur->row + cur->rd;
                cur->col += cur->cd;


                if (cur->col < -64) {
                    //cur->col = 240 + (i*80) + rand() % 50;
                    cur->col = 400; //if you go too high the sprite will wrap
                    cur->row = 100+rand() % 60;
                    cur->height = 143-cur->row-1;
                    cur->passed = 0;
                }
                if (cur-> col < col && !cur->passed) {
                    score++;
                    cur->passed = 1;
                }
                if (col + BIRDWIDTH >= cur->col && col < cur->col + cur->width) {
                    if (row+BIRDHEIGHT >= cur->row && row < cur->row+cur->height)
                    {
                        state = GAMEOVER;

                    }
                }

            }
            ///////////////////////////////////////////////////////////////////////////////////
            
            //delay++;
            waitForVblank();

            

			//DMA[3].src = sprites;
    		//DMA[3].dst = OAMMEM;
    		//DMA[3].cnt = 128 | DMA_ON;
            
                
            
            //UNCOMMENT THIS LINE IF SCREENBUFFER IS REMOVED
            ////drawFragment(oldcol, oldrow, BIRDWIDTH, BIRDHEIGHT, background2, oldparallax + 1);
            oldcol = oldcol +0;
            oldrow= oldrow +0;
            cur = oldobjs + 0;

            //drawBird(col,row, bStart, bWidth, bird2);
            oldrow = row;
            oldcol = col;

            //UNCOMMENT THE FOLLOWING IF SCREENBUFFER IS REMOVED
            /*for(int i=0; i<3; i++)
            {
                cur = oldobjs + i;

                if (cur-> col < 240 && cur->col >= -15)
                {
                    ////drawFragment(cur->col, cur->row, 15, cur->height + 43, background2, oldparallax + 1);
                }
            }
            */

            for(int i=0; i<3; i++)
            {
                cur = objs + i;


                
                	cur->sp->attr0 = cur->row | BANDP_PALETTE_TYPE | PIPE2_SPRITE_SHAPE | ATTR0_SQUARE;
					cur->sp->attr1 = ((cur->col < 0 && (511+cur->col) > 400) ? 511+cur->col: cur->col) | (PIPE2_SPRITE_SIZE) | ATTR1_SIZE8;
                
                if (cur->col < 240 && cur->col >= -PIPE2_WIDTH)
                {
                    //drawRectImage(cur->col,cur->row, PIPE2_WIDTH, cur->height, pipe2);
                }
                oldobjs[i] = objs[i];
            }
            //sprintf(buffer, "Score: %d", score);
            
            //UNCOMMENT THIS LINE IF SCREENBUFFER IS REMOVED
            ////drawFragment(5, 150, 30, 8, background2, 0);
            drawString(150, 5, numToChar(score, buffer), YELLOW);

			bird->attr0 = ((row < 0 && (255 + row) >= 160) ? 255 + row : row) | BANDP_PALETTE_TYPE | BIRD2_SPRITE_SHAPE | (0<<8);
			bird->attr1 = col | (BIRD2_SPRITE_SIZE) | ATTR1_SIZE8 ;
	

            ////waitForVblank();
            
            renderSprites();


            if (oldparallax < -239) {
                    oldparallax = 0;
                    delay--;
                } else {
                	delay++;
                }
                ////drawImage3(oldparallax,0,240+oldparallax, 160+delay, background2);

				drawFragmentMoved(abs(oldparallax),0,0,0,240+oldparallax, 160, background2);


				if (oldparallax != 0 )
				drawFragmentMoved(0,0, 240+oldparallax -1, 0, abs(oldparallax), 160, background2);


				oldparallax--;
            //DMA[3].src = bird;
    		//DMA[3].dst = OAMMEM;
    		//DMA[3].cnt = 3 | DMA_ON;

	


            if (state == GAMEOVER) {
            	drawImage3(0,0,240, 160, go);
            	drawString(160/2 + 50, 240/2, numToChar(score, buffer), BLUE);
            	//bird->attr0 = ((row < 0 && (255 + row) >= 160) ? 255 + row : row) | BIRDS_PALETTE_TYPE | BIRD2_SPRITE_SHAPE | (2<<8);
				//bird->attr1 = col | (BIRD2_SPRITE_SIZE) | ATTR1_SIZE8 ;
				hideSprites();
				renderSprites();
            }
//25% or more body fat males
            break;
        case GAMEOVER:
        	


        	if(!KEY_DOWN_NOW(BUTTON_SELECT)) {
        		cooldown = 0;
        	}
        	if(KEY_DOWN_NOW(BUTTON_SELECT) && !cooldown) {
        		cooldown = 1;
        		state = START;
        	}
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

