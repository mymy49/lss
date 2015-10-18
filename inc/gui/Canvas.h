/*
 * Canvas.h
 *
 *  Created on: 2010. 8. 31.
 *      Author: Yoon-Ki Hong
 */

#ifndef LSS_GUI_CANVAS__H_
#define LSS_GUI_CANVAS__H_

#include "ObjSys.h"

class Canvas : public ObjSys
{
protected:
	unsigned short mNumOfObj, mMaxObj;
	ObjSys **mObjArr;

public:
	Canvas(void);

	virtual void doRefresh(void);
	void drawObj(ObjSys *obj);

	void doIncreaseObjArr(void);
	void add(ObjSys &obj);

	virtual Dot** getFrameBuffer(void);
};

#endif /* CANVAS_H_ */
