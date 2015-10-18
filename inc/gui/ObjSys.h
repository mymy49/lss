/*
 * guisys.h
 *
 *  Created on: 2010. 8. 27.
 *      Author: Yoon-Ki Hong
 */

#ifndef LSS_GUI_OBJSYS__H_
#define LSS_GUI_OBJSYS__H_

#include "dot.h"
#include "Frame.h"

class ObjSys : public Frame
{
protected:
	bool mUpdateFlag, mVisibleFlag;
	Pos mPos;
	ObjSys *mParent;
	unsigned char mAlpha;

public:
	ObjSys(void);

	virtual void setPos(unsigned short x, unsigned short y);
	virtual void setPos(Pos pos);
	unsigned short getPosX(void);
    unsigned short getPosY(void);
	Pos getPos(void);

	void doUpdate(void);
	bool isUpdated(void);
	void resetUpdate(void);
	bool isVisible(void);
	void setVisible(bool on);
	void getMe(ObjSys *parent);
	virtual Dot** getFrameBuffer(void);

	void setAlpha(unsigned char alpha);
	unsigned char getAlpha(void);

};

#endif /* GUISYS_H_ */
