/*
 * raw.cpp
 *
 *  Created on: 2010. 8. 30.
 *      Author: Administrator
 */

#include <gui/Frame.h>
#include <malloc.h>

Frame::Frame(void)
{
	mWidth = 0;
	mHeight = 0;
	mFb = 0;
    mHFb = 0;
	mMemFlag = false;
}

Frame::~Frame(void)
{
	unsigned short i;

	if(mMemFlag)
	{
		for(i=0;i<mHeight;i++)
			lfree(mHFb[i]);
		hfree(mFb);
	}
}

void Frame::setSize(unsigned short width, unsigned short height)
{
	unsigned short i;
    unsigned long index;

	mHeight = height;
	mWidth = width;
	
	if(mFb)
	{
		lfree(mFb);
	}
	mFb = (Dot*)lmalloc(sizeof(Dot)*mHeight*mWidth);
	
   	if(mHFb)
	{
		hfree(mHFb);
	}

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

	if(mFb && mHFb)
	{
		mMemFlag = true;
	}

	brush.setFrameBuffer(width, height, mHFb);
}

Dot** Frame::getFrameBuffer(void)
{
	return mHFb;
}

unsigned short Frame::getHeight(void)
{
	return mHeight;
}

unsigned short Frame::getWidth(void)
{
	return mWidth;
}
