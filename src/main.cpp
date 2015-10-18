#include <stm32f429.h>
#include <malloc.h>
#include <schedule.h>
#include <lssConfig.h>
#include <gui/Brush.h>
#include <gui/Canvas.h>
#include <gui/Panel.h>
#include <gui/Label.h>
#include <gui/Image.h>
#include "img.h"

void func1(void);
void func2(void);
void func3(void);
void func4(void);
void func5(void);
void func6(void);
void func7(void);
void func8(void);

void setMcuLtdcFrameBuffer(void* fb);

Panel pn, pnSmall, pnSmall2;
Image img1, img2, img3, img4, img5, img6;
Canvas cv;

unsigned short *pFb, *pHFb[2];

int main(void)
{
	unsigned short **p1, **p2;
	setMcuRccGpioGEn(true);

	setMcuGpioMode(GPIOG, 13, GPIO_MODER_OUTPUT);
	setMcuGpioMode(GPIOG, 14, GPIO_MODER_OUTPUT);

	setMcuGpioMode(GPIOA, 8, GPIO_MODER_ALT_FUNC);
	setMcuGpioMode(GPIOC, 9, GPIO_MODER_ALT_FUNC);
	setMcuGpioAltfunc(GPIOA, 8, GPIO_AFR_I2C3);
	setMcuGpioAltfunc(GPIOC, 9, GPIO_AFR_I2C3);

	pFb = (unsigned short*)lmalloc(240*320*sizeof(unsigned short));
	pHFb[0] = &pFb[0];
	pHFb[1] = &pFb[240];
	setMcuLtdcFrameBuffer(pFb);

	cv.brush.setBgColor(0x07e0);
	pn.setSize(100, 100);
	pn.brush.setBgColor(0xf800);
	pn.setAlpha(150);

	pnSmall.setSize(50, 50);
	pnSmall.brush.setBgColor(0xffe0);

    setMcuRccGpioGEn(true);

	setMcuGpioMode(GPIOG, 13, GPIO_MODER_OUTPUT);
	setMcuGpioMode(GPIOG, 14, GPIO_MODER_OUTPUT);

	setMcuGpioMode(GPIOA, 8, GPIO_MODER_ALT_FUNC);
	setMcuGpioMode(GPIOC, 9, GPIO_MODER_ALT_FUNC);
	setMcuGpioAltfunc(GPIOA, 8, GPIO_AFR_I2C3);
	setMcuGpioAltfunc(GPIOC, 9, GPIO_AFR_I2C3);

	pFb = (unsigned short*)lmalloc(240*320*sizeof(unsigned short));
    pHFb[0] = &pFb[0];
    pHFb[1] = &pFb[240];
    setMcuLtdcFrameBuffer(pFb);

    cv.brush.setBgColor(0x07e0);
    pn.setSize(100, 100);
    pn.brush.setBgColor(0xf800);
	pn.setAlpha(150);

    pnSmall.setSize(50, 50);
    pnSmall.brush.setBgColor(0xffe0);

    pnSmall2.setSize(10, 10);
    pnSmall2.brush.setBgColor(0x001f);

	img1.setImage(220,165,(Dot*)IMAGE1);
	img2.setImage(220,165,(Dot*)IMAGE2);
	img3.setImage(220,165,(Dot*)IMAGE3);
	img4.setImage(220,165,(Dot*)IMAGE4);
	img5.setImage(220,165,(Dot*)IMAGE5);
	img6.setImage(220,165,(Dot*)IMAGE6);

	pnSmall.add(pnSmall2);

    pn.add(pnSmall);

	cv.add(img1);
	cv.add(img2);
	cv.add(img3);
	cv.add(img4);
	cv.add(img5);
	cv.add(img6);
	cv.add(pn);

	addThread(func1, 1024);
	addThread(func2, 1024);
	addThread(func3, 1024);
	addThread(func4, 1024);
	addThread(func5, 1024);
	addThread(func6, 1024);
	addThread(func7, 1024);
	addThread(func8, 1024);
   
    while(1)
    {
//		delay(50);
        setMcuDma2dCopy((unsigned short**)cv.getFrameBuffer(), 240, 320, pHFb, 240, 320, 0, 0);
    }

	pnSmall2.setSize(10, 10);
	pnSmall2.brush.setBgColor(0x001f);

	img1.setImage(220,165,(Dot*)IMAGE1);
	img2.setImage(220,165,(Dot*)IMAGE2);
	img3.setImage(220,165,(Dot*)IMAGE3);
	img4.setImage(220,165,(Dot*)IMAGE4);
	img5.setImage(220,165,(Dot*)IMAGE5);
	img6.setImage(220,165,(Dot*)IMAGE6);

	pnSmall.add(pnSmall2);

	pn.add(pnSmall);

	cv.add(img1);
	cv.add(img2);
	cv.add(img3);
	cv.add(img4);
	cv.add(img5);
	cv.add(img6);
	cv.add(pn);

	addThread(func1, 1024);
	addThread(func2, 1024);
	addThread(func3, 1024);
	addThread(func4, 1024);
	addThread(func5, 1024);
	addThread(func6, 1024);
	addThread(func7, 1024);
	addThread(func8, 1024);

	while(1)
	{
//		delay(50);
		setMcuDma2dCopy((unsigned short**)cv.getFrameBuffer(), 240, 320, pHFb, 240, 320, 0, 0);
	}

	return 0;
}

void func1(void)
{
    while(1)
    {
        setMcuGpioOdr(GPIOG, 13, false);
        delay(500);
        setMcuGpioOdr(GPIOG, 13, true);
        delay(500);
    }
}

