#include "myLib.h"

unsigned short *videoBuffer = (unsigned short *)0x6000000;

void setPixel(int row, int col, unsigned short color)
{
	videoBuffer[OFFSET(row, col, 240)] = color;
}

void drawRect(int row, int col, int height, int width, unsigned short color)
{
	for(int r = 0; r<height; r++)
	{
		for(int c=0; c<width; c++)
		{
			setPixel(r+row, c+col, color);
		}
	}
}

void delay(int n)
{
	int volatile x = 0;
	for(int i =0; i<n*8000; i++)
	{
		x = x + 1;
	}
}

void waitForVblank()
{
	while(SCANLINECOUNTER >= 160);
	while(SCANLINECOUNTER<160);
}
