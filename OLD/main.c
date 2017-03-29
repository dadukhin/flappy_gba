#include "myLib.h"
#include "text.h"
#include <stdlib.h>

int main()
{
	REG_DISPCTL = MODE3 | BG2_ENABLE;
	int row = 80;
	int col = 120;
	int oldrow = row;
	int oldcol = col;
	int rdel = 1;
	int cdel = 1;
	int size = 5;
	int oldsize = size;
	int bgcolor = BLUE;
/*
	for(int i=0; i<38400; i++)
	{
		videoBuffer[i] = bgcolor;
	}
*/
	DMA[3].src = &bgcolor;
	DMA[3].dst = videoBuffer;
	DMA[3].cnt = 38400 | DMA_SOURCE_FIXED | DMA_DESTINATION_INCREMENT | DMA_ON;

	while(1)
	{
		if(KEY_DOWN_NOW(BUTTON_UP))
		{
			size++;
			if(size>150)
				size = 150;
		}
		if(KEY_DOWN_NOW(BUTTON_DOWN))
		{
			size--;
			if(size<3)
				size = 3;
		}
		row = row + rdel;
		col += cdel;
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
			row = 0;
			rdel = -rdel;
		}
		if(row > 159-size+1)
		{
			row = 159-size+1;
			rdel = -rdel;
		}
		
		waitForVblank();
		drawRect(oldrow, oldcol, oldsize, oldsize, bgcolor);
		drawRect(row, col, size, size, RED);
		oldrow = row;
		oldcol = col;
		oldsize = size;
	}
}

