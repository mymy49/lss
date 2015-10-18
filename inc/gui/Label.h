/*
 * Label.h
 *
 *  Created on: 2010. 8. 31.
 *      Author: Yoon-Ki Hong
 */

#ifndef LABEL_H_
#define LABEL_H_

#define LABEL_STR_LENGTH	32
#define LABEL_HEIGHT		16

#include "dot.h"
#include "ObjSys.h"

class Label : public ObjSys
{
	char str[LABEL_STR_LENGTH];
	void draw(void);

public:
//	Label(void);
//	Label(char* fmt,...);
//	~Label(void);
	void set(char* fmt,...);

	virtual void setColor(Dot color);
	virtual void setBgColor(Dot color);
};

#endif /* LABEL_H_ */
