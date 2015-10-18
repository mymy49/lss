/*
 * raw.h
 *
 *  Created on: 2010. 8. 27.
 *      Author: Yoon-Ki Hong
 */

#ifndef LSS_GUI_FRAME__H_
#define LSS_GUI_FRAME__H_

#include "dot.h"
#include <gui/Brush.h>

class Frame
{
	bool mMemFlag;
	unsigned short mHeight, mWidth;

protected:
    Dot** mHFb;
    Dot* mFb;

public:
	Brush brush;

	Frame(void);
	~Frame(void);
	void setSize(unsigned short width, unsigned short height);
	virtual Dot** getFrameBuffer(void);
	unsigned short getHeight(void);
	unsigned short getWidth(void);
//	void setIntFunc(void (*cli)(void), void (*sei)(void));
};

#endif /* RAW_H_ */
