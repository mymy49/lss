/*
 * canvas.cpp
 *
 *  Created on: 2010. 8. 31.
 *      Author: Yoon-Ki Hong
 */

#include <gui/Canvas.h>
#include <malloc.h>
#include <lssConfig.h>
#include <stm32f429.h>

Canvas::Canvas()
{
	setSize(LCD_WIDTH, LCD_HEIGHT);
	mMaxObj = 0;
	mNumOfObj = 0;
	doIncreaseObjArr();
}

void Canvas::doRefresh(void)
{
	unsigned short i;

	for(i=0;i<mNumOfObj;i++)
	{
		if(mObjArr[i]->isVisible())
			drawObj(mObjArr[i]);
	}
}

void Canvas::add(ObjSys &obj)
{
	if(mNumOfObj+1 >= mMaxObj)
		doIncreaseObjArr();

	mObjArr[mNumOfObj] = &obj;
	obj.getMe(this);
	mNumOfObj++;

	doUpdate();
}

void Canvas::doIncreaseObjArr(void)
{
	unsigned short i;
	ObjSys** temp;

	temp = (ObjSys**)hmalloc(sizeof(ObjSys*)*(mMaxObj+8));

	if(mMaxObj)
	{
		for(i=0;i<mMaxObj;i++)
			temp[i] = mObjArr[i];

		hfree(mObjArr);
	}
	mMaxObj += 8;

	mObjArr = temp;
}

void Canvas::drawObj(ObjSys *obj)
{
	unsigned char alpha = obj->getAlpha();
	Pos pos = obj->getPos();

	if(alpha == 255)
		setMcuDma2dCopy((unsigned short**)obj->getFrameBuffer(), obj->getWidth(), obj->getHeight(), (unsigned short**)mHFb, getWidth(), getHeight(), pos.x, pos.y);
	else
		setMcuDma2dCopy((unsigned short**)obj->getFrameBuffer(), obj->getWidth(), obj->getHeight(), (unsigned short**)mHFb, getWidth(), getHeight(), pos.x, pos.y, alpha);
}

Dot** Canvas::getFrameBuffer(void)
{
	brush.drawClear();
	doRefresh();
	resetUpdate();
	return mHFb;
}
