#include "myLib.h"
#include <stdlib.h>
unsigned short *videoBuffer = (unsigned short *)0x6000000;

void setPixel(int row, int col, unsigned short color)
{
	videoBuffer[OFFSET(row, col, 240)] = color;
}
void drawBird(int x, int y, int *starts, int *widths, const unsigned short *image) {



/*for (int i = 0; i < height; i++){
	for (int j = 0; j < width; j++) {
		if (image[(width * i) +j] != MAGENTA) {
		videoBuffer[((i+y) * 240) + j + x] =  image[(width * i) + j];
		}
		
	}	
} 
*/


	for(int i=0; i<BIRDHEIGHT; i++)
	{
		int start = starts[i];
		int widthMOD = widths[i];
		DMA[3].src = image + 32*i + start;
		DMA[3].dst = videoBuffer + OFFSET(y+i, x+start, 240);
		DMA[3].cnt = widthMOD | DMA_SOURCE_INCREMENT | DMA_ON; //INCREMENT
	}

}
void drawRect(int row, int col, int height, int width, unsigned short color)
{
int widthMOD = width;
if (width + col >240) {
widthMOD = abs(col-240);
}

if (col < 0) {
widthMOD = width-abs(0-col);
col = 0;
}
	for(int r=0; r<height; r++)
	{
/*
		for(int c=0; c<width; c++)
		{
			setPixel(row+r, col+c, color);
		}
*/
		DMA[3].src = &color;
		DMA[3].dst = videoBuffer + OFFSET(row+r, col, 240);
		DMA[3].cnt = widthMOD | DMA_SOURCE_FIXED | DMA_ON;
	}
}

void drawRectImage(int x, int y, int width, int height, const unsigned short *image) {
int widthMOD = width;
if (width + x >240) {
widthMOD = abs(x-240);
}

if (x < 0) {
widthMOD = width-abs(x-0);
x = 0;
}
for(int i=0; i<height; i++)
	{
		DMA[3].src = image + width*i;
		DMA[3].dst = videoBuffer + OFFSET(y+i, x, 240);
		DMA[3].cnt = widthMOD | DMA_SOURCE_INCREMENT | DMA_ON; //INCREMENT
	}


}


void drawImage3(int x, int y, int width, int height, const unsigned short *image) {
for(int i=0; i<height; i++)
	{
		DMA[3].src = image + width*i;
		DMA[3].dst = videoBuffer + OFFSET(y+i, x, 240);
		DMA[3].cnt = width | DMA_SOURCE_INCREMENT | DMA_ON; //INCREMENT
	}


}


void drawFragment(int x, int y, int width, int height, const unsigned short *image) {
for(int i=0; i<height; i++)
	{
		DMA[3].src = image + (240*(i+y))+x;
		DMA[3].dst = videoBuffer + (y+i) * 240 + x;
		DMA[3].cnt = width | DMA_SOURCE_INCREMENT | DMA_ON; //INCREMENT
	}


}


void birdSetup(int *starts, int *widths, const unsigned short *image) {
for (int i = 0; i < BIRDHEIGHT; i++) {
	int start = -1;
	int width = BIRDWIDTH;
	int j = 0;
	while (j < BIRDWIDTH && image[(BIRDWIDTH * i) +j] == MAGENTA) {
		j++;
	}
	start = BIRDWIDTH == j ? 0: j;
	starts[i] = start;

	while (j < BIRDWIDTH && image[(BIRDWIDTH * i) +j] != MAGENTA) {
		j++;
	}
	width = j - start;
	widths[i] = width; 
}
}


void delay(int n)
{
	volatile int x = 0;
	for(int i=0; i<6000*n; i++)
	{
		x = x + 1;
	}
}

void waitForVblank()
{
	while(SCANLINECOUNTER >= 160);
	while(SCANLINECOUNTER<160);
}
