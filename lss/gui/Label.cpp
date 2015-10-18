/*
 * label.cpp
 *
 *  Created on: 2010. 8. 31.
 *      Author: Yoon-Ki Hong
 */

#include <gui/Label.h>
#include <stdarg.h>
#include <stdio.h>


void Label::set(char* fmt,...)
{
	va_list ap;
	char string[100];
	unsigned short i;

	va_start(ap,fmt);
	vsprintf(string,fmt,ap);
	va_end(ap);

	for(i=0;fmt[i] != 0;i++)
		str[i] = fmt[i];

	setSize(i*8, LABEL_HEIGHT);
	draw();
}

void Label::setColor(Dot color)
{
	brush.setColor(color);
	draw();
}

void Label::setBgColor(Dot color)
{
	brush.setBgColor(color);
	draw();
}

void Label::draw(void)
{
	brush.drawClear();
//	drawString(pos, str);
	doUpdate();
}

