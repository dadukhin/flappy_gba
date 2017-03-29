#include <stdlib.h>
#include "myLib.h"
#include "text.h"

#define NUMOBJS 7
#define ROWMAX 149

/*
 * MOVOBJ - Moving Object Structure
 */
typedef struct 
{
	int row;
	int col;
	int rd;
	int cd;
	int size;
	unsigned short color;
} MOVOBJ;

int main()
{
	MOVOBJ objs[NUMOBJS];
	MOVOBJ oldobjs[NUMOBJS];
	MOVOBJ *cur;
	REG_DISPCTL = MODE3 | BG2_ENABLE;
	//* ( OFFSET(80, 120, 240) +  videoBuffer )= WHITE;
	//videoBuffer[OFFSET(80, 120, 240)] = WHITE;
	int dels[] = {-3, -2, -1, 1, 2, 3};
	int numdels = sizeof(dels)/sizeof(dels[0]);
	int size = 5;
	int oldsize = size;
	unsigned short colors[] = {RED, GREEN, BLUE, MAGENTA, CYAN, YELLOW, WHITE};
	int numcolors = sizeof(colors)/sizeof(colors[0]);
	for(int i=0; i<NUMOBJS; i++)
	{
		objs[i].row = 70 + rand()%20;
		objs[i].col = 110 + rand()%20;
		objs[i].rd = dels[rand()%numdels];
		objs[i].cd = dels[rand()%numdels];
		objs[i].color = colors[i%numcolors];
		oldobjs[i] = objs[i];
	}
	//unsigned short color = GREEN;



	drawString(150, 5, "Spring Break!", YELLOW);

	while(1) // Game Loop
	{
		if(KEY_DOWN_NOW(BUTTON_UP))
		{
			size++;
			if(size>150)
			{
				size = 150;
			}
		}
		if(KEY_DOWN_NOW(BUTTON_DOWN))
		{
			size--;
			if(size<3)
			{
				size = 3;
			}
		}
		for(int i=0; i<NUMOBJS; i++)
		{
			cur = &objs[i];
			cur = objs + i;

			cur->row = cur->row + cur->rd;
			cur->col += cur->cd;
			if(cur->row < 0)
			{
				cur->row = 0;
				cur->rd = -cur->rd;
			}
			if(cur->row > ROWMAX-size+1)
			{
				cur->row = ROWMAX-size+1;
				cur->rd = -cur->rd;
			}
			if(cur->col < 0)
			{
				cur->col = 0;
				cur->cd = -cur->cd;
			}
			if(cur->col > 239-size+1)
			{
				cur->col = 239-size+1;
				cur->cd = -cur->cd;
			}
		}
		waitForVblank();
		for(int i=0; i<NUMOBJS; i++)
		{
			
			drawRect(oldobjs[i].row, oldobjs[i].col, oldsize, oldsize, BLACK);
		}
		for(int i=0; i<NUMOBJS; i++)
		{
			cur = objs + i;
			drawRect(cur->row, cur->col, size, size, cur->color);
			oldobjs[i] = objs[i];
			
		}		
		oldsize = size;
	} // Game Loop
}

