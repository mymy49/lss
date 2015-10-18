/*
 * Panel.h
 *
 *  Created on: 2010. 8. 31.
 *      Author: Yoon-Ki Hong
 */

#ifndef LSS_GUI_PANEL__H_
#define LSS_GUI_PANEL__H_

#include "ObjSys.h"

class Panel : public ObjSys
{
protected:
	unsigned short mNumOfObj, mMaxObj;
	ObjSys **mObjArr;

public:
	Panel(void);

	virtual void doRefresh(void);
	void drawObj(ObjSys *obj);

	void doIncreaseObjArr(void);
	void add(ObjSys &obj);

    virtual Dot** getFrameBuffer(void);

};

#endif /* PANEL_H_ */