void func2(void)
{
    while(1)
    {
        setMcuGpioOdr(GPIOG, 14, false);
        delay(250);
        setMcuGpioOdr(GPIOG, 14, true);
        delay(250);
    }
}

void func3(void)
{
    unsigned short bgColor = 0;

    while(1)
    {
        delay(250);
        cv.brush.setBgColor(bgColor++);
    }
}

#define INT    150

void func4(void)
{
    while(1)
    {
        img1.setVisible(true);
        img2.setVisible(false);
        img3.setVisible(false);
        img4.setVisible(false);
        img5.setVisible(false);
        img6.setVisible(false);
        delay(2000);
        img1.setVisible(false);
        img2.setVisible(true);
        img3.setVisible(false);
        img4.setVisible(false);
        img5.setVisible(false);
        img6.setVisible(false);
        delay(INT);
        img1.setVisible(false);
        img2.setVisible(false);
        img3.setVisible(true);
        img4.setVisible(false);
        img5.setVisible(false);
        img6.setVisible(false);
        delay(INT);
        img1.setVisible(false);
        img2.setVisible(false);
        img3.setVisible(false);
        img4.setVisible(true);
        img5.setVisible(false);
        img6.setVisible(false);
        delay(INT);
        img1.setVisible(false);
        img2.setVisible(false);
        img3.setVisible(false);
        img4.setVisible(false);
        img5.setVisible(true);
        img6.setVisible(false);
        delay(INT);
        img1.setVisible(false);
        img2.setVisible(false);
        img3.setVisible(false);
        img4.setVisible(false);
        img5.setVisible(false);
        img6.setVisible(true);
        delay(2000);
        img1.setVisible(false);
        img2.setVisible(false);
        img3.setVisible(false);
        img4.setVisible(false);
        img5.setVisible(true);
        img6.setVisible(false);
        delay(INT);
        img1.setVisible(false);
        img2.setVisible(false);
        img3.setVisible(false);
        img4.setVisible(true);
        img5.setVisible(false);
        img6.setVisible(false);
        delay(INT);
        img1.setVisible(false);
        img2.setVisible(false);
        img3.setVisible(true);
        img4.setVisible(false);
        img5.setVisible(false);
        img6.setVisible(false);
        delay(INT);
        img1.setVisible(false);
        img2.setVisible(true);
        img3.setVisible(false);
        img4.setVisible(false);
        img5.setVisible(false);
        img6.setVisible(false);
        delay(INT);
    }
}

void func5(void)
{
    unsigned short x = 0, y = 0;
    bool dirX = true, dirY = true;

    while(1)
    {
        delay(100);
        if(dirX)
        {
            x++;
            if(img1.getWidth()+x+1 >= LCD_WIDTH)
            {
                dirX = false;
            }
        }
        else
        {
            x--;
            if(x <= 1)
            {
                dirX = true;
            }
        }

        if(dirY)
        {
            y++;
            if(img1.getHeight()+y+1 >= LCD_HEIGHT)
            {
                dirY = false;
            }
        }
        else
        {
            y--;
            if(y <= 1)
            {
                dirY = true;
            }
        }

        img1.setPos(x, y);
        img2.setPos(x, y);
        img3.setPos(x, y);
        img4.setPos(x, y);
        img5.setPos(x, y);
        img6.setPos(x, y);
    }
}

void func6(void)
{
    unsigned short x = 20, y = 0;
    bool dirX = true, dirY = true;

    while(1)
    {
        delay(5);
        if(dirX)
        {
            x++;
            if(pnSmall2.getWidth()+x+1 >= pnSmall.getWidth())
            {
                dirX = false;
            }
        }
        else
        {
            x--;
            if(x <= 1)
            {
                dirX = true;
            }
        }

        if(dirY)
        {
            y++;
            if(pnSmall2.getHeight()+y+1 >= pnSmall.getHeight())
            {
                dirY = false;
            }
        }
        else
        {
            y--;
            if(y <= 1)
            {
                dirY = true;
            }
        }

        pnSmall2.setPos(x, y);
    }
}

void func7(void)
{
    unsigned short x = 0, y = 0;
    bool dirX = true, dirY = true;

    while(1)
    {
        delay(25);
        if(dirX)
        {
            x++;
            if(pn.getWidth()+x+1 >= LCD_WIDTH)
            {
                dirX = false;
            }
        }
        else
        {
            x--;
            if(x <= 1)
            {
                dirX = true;
            }
        }

        if(dirY)
        {
            y++;
            if(pn.getHeight()+y+1 >= LCD_HEIGHT)
            {
                dirY = false;
            }
        }
        else
        {
            y--;
            if(y <= 1)
            {
                dirY = true;
            }
        }

        pn.setPos(x, y);
    }
}

void func8(void)
{
    unsigned short x = 20, y = 0;
    bool dirX = true, dirY = true;

    while(1)
    {
        delay(10);
        if(dirX)
        {
            x++;
            if(pnSmall.getWidth()+x+1 >= pn.getWidth())
            {
                dirX = false;
            }
        }
        else
        {
            x--;
            if(x <= 1)
            {
                dirX = true;
            }
        }

        if(dirY)
        {
            y++;
            if(pnSmall.getHeight()+y+1 >= pn.getHeight())
            {
                dirY = false;
            }
        }
        else
        {
            y--;
            if(y <= 1)
            {
                dirY = true;
            }
        }

        pnSmall.setPos(x, y);
    }
}
