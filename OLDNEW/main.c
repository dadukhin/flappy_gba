#include "myLib.h"
#include "text.h"
#include <stdlib.h>
#include <stdio.h>
#include "bg.h"
#include "bird3.h"
#include "pipe2.h"
#include "title.h"
#include "go.h"

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
} PIPE;

enum GBAState {
    START,
    START_NODRAW,
    PLAY,
    GAMEOVER,
};
int main()
{
    enum GBAState state = START; //


    
    PIPE objs[3]; //for now 3 pipes on screen at once
    PIPE oldobjs[3];
    PIPE *cur;

    volatile int score = 0;
    REG_DISPCTL = MODE3 | BG2_ENABLE;
    int row = 80;
    int col = 35;
    int oldrow = row;
    int oldcol = col;
    int rdel = 1;
    int cdel = 1;
    volatile int cooldown = 0;
    int g = 1;
    int size = 5;
    int oldsize = size;
    char buffer[10];
    int bStart[BIRDHEIGHT];
    int bWidth[BIRDHEIGHT];
    birdSetup(bStart, bWidth, bINEF);
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
        objs[i].width = 15;
        objs[i].height = 50;
        oldobjs[i] = objs[i];
    }


    
    drawImage3(0,0,240, 160, background2);
    while(1)
    {


        switch(state)
        {
        case START:
        	drawImage3(0,0,240,160, title);
        	drawString(160/2, 240/2 - 60/2, "PRESS SELECT", YELLOW);
    		state = START_NODRAW;
            break;
        case START_NODRAW:
        	if(!KEY_DOWN_NOW(BUTTON_SELECT)) {
        		cooldown = 0;
        	}
        	if(KEY_DOWN_NOW(BUTTON_SELECT) && !cooldown) {
        		cooldown = 1;
        		drawImage3(0,0,240, 160, background2);
        		//RESETING ALL GAME VARS
				for(int i=0; i<3; i++)
    			{		
        		objs[i].row = 110;
        		objs[i].col = 240 + (i * 50) ;
        		objs[i].rd = 0; //maybe some pipes move up and down as well
        		objs[i].cd = -4;
        		objs[i].color = RED;
        		objs[i].width = 15;
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
                //go to title screen
                //add title screen
                state = START;
                cooldown = 1;
            }
            if(KEY_DOWN_NOW(BUTTON_UP) && !cooldown)
            {
                rdel = -10;
                cooldown = 1;
            }

            if(!KEY_DOWN_NOW(BUTTON_UP) && !KEY_DOWN_NOW(BUTTON_SELECT))
            {
                cooldown = 0;
            }
            if(KEY_DOWN_NOW(BUTTON_DOWN))
            {
                size--;
                if(size<3)
                    size = 3;
            }
            //row = row + rdel;
            //col += cdel;
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
            if(row > 143-BIRDHEIGHT+1)
            {
                row = 143-BIRDHEIGHT+1;
                rdel = (-1 * rdel) / 2;
            }
            for(int i=0; i<3; i++)
            {
                cur = &objs[i];
                cur = objs + i;

                cur->row = cur->row + cur->rd;
                cur->col += cur->cd;


                if (cur->col < -15) {
                    //cur->col = 240 + (i*80) + rand() % 50;
                    cur->col = 500;
                    cur->row = 80+rand() % 50;
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
            waitForVblank();
            delay++;
            if (delay >= 30) {
                if (oldparallax <= -50) {
                    oldparallax = 0;
                }
                drawImage3(oldparallax--,0,240, 100, background2);
                delay = 0;
            }
            //drawImage3(0,0,240, 100, background2);
            //delay(1);
            drawFragment(oldcol, oldrow, BIRDWIDTH, BIRDHEIGHT, background2, oldparallax + 1);
            oldsize++;
            oldcol = oldcol +0;
            oldrow= oldrow +0;
            drawBird(col,row, bStart, bWidth, bINEF);
            oldrow = row;
            oldcol = col;
            oldsize = size;

            for(int i=0; i<3; i++)
            {
                cur = oldobjs + i;

                if (cur-> col < 240 && cur->col >= -15)
                {
                    drawFragment(cur->col, cur->row, 15, cur->height, background2, oldparallax + 1);
                }
            }
            for(int i=0; i<3; i++)
            {
                cur = objs + i;
                if (cur->col < 240 && cur->col >= -15)
                {
                    drawRectImage(cur->col,cur->row, 15, cur->height, pipe2);
                }
                oldobjs[i] = objs[i];
            }
            //sprintf(buffer, "Score: %d", score);
            drawFragment(5, 150, 30, 8, background2, 0);
            drawString(150, 5, numToChar(score, buffer), YELLOW);

            if (state == GAMEOVER) {
            	drawImage3(0,0,240, 160, go);
            	drawString(160/2 + 50, 240/2, numToChar(score, buffer), BLUE);

            }

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

