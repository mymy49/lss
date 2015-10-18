/*
 * figure.cpp
 *
 *  Created on: 2010. 8. 27.
 *      Author: Administrator
 */

#include <gui/Brush.h>
#include <math.h>
/*
void Brush::drawLine(Pos sp, Pos ep)
{
	frame temp, end;
	if(memFlag)
	{
		if(sp.x > ep.x)
		{
			temp = sp.x;
			sp.x = ep.x;
			ep.x = temp;
		}
		if(sp.y > ep.y)
		{
			temp = sp.y;
			sp.y = ep.y;
			ep.y = temp;
		}

		if(ep.x < width && ep.y < height)
		{
			if(!(ep.x-sp.x))
			{
				end = ep.y;
				for(temp=sp.y;temp<=end;temp++)
					frameBuffer[temp][sp.x] = color;
			}
			else if(!(ep.y-sp.y))
			{
				end = ep.x;
				for(temp=sp.x;temp<=end;temp++)
					frameBuffer[sp.y][temp] = color;
			}
		}
	}
}
*/
/*
void Brush::drawCiurcle(Pos pos, frame r)
{
	frame i, j, k;
	if(memFlag)
	{
		if(pos.x + r < height && pos.y < height)
		{
	//		if(fiil)
			if(0)
			{
				for(i=0;i*i*2<=r*r;i++)
				{
					j = (int)(pow(r*r-i*i,0.5)+0.5);

					for(k=0;k<=j;k++)
						frameBuffer[pos.y+k][pos.x+i] = bshColor;
					for(k=0;k<=j;k++)
						frameBuffer[pos.y-k][pos.x+i] = bshColor;
					for(k=0;k<=j;k++)
						frameBuffer[pos.y+k][pos.x-i] = bshColor;
					for(k=0;k<=j;k++)
						frameBuffer[pos.y-k][pos.x-i] = bshColor;

					for(k=0;k<=j;k++)
						frameBuffer[pos.y+i][pos.x+k] = bshColor;
					for(k=0;k<=j;k++)
						frameBuffer[pos.y-i][pos.x+k] = bshColor;
					for(k=0;k<=j;k++)
						frameBuffer[pos.y+i][pos.x-k] = bshColor;
					for(k=0;k<=j;k++)
						frameBuffer[pos.y-i][pos.x-k] = bshColor;
				}
			}
			else
			{
				for(i=0;i*i*2<=r*r;i++)
				{
					j = (int)(pow(r*r-i*i,0.5)+0.5);

					frameBuffer[pos.y+j][pos.x+i] = bshColor;
					frameBuffer[pos.y-j][pos.x+i] = bshColor;
					frameBuffer[pos.y+j][pos.x-i] = bshColor;
					frameBuffer[pos.y-j][pos.x-i] = bshColor;

					frameBuffer[pos.y+i][pos.x+j] = bshColor;
					frameBuffer[pos.y-i][pos.x+j] = bshColor;
					frameBuffer[pos.y+i][pos.x-j] = bshColor;
					frameBuffer[pos.y-i][pos.x-j] = bshColor;
				}
			}
		}
	}
}
*/
/*
void Brush::drawRectangle(Pos sp, Pos ep)
{
	Pos p1, p2;

	p1.x = sp.x;
	p1.y = sp.y;
	p2.x = sp.x;
	p2.y = ep.y;
	drawLine(p1, p2);

	p1.y = ep.y;
	p2.x = ep.x;
	drawLine(p1, p2);

	p1.x = ep.x;
	p2.y = sp.y;
	drawLine(p1, p2);

	p1.y = sp.y;
	p2.x = sp.x;
	drawLine(p1, p2);
}
*/