#include <stdio.h>
#include "text.h"
#include "myLib.h"


void drawChar(int row, int col, char ch, unsigned short color)
{
	for(int r = 0; r<8; r++)
	{
		for(int c=0; c<6; c++)
		{
			if(fontdata_6x8[OFFSET(r, c, 6) + ch*48])
			{
				setPixel(row+r, col+c, color);
			}
		}



	}

}

void drawString(int row, int col, char *str, unsigned short color)
{
	while(*str)
	{
		drawChar(row, col, *str++, color);
		col += 6;

	}
	
}
int power(int n, int l) {
int num = 1;
for (int i = 0; i < l; i++) {
num *=n;
}
return num;
}

char* numToChar(int num, char* buffer) {
int length = 0;
int temp = num;
while (temp !=0) {
temp = temp/10;
length++;
if (length == 3) {
//num = 300;
}
}
//always create a pointer to an array buffer so as to avoid read only memory
//void pointer doesn't know what type the data it points to is
for (int i = 0; i < length; i++) {
buffer[i] = (char) (((num/(int)power(10, length - i-1))  % 10) + 48);
}
return buffer;
}



