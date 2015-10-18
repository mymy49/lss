/*
 * objsys.cpp
 *
 *  Created on: 2010. 8. 30.
 *      Author: Yoon-Ki Hong
 */

#include <gui/ObjSys.h>

ObjSys::ObjSys(void)
{
	mPos.x = 0;
	mPos.y = 0;
	mParent = 0;
	mVisibleFlag = true;
	mAlpha = 255;

	doUpdate();
}

void ObjSys::setVisible(bool on)
{
	mVisibleFlag = on;
}

void ObjSys::setPos(unsigned short x, unsigned short y)
{
	mPos.x = x;
	mPos.y = y;
	doUpdate();
}

void ObjSys::setPos(Pos pos)
{
	mPos = pos;
}

Pos ObjSys::getPos(void)
{
	return mPos;
}

void ObjSys::doUpdate(void)
{
	mUpdateFlag = true;
	if(mParent)
		mParent->doUpdate();
}

bool ObjSys::isUpdated(void)
{
	return mUpdateFlag;
}

void ObjSys::resetUpdate(void)
{
	mUpdateFlag = false;
}

bool ObjSys::isVisible(void)
{
	return mVisibleFlag;
}

void ObjSys::getMe(ObjSys *parent)
{
	mParent = parent;
}

Dot** ObjSys::getFrameBuffer(void)
{
	mUpdateFlag = false;
	return mHFb;
}

void ObjSys::setAlpha(unsigned char alpha)
{
	mAlpha = alpha;
}

unsigned char ObjSys::getAlpha(void)
{
	return mAlpha;
}
