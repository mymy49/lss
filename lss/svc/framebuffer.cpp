#include <stm32f429.h>
#include <gui/Canvas.h>



void drawLcd(unsigned short *fb, Canvas &obj)
{
/*
	unsigned short x, y;
	unsigned short **src = obj.getBuffer();
	dot *buf;
	
	for(x=0;x<320;x++)
	{
		for(y=0;y<240;y++)
		{
			*fb++ = src[y][x];
		}
	}
*/
/*
	for(y=0;y<240;y++)
	{
		buf = src[y];
		//
		for(x=0;x+31<320;x+=32)
		{
			*fb++ = *buf++;
            *fb++ = *buf++;
            *fb++ = *buf++;
            *fb++ = *buf++;
            *fb++ = *buf++;
            *fb++ = *buf++;
            *fb++ = *buf++;
            *fb++ = *buf++;
            *fb++ = *buf++;
            *fb++ = *buf++;
			// 10
			*fb++ = *buf++;
            *fb++ = *buf++;
            *fb++ = *buf++;
            *fb++ = *buf++;
            *fb++ = *buf++;
            *fb++ = *buf++;
            *fb++ = *buf++;
            *fb++ = *buf++;
            *fb++ = *buf++;
            *fb++ = *buf++;
			// 20
			*fb++ = *buf++;
            *fb++ = *buf++;
            *fb++ = *buf++;
            *fb++ = *buf++;
            *fb++ = *buf++;
            *fb++ = *buf++;
            *fb++ = *buf++;
            *fb++ = *buf++;
            *fb++ = *buf++;
            *fb++ = *buf++;
			// 30
			*fb++ = *buf++;
            *fb++ = *buf++;
		}

		for(;x+7<320;x+=8)
		{
			*fb++ = *buf++;
            *fb++ = *buf++;
            *fb++ = *buf++;
            *fb++ = *buf++;
            *fb++ = *buf++;
            *fb++ = *buf++;
            *fb++ = *buf++;
            *fb++ = *buf++;
		}
		for(;x<320;x++)
			*fb++ = *buf++;

	}
*/
}
