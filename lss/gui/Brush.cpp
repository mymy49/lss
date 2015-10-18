/*
 * Brush.cpp
 *
 *  Created on: 2010. 8. 27.
 *      Author: Administrator
 */

#include <gui/Brush.h>
#include <malloc.h>
#include <stm32f429.h>

Brush::Brush(void)
{
	mWidth = 0;
	mHeight = 0;
	mHFb = 0;
	mFb = 0;
	mMemFlag = false;
}

Brush::~Brush(void)
{
	if(mFb)
	{
		
	}
}

void Brush::drawDot(unsigned short x, unsigned short y)
{
	if(mMemFlag)
	{
		if(y < mHeight && x < mWidth)
			mHFb[y][x] = color;
	}
}

void Brush::setFrameBuffer(unsigned short width, unsigned short height, Dot** fb)
{
	mWidth = width;
    mHeight = height;

	mHFb = fb;
	mMemFlag = true;
}

void Brush::setFrameBuffer(unsigned short width, unsigned short height, Dot* fb)
{
	unsigned long index;
	unsigned short i;

	mWidth = width;
    mHeight = height;

	if(mFb)
	{
		delete mHFb;
	}

	mFb = fb;
	
	mHFb = new Dot*[height];
	if(mHFb)
	{
		index = 0;
		for(i=0;i<height;i++)
		{
			mHFb[i] = &mFb[index];
			index += width;
		}
	}

	if(mHFb)
	{
		mMemFlag = true;
	}
}

void Brush::setColor(Dot color)
{
	this->color = color;
}

void Brush::setColor(unsigned short color)
{
	this->color.data = color;
}

void Brush::setBgColor(Dot color)
{
	bgColor = color;
}

void Brush::setBgColor(unsigned short color)
{
	bgColor.data = color;
}

void Brush::drawClear(void)
{
	setMcuDma2dFill((unsigned short**)mHFb, mWidth, mHeight, bgColor.data);
}

void Brush::doCopyFromImageToBuffer(Dot *image)
{
	unsigned short *buf[2] = {(unsigned short*)&image[0], (unsigned short*)&image[mWidth]};
	setMcuDma2dCopy(buf, mWidth, mHeight, (unsigned short**)mHFb, mWidth, mHeight, 0, 0);
}
