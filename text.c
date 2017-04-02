//DAVID SOLODUKHIN
#include <stdio.h>
#include "text.h"
#include "myLib.h"
#include <stdlib.h>


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
return abs(num);
}

char* numToChar(int num, char* buffer) {

for (int i = 0; i < 10; i++) {
	buffer[i] = '\0';
}

int length = 0;
int temp = num;
while (temp !=0) {
temp = temp/10;
length++;
}
//always create a pointer to an array buffer so as to avoid read only memory
//void pointer doesn't know what type the data it points to is
int negative = 0;
if (num <  0) {
	buffer[0] = '-';
	negative = 1;
}
num = abs(num);
for (int i = 0+negative; i < length+negative; i++) {
buffer[i] = (char) (((num/(int)power(10, length - i-(negative ? 0: 1)))  % 10) + 48);
}
return buffer;
}



