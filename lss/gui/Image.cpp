/*
 * image.cpp
 *
 *  Created on: 2010. 9. 14.
 *      Author: Administrator
 */

#include <gui/Image.h>

void Image::setImage(unsigned short width, unsigned short height, Dot *image)
{
	setSize(width, height);
	brush.doCopyFromImageToBuffer(image);
}
