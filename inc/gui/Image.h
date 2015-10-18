/*
 * Image.h
 *
 *  Created on: 2010. 9. 14.
 *      Author: Yoon-Ki Hong (mymy49@nate.com)
 */

#ifndef IMAGE_H_
#define IMAGE_H_

#include "ObjSys.h"

class Image :public ObjSys
{

public:
	void setImage(unsigned short width, unsigned short height, Dot *image);

};

#endif /* IMAGE_H_ */
