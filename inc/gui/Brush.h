/*
 * Brush.h
 *
 *  Created on: 2010. 8. 27.
 *      Author: Yoon-Ki Hong
 */

#ifndef LSS_GUI_BRUSH__H_
#define LSS_GUI_BRUSH__H_

#include "dot.h"

class Brush
{
	unsigned short mHeight, mWidth;
	bool mMemFlag;
	Dot color, bgColor;
	Dot** mHFb;
	Dot* mFb;

public:
	Brush(void);
	~Brush(void);

	void drawDot(unsigned short x, unsigned short y);
    void setFrameBuffer(unsigned short width, unsigned short height, Dot** fb);
    void setFrameBuffer(unsigned short width, unsigned short height, Dot* fb);
    void setColor(Dot color);
    void setColor(unsigned short color);
    void setBgColor(Dot color);
    void setBgColor(unsigned short color);
	void drawClear(void);
    void doCopyFromImageToBuffer(Dot *image);
/*
	void drawChar(unsigned short x, unsigned short y, short ch);
	void drawString(Pos pos, char* str);
	void drawPrintf(Pos pos, char* fmt, ...);
	void drawDot(Pos pos);

	void drawLine(Pos sp, Pos ep);
	
//	void drawCiurcle(Pos pos, frame r);
	void drawRectangle(Pos sp, Pos ep);
	
	
	
*/
};

#endif /* BRUSH_H_ */
