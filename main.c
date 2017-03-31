#include "myLib.h"
#include "text.h"
#include <stdlib.h>
#include <stdio.h>
#include "bg.h"
//#include "bird.h"
//#include "pipe2.h"
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





//////////////////GAME VARS/////////////////////////
volatile int score = 0;
volatile int cooldown = 0; //COOLDOWN USED FOR BUTTONS AND REDRAW
volatile int pLax = 0; //BACKGROUND DRAWN WITH PARALLAX
volatile int suspend = 0;
int row = 80; //BIRD Y position
int col = 35; //BIRD X position

int rVel, cVel = 1; //BIRD X AND Y VELOCITY
const int g = 1; //VELOCITY ADDEND (ACCELERATION)
char scoreStr[100]; //BUFFER HOLDS STRING VERSION OF SCORE


PIPE pipes[NUMPIPES]; //ARRAY OF PIPES PRESENT AT ONCE
PIPE *cur; //POINTER TO A PIPE OBJ

OamEntry *bird; //BIRD SPRITE OBJ
OamEntry *pipe;

GBAState state = START;
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
    initGraphics();
    setupOBJS();
    ///////////
    while(1)
    {


        switch(state)
        {
        case START:
            drawImage3(0,0,240,160, title);
            drawString(160/2, 240/2 - 60/2, "PRESS SELECT", YELLOW);
            state = START_NODRAW;
            hideSprites();
            renderSprites();
            break;
        case START_NODRAW:
            keyInput(PLAY);
            break;
        case PLAY:

            keyInput(START);
            moveBird();
            movePipes();
            waitForVblank();
            renderSprites();
            bgRedraw();

            drawString(150, 5, numToChar(score, scoreStr), YELLOW);


            if (state == GAMEOVER) {
                drawImage3(0,0,240, 160, go);
                drawString(160/2 + 50, 240/2, numToChar(score, scoreStr), BLUE);
                hideSprites();
                renderSprites();
            }
//25% or more body fat males
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
    if(KEY_DOWN_NOW(BUTTON_SELECT) && !cooldown) {
        state = st;
        if (st == PLAY) {
            resetVars();
        }
        cooldown = 1;
    }
    if(KEY_DOWN_NOW(BUTTON_UP) && !cooldown)
    {
        rVel = -JUMPVEL;
        cooldown = 1;
    }

    if(!KEY_DOWN_NOW(BUTTON_UP) && !KEY_DOWN_NOW(BUTTON_SELECT))
    {
        cooldown = 0;
    }
}
void setupOBJS() {
    for(int i=0; i<NUMPIPES; i++)
    {
        pipes[i].row = 110;
        pipes[i].col = 240 + (i * 50) ;
        pipes[i].rd = 0; //maybe some pipes move up and down as well
        pipes[i].cd = -2;
        pipes[i].width = 30;
        pipes[i].height = 50;
        pipe = sprites+1+i;
        pipe->attr0 = pipes[i].row | BANDP_PALETTE_TYPE | PIPE2_SPRITE_SHAPE | ATTR0_SQUARE;
        pipe->attr1 = pipes[i].col | (PIPE2_SPRITE_SIZE) | ATTR1_SIZE8;
        pipe->attr2 = PIPE2_PALETTE | PIPE2_ID;
        pipes[i].sp = pipe;
    }

    //BIRD SPRITE SETUP
    bird = sprites + 0;
    bird->attr0 = row | BANDP_PALETTE_TYPE | BIRD2_SPRITE_SHAPE | (0<<8);
    bird->attr1 = col | (BIRD2_SPRITE_SIZE) | ATTR1_SIZE8;
    bird->attr2 = BIRD2_PALETTE | BIRD2_ID;
}
void resetVars() {
    for(int i=0; i<3; i++)
    {
        pipes[i].row = 110;
        pipes[i].col = 240 + (i * 50) ;
        pipes[i].rd = 0; //maybe some pipes move up and down as well
        pipes[i].cd = -2;
    }

    row = 80;
    col = 35;
    pLax = 0;
    score = 0;
}
void bgRedraw() {
    if (pLax < -239) {
        pLax = 0;

    }
    drawFragmentMoved(abs(pLax),0,0,0,240+pLax, 160, background2);


    if (pLax != 0 ) {
        drawFragmentMoved(0,0, 240+pLax -1, 0, abs(pLax), 160, background2);
    }



    pLax--;

}
void moveBird() {
    rVel = rVel + g;
    row = row + rVel;


    if(row > 145-BIRDHEIGHT+1)
    {
        row = 145-BIRDHEIGHT+1;
        rVel = (-1 * rVel) / 2;
    }
    bird->attr0 = ((row < 0 && (255 + row) >= 160) ? 255 + row : row) | BANDP_PALETTE_TYPE | BIRD2_SPRITE_SHAPE | (0<<8);
    bird->attr1 = col | (BIRD2_SPRITE_SIZE) | ATTR1_SIZE8 ;

}
void movePipes() {
    for(int i=0; i<NUMPIPES; i++)
    {
        cur = &pipes[i];

        cur->row = cur->row + cur->rd;
        cur->col += cur->cd;


        if (cur->col < -64) {
            //cur->col = 240 + (i*80) + rand() % 50;
            cur->col = 400; //if you go too high the sprite will wrap
            cur->row = 100+rand() % 60;
            cur->height = 144-cur->row-1;
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




        cur->sp->attr0 = cur->row | BANDP_PALETTE_TYPE | PIPE2_SPRITE_SHAPE | ATTR0_SQUARE;
        cur->sp->attr1 = ((cur->col < 0 && (511+cur->col) > 400) ? 511+cur->col: cur->col) | (PIPE2_SPRITE_SIZE) | ATTR1_SIZE8;

    }
}

