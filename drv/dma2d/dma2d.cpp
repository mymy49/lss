#include <stm32f429.h>

static void wait(void);

volatile unsigned long gOrderCur=1, gOrderReg;
static void (*pWaitFunc)(void) = wait;

void initMcuDma2d(void)
{
	setMcuDma2dTcie(true);
    setMcuNvicIntEn(DMA2D_IRQn);
}

static void wait(void)
{
	
}

static unsigned long getOrder(void)
{
	return ++gOrderReg;
}

void setMcuDma2dWaitFunc(void (*func)(void))
{
	pWaitFunc = func;
}

extern "C"
{
	void DMA2D_IRQHandler(void)
	{
		if(getMcuDma2dTcif())
		{
			clrMcuDma2dTcif();
            gOrderCur++;
		}
	}
}

void setMcuDma2dFill(unsigned short** addr, unsigned short width, unsigned short height, unsigned short color)
{
	unsigned long order = getOrder();
    
	while(order != gOrderCur)
		pWaitFunc();

	unsigned long offset = (((unsigned long)addr[1] - (unsigned long)addr[0]) >> 1) - width;

	setMcuDma2dMode(DMA2D_MODE_REG_TO_MEM);
	setMcuDma2dOutputColorMode(DMA2D_COLOR_MODE_RGB565);
	setMcuDma2dOutputColor(color);
	setMcuDma2dOmar(addr[0]);
	setMcuDma2dNumOfLine(height);
	setMcuDma2dNumOfPixel(width);
	setMcuDma2dOutputLineOffset(offset);
	setMcuDma2dStart();
}  

void setMcuDma2dCopy(unsigned short** srcBf, unsigned short srcWidth, unsigned short srcHeight, unsigned short** desBf, unsigned short desWidth, unsigned short desHeight, unsigned short desX, unsigned short desY)
{
	unsigned long order = getOrder();
	
	while(order != gOrderCur)
		pWaitFunc();

	unsigned long srcOffset = (((unsigned long)srcBf[1] - (unsigned long)srcBf[0]) >> 1) - srcWidth;
	unsigned long desOffset = (((unsigned long)desBf[1] - (unsigned long)desBf[0]) >> 1) - desWidth;
	
	desOffset += desWidth - srcWidth;
	
	setMcuDma2dMode(DMA2D_MODE_MEM_TO_MEM);
	setMcuDma2dFgmar(srcBf[0]);
	setMcuDma2dOmar(&desBf[desY][desX]);
	setMcuDma2dFgColorMode(DMA2D_COLOR_MODE_RGB565);
	setMcuDma2dOutputColorMode(DMA2D_COLOR_MODE_RGB565);
	setMcuDma2dNumOfLine(srcHeight);
	setMcuDma2dNumOfPixel(srcWidth);
	setMcuDma2dFgLineOffset(srcOffset);
	setMcuDma2dOutputLineOffset(desOffset);
	setMcuDma2dStart();
}  

void setMcuDma2dCopy(unsigned short** srcBf, unsigned short srcWidth, unsigned short srcHeight, unsigned short** desBf, unsigned short desWidth, unsigned short desHeight, unsigned short desX, unsigned short desY, unsigned char alpha)
{
	unsigned long order = getOrder();
	
	while(order != gOrderCur)
		pWaitFunc();

	unsigned long srcOffset = (((unsigned long)srcBf[1] - (unsigned long)srcBf[0]) >> 1) - srcWidth;
	unsigned long desOffset = (((unsigned long)desBf[1] - (unsigned long)desBf[0]) >> 1) - desWidth;
	
	desOffset += desWidth - srcWidth;
	
	setMcuDma2dMode(DMA2D_MODE_MEM_TO_MEM_BLENDING);
	setMcuDma2dFgmar(srcBf[0]);
	setMcuDma2dBgmar(&desBf[desY][desX]);
	setMcuDma2dOmar(&desBf[desY][desX]);
    setMcuDma2dFgAlpha(alpha);
    setMcuDma2dFgAlphaMode(1);
	setMcuDma2dFgColorMode(DMA2D_COLOR_MODE_RGB565);
	setMcuDma2dBgColorMode(DMA2D_COLOR_MODE_RGB565);
	setMcuDma2dOutputColorMode(DMA2D_COLOR_MODE_RGB565);
	setMcuDma2dNumOfLine(srcHeight);
	setMcuDma2dNumOfPixel(srcWidth);
	setMcuDma2dFgLineOffset(srcOffset);
    setMcuDma2dBgLineOffset(desOffset);
	setMcuDma2dOutputLineOffset(desOffset);
	setMcuDma2dStart();
}  