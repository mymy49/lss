#include <stm32f429.h>
#include <dev/lcd.h>

inline void initClock(void)
{
	setMcuRccPpre2(RCC_AHB_DIV_2);	// 84Mhz
	setMcuRccPpre1(RCC_AHB_DIV_8);	// 21Mhz

	setMcuFlashLatency(5);
	setMcuFlashPrefetch(true);

	setMcuPwrVos(3);

	setMcuRccHseEn(true);
	waitMcuRccHseRdy();

	// PLL Configuration - 168Mhz
	setMcuRccMainPllm(8);
	setMcuRccMainPlln(336);
	setMcuRccMainPllp(0);
	setMcuRccMainPllq(8);

	setMcuRccMainPllSrc(true);

	setMcuRccMainPllOn(true);
	waitMcuRccMainPllRdy();

	setMcuRccSysclkSw(RCC_SW_PLL);
}

void sendDevLcdCmd(unsigned char cmd)
{
	setDevLcdDcxCmd();
	setDevLcdCs(true);
	exchMcuSpi(SPI5, cmd);
	setDevLcdCs(false);
}

void sendDevLcdData(unsigned char data)
{
	setDevLcdDcxData();
	setDevLcdCs(true);
	exchMcuSpi(SPI5, data);
	setDevLcdCs(false);
}

#define LCD_SLEEP_OUT            0x11   /* Sleep out register */
#define LCD_GAMMA                0x26   /* Gamma register */
#define LCD_DISPLAY_OFF          0x28   /* Display off register */
#define LCD_DISPLAY_ON           0x29   /* Display on register */
#define LCD_COLUMN_ADDR          0x2A   /* Colomn address register */ 
#define LCD_PAGE_ADDR            0x2B   /* Page address register */ 
#define LCD_GRAM                 0x2C   /* GRAM register */   
#define LCD_MAC                  0x36   /* Memory Access Control register*/
#define LCD_PIXEL_FORMAT         0x3A   /* Pixel Format register */
#define LCD_WDB                  0x51   /* Write Brightness Display register */
#define LCD_WCD                  0x53   /* Write Control Display register*/
#define LCD_RGB_INTERFACE        0xB0   /* RGB Interface Signal Control */
#define LCD_FRC                  0xB1   /* Frame Rate Control register */
#define LCD_BPC                  0xB5   /* Blanking Porch Control register*/
#define LCD_DFC                  0xB6   /* Display Function Control register*/
#define LCD_POWER1               0xC0   /* Power Control 1 register */
#define LCD_POWER2               0xC1   /* Power Control 2 register */
#define LCD_VCOM1                0xC5   /* VCOM Control 1 register */
#define LCD_VCOM2                0xC7   /* VCOM Control 2 register */
#define LCD_POWERA               0xCB   /* Power control A register */
#define LCD_POWERB               0xCF   /* Power control B register */
#define LCD_PGAMMA               0xE0   /* Positive Gamma Correction register*/
#define LCD_NGAMMA               0xE1   /* Negative Gamma Correction register*/
#define LCD_DTCA                 0xE8   /* Driver timing control A */
#define LCD_DTCB                 0xEA   /* Driver timing control B */
#define LCD_POWER_SEQ            0xED   /* Power on sequence register */
#define LCD_3GAMMA_EN            0xF2   /* 3 Gamma enable register */
#define LCD_INTERFACE            0xF6   /* Interface control register */
#define LCD_PRC                  0xF7   /* Pump ratio control register */

void initLtdc(void)
{
	// RCC Configuration
	setMcuRccGpioAEn(true);
	setMcuRccGpioBEn(true);
	setMcuRccGpioCEn(true);
	setMcuRccGpioDEn(true);
	setMcuRccGpioFEn(true);
	setMcuRccGpioGEn(true);
	setMcuRccSpi5En(true);
	setMcuRccLtdcEn(true);
	setMcuRccDma2dEn(true);

	// SPI5 port Configuration
	setMcuGpioMode(GPIOC, 2, GPIO_MODER_OUTPUT);
	setMcuGpioMode(GPIOD, 13, GPIO_MODER_OUTPUT);
	setMcuGpioMode(GPIOF, 7, GPIO_MODER_ALT_FUNC);
	setMcuGpioMode(GPIOF, 9, GPIO_MODER_ALT_FUNC);
	setMcuGpioAltfunc(GPIOF, 7, GPIO_AFR_SPI_AF5);
	setMcuGpioAltfunc(GPIOF, 9, GPIO_AFR_SPI_AF5);
	setMcuGpioOspeed(GPIOC, 2, GPIO_SPEED_FAST);
	setMcuGpioOspeed(GPIOD, 13, GPIO_SPEED_FAST);
	setMcuGpioOspeed(GPIOF, 7, GPIO_SPEED_FAST);
	setMcuGpioOspeed(GPIOF, 9, GPIO_SPEED_FAST);

	setDevLcdCs(false);

	// LTDC port Configuration
	setMcuGpioMode(GPIOA, 4, GPIO_MODER_ALT_FUNC);
	setMcuGpioMode(GPIOC, 6, GPIO_MODER_ALT_FUNC);
	setMcuGpioMode(GPIOF, 10, GPIO_MODER_ALT_FUNC);
	setMcuGpioMode(GPIOG, 7, GPIO_MODER_ALT_FUNC);

	setMcuGpioMode(GPIOC, 10, GPIO_MODER_ALT_FUNC);
	setMcuGpioMode(GPIOB, 0, GPIO_MODER_ALT_FUNC);
	setMcuGpioMode(GPIOA, 11, GPIO_MODER_ALT_FUNC);
	setMcuGpioMode(GPIOA, 12, GPIO_MODER_ALT_FUNC);
	setMcuGpioMode(GPIOB, 1, GPIO_MODER_ALT_FUNC);
	setMcuGpioMode(GPIOG, 6, GPIO_MODER_ALT_FUNC);

	setMcuGpioMode(GPIOA, 6, GPIO_MODER_ALT_FUNC);
	setMcuGpioMode(GPIOG, 10, GPIO_MODER_ALT_FUNC);
	setMcuGpioMode(GPIOB, 10, GPIO_MODER_ALT_FUNC);
	setMcuGpioMode(GPIOB, 11, GPIO_MODER_ALT_FUNC);
	setMcuGpioMode(GPIOC, 7, GPIO_MODER_ALT_FUNC);
	setMcuGpioMode(GPIOD, 3, GPIO_MODER_ALT_FUNC);

	setMcuGpioMode(GPIOD, 6, GPIO_MODER_ALT_FUNC);
	setMcuGpioMode(GPIOG, 11, GPIO_MODER_ALT_FUNC);
	setMcuGpioMode(GPIOG, 12, GPIO_MODER_ALT_FUNC);
	setMcuGpioMode(GPIOA, 3, GPIO_MODER_ALT_FUNC);
	setMcuGpioMode(GPIOB, 8, GPIO_MODER_ALT_FUNC);
	setMcuGpioMode(GPIOB, 9, GPIO_MODER_ALT_FUNC);

	setMcuGpioAltfunc(GPIOA, 4, GPIO_AFR_LCD_AF14);
	setMcuGpioAltfunc(GPIOC, 6, GPIO_AFR_LCD_AF14);
	setMcuGpioAltfunc(GPIOF, 10, GPIO_AFR_LCD_AF14);
	setMcuGpioAltfunc(GPIOG, 7, GPIO_AFR_LCD_AF14);

	setMcuGpioAltfunc(GPIOC, 10, GPIO_AFR_LCD_AF14);
	setMcuGpioAltfunc(GPIOB, 0, GPIO_AFR_LCD_AF9);
	setMcuGpioAltfunc(GPIOA, 11, GPIO_AFR_LCD_AF14);
	setMcuGpioAltfunc(GPIOA, 12, GPIO_AFR_LCD_AF14);
	setMcuGpioAltfunc(GPIOB, 1, GPIO_AFR_LCD_AF9);
	setMcuGpioAltfunc(GPIOG, 6, GPIO_AFR_LCD_AF14);

	setMcuGpioAltfunc(GPIOA, 6, GPIO_AFR_LCD_AF14);
	setMcuGpioAltfunc(GPIOG, 10, GPIO_AFR_LCD_AF9);
	setMcuGpioAltfunc(GPIOB, 10, GPIO_AFR_LCD_AF14);
	setMcuGpioAltfunc(GPIOB, 11, GPIO_AFR_LCD_AF14);
	setMcuGpioAltfunc(GPIOC, 7, GPIO_AFR_LCD_AF14);
	setMcuGpioAltfunc(GPIOD, 3, GPIO_AFR_LCD_AF14);

	setMcuGpioAltfunc(GPIOD, 6, GPIO_AFR_LCD_AF14);
	setMcuGpioAltfunc(GPIOG, 11, GPIO_AFR_LCD_AF14);
	setMcuGpioAltfunc(GPIOG, 12, GPIO_AFR_LCD_AF9);
	setMcuGpioAltfunc(GPIOA, 3, GPIO_AFR_LCD_AF14);
	setMcuGpioAltfunc(GPIOB, 8, GPIO_AFR_LCD_AF14);
	setMcuGpioAltfunc(GPIOB, 9, GPIO_AFR_LCD_AF14);

	setMcuGpioOspeed(GPIOA, 4, GPIO_SPEED_FAST);
	setMcuGpioOspeed(GPIOC, 6, GPIO_SPEED_FAST);
	setMcuGpioOspeed(GPIOF, 10, GPIO_SPEED_FAST);
	setMcuGpioOspeed(GPIOG, 7, GPIO_SPEED_FAST);

	setMcuGpioOspeed(GPIOC, 10, GPIO_SPEED_FAST);
	setMcuGpioOspeed(GPIOB, 0, GPIO_SPEED_FAST);
	setMcuGpioOspeed(GPIOA, 11, GPIO_SPEED_FAST);
	setMcuGpioOspeed(GPIOA, 12, GPIO_SPEED_FAST);
	setMcuGpioOspeed(GPIOB, 1, GPIO_SPEED_FAST);
	setMcuGpioOspeed(GPIOG, 6, GPIO_SPEED_FAST);

	setMcuGpioOspeed(GPIOA, 6, GPIO_SPEED_FAST);
	setMcuGpioOspeed(GPIOG, 10, GPIO_SPEED_FAST);
	setMcuGpioOspeed(GPIOB, 10, GPIO_SPEED_FAST);
	setMcuGpioOspeed(GPIOB, 11, GPIO_SPEED_FAST);
	setMcuGpioOspeed(GPIOC, 7, GPIO_SPEED_FAST);
	setMcuGpioOspeed(GPIOD, 3, GPIO_SPEED_FAST);

	setMcuGpioOspeed(GPIOD, 6, GPIO_SPEED_FAST);
	setMcuGpioOspeed(GPIOG, 11, GPIO_SPEED_FAST);
	setMcuGpioOspeed(GPIOG, 12, GPIO_SPEED_FAST);
	setMcuGpioOspeed(GPIOA, 3, GPIO_SPEED_FAST);
	setMcuGpioOspeed(GPIOB, 8, GPIO_SPEED_FAST);
	setMcuGpioOspeed(GPIOB, 9, GPIO_SPEED_FAST);

	// SPI5 Configuration
	setMcuSpiBaudrate(SPI5, MCU_SPI_BAUDRATE_32);
	setMcuSPiMode(SPI5, 0);
	setMcuSpiDff(SPI5, 0);
	setMcuSpiMsbfirst(SPI5);
	setMcuSpiSsm(SPI5, 1);
	setMcuSpiSsi(SPI5, 1);
	setMcuSpiMstr(SPI5, 1);
	setMcuSpiTxeie(SPI5, true);
	setMcuSpiRxneie(SPI5, true);
	setMcuSpiEnable(SPI5, true);

	sendDevLcdCmd(0xca);
	sendDevLcdData(0xc3);
	sendDevLcdData(0x08);
	sendDevLcdData(0x50);

	sendDevLcdCmd(LCD_POWERB);
	sendDevLcdData(0x00);
	sendDevLcdData(0xc1);
	sendDevLcdData(0x30);

	sendDevLcdCmd(LCD_POWER_SEQ);
	sendDevLcdData(0x64);
	sendDevLcdData(0x03);
	sendDevLcdData(0x12);
	sendDevLcdData(0x81);

	sendDevLcdCmd(LCD_DTCA);
	sendDevLcdData(0x85);
	sendDevLcdData(0x00);
	sendDevLcdData(0x78);

	sendDevLcdCmd(LCD_POWERA);
	sendDevLcdData(0x39);
	sendDevLcdData(0x2c);
	sendDevLcdData(0x00);
	sendDevLcdData(0x34);
	sendDevLcdData(0x02);

	sendDevLcdCmd(LCD_PRC);
	sendDevLcdData(0x20);

	sendDevLcdCmd(LCD_DTCB);
	sendDevLcdData(0x00);
	sendDevLcdData(0x00);

	sendDevLcdCmd(LCD_FRC);
	sendDevLcdData(0x00);
	sendDevLcdData(0x1b);

	sendDevLcdCmd(LCD_DFC);
	sendDevLcdData(0x0a);
	sendDevLcdData(0xa2);

	sendDevLcdCmd(LCD_POWER1);
	sendDevLcdData(0x10);

	sendDevLcdCmd(LCD_POWER2);
	sendDevLcdData(0x10);

	sendDevLcdCmd(LCD_VCOM1);
	sendDevLcdData(0x45);
	sendDevLcdData(0x15);

	sendDevLcdCmd(LCD_VCOM2);
	sendDevLcdData(0x90);

	sendDevLcdCmd(LCD_MAC);
	sendDevLcdData(0xc8);

	sendDevLcdCmd(LCD_3GAMMA_EN);
	sendDevLcdData(0x00);

	sendDevLcdCmd(LCD_RGB_INTERFACE);
	sendDevLcdData(0xc2);

	sendDevLcdCmd(LCD_DFC);
	sendDevLcdData(0x0a);
	sendDevLcdData(0xa7);
	sendDevLcdData(0x27);
	sendDevLcdData(0x04);

	sendDevLcdCmd(LCD_COLUMN_ADDR);
	sendDevLcdData(0x00);
	sendDevLcdData(0x00);
	sendDevLcdData(0x00);
	sendDevLcdData(0xef);

	sendDevLcdCmd(LCD_PAGE_ADDR);
	sendDevLcdData(0x00);
	sendDevLcdData(0x00);
	sendDevLcdData(0x01);
	sendDevLcdData(0x3f);

	sendDevLcdCmd(LCD_INTERFACE);
	sendDevLcdData(0x01);
	sendDevLcdData(0x00);
	sendDevLcdData(0x06);

	sendDevLcdCmd(LCD_GRAM);
	for(volatile long i=0;i<200;i++);

	sendDevLcdCmd(LCD_GAMMA);
	sendDevLcdData(0x01);

	sendDevLcdCmd(LCD_PGAMMA);
	sendDevLcdData(0x0f);
	sendDevLcdData(0x29);
	sendDevLcdData(0x24);
	sendDevLcdData(0x0c);
	sendDevLcdData(0x0e);
	sendDevLcdData(0x09);
	sendDevLcdData(0x4e);
	sendDevLcdData(0x78);
	sendDevLcdData(0x3c);
	sendDevLcdData(0x09);
	sendDevLcdData(0x13);
	sendDevLcdData(0x05);
	sendDevLcdData(0x17);
	sendDevLcdData(0x11);
	sendDevLcdData(0x00);

	sendDevLcdCmd(LCD_NGAMMA);
	sendDevLcdData(0x00);
	sendDevLcdData(0x16);
	sendDevLcdData(0x1b);
	sendDevLcdData(0x04);
	sendDevLcdData(0x11);
	sendDevLcdData(0x07);
	sendDevLcdData(0x31);
	sendDevLcdData(0x33);
	sendDevLcdData(0x42);
	sendDevLcdData(0x05);
	sendDevLcdData(0x0c);
	sendDevLcdData(0x0a);
	sendDevLcdData(0x28);
	sendDevLcdData(0x2f);
	sendDevLcdData(0x0f);

	sendDevLcdCmd(LCD_SLEEP_OUT);
	for(volatile long i=0;i<200;i++);

	sendDevLcdCmd(LCD_DISPLAY_ON);
	sendDevLcdCmd(LCD_GRAM);

	setMcuRccSaiPlln(192);
	setMcuRccSaiPllq(4);
	setMcuRccSaiPllr(2);
	setMcuRccSaiDivr(2);

	setMcuRccSaiPllOn(true);
	waitMcuRccSaiPllRdy();

	setMcuLtdcHsw(9);
	setMcuLtdcVsh(1);
	setMcuLtdcAhbp(29);
	setMcuLtdcAvbp(3);
	setMcuLtdcAaw(269);
	setMcuLtdcAah(323);
	setMcuLtdcTotalw(279);
	setMcuLtdcTotalh(327);

	setMcuLtdcHspol(false);
	setMcuLtdcVspol(false);
	setMcuLtdcDepol(false);
	setMcuLtdcPcpol(false);

	setMcuLtdcBcRed(0);
	setMcuLtdcBcGreen(0);
	setMcuLtdcBcBlue(0);

	setMcuLtdcLayerWhpcr(LTDC_Layer1, 30, 269);
	setMcuLtdcLayerWvpcr(LTDC_Layer1, 4, 323);
	setMcuLtdcLayerPixelFormat(LTDC_Layer1, LTDC_PIXEL_FORMAT_RGB565);
	setMcuLtdcLayerDccr(LTDC_Layer1, 0, 0, 0, 0);
	setMcuLtdcLayerConstAlpha(LTDC_Layer1, 0xff);
	setMcuLtdcLayerBfcr(LTDC_Layer1, 4, 5);
//	setMcuLtdcLayerFrameBuffer(LTDC_Layer1, 0xd0000000);
	setMcuLtdcLayerCfblr(LTDC_Layer1, 480, 483);
	setMcuLtdcLayerFrameBufferLineNumber(LTDC_Layer1, 320);
	setMcuLtdcImediateReload();

	setMcuLtdcLayerEn(LTDC_Layer1, true);
	setMcuLtdcImediateReload();

	setMcuLtdcDitherEn(true);
	setMcuLtdcEn(true);
}

void initSdram(void)
{
	unsigned long buf;

    // RCC GPIO setup
    setMcuRccGpioBEn(true);
    setMcuRccGpioCEn(true);
    setMcuRccGpioDEn(true);
    setMcuRccGpioEEn(true);
    setMcuRccGpioFEn(true);
    setMcuRccGpioGEn(true);

    // SDRAM GPIO setup
    setMcuGpioMode(GPIOB, 5, GPIO_MODER_ALT_FUNC);
    setMcuGpioMode(GPIOB, 6, GPIO_MODER_ALT_FUNC);
    setMcuGpioMode(GPIOC, 0, GPIO_MODER_ALT_FUNC);
    setMcuGpioMode(GPIOD, 0, GPIO_MODER_ALT_FUNC);
    setMcuGpioMode(GPIOD, 1, GPIO_MODER_ALT_FUNC);
    setMcuGpioMode(GPIOD, 8, GPIO_MODER_ALT_FUNC);
    setMcuGpioMode(GPIOD, 9, GPIO_MODER_ALT_FUNC);
    setMcuGpioMode(GPIOD, 10, GPIO_MODER_ALT_FUNC);
    setMcuGpioMode(GPIOD, 14, GPIO_MODER_ALT_FUNC);
    setMcuGpioMode(GPIOD, 15, GPIO_MODER_ALT_FUNC);
    setMcuGpioMode(GPIOE, 0, GPIO_MODER_ALT_FUNC);
    setMcuGpioMode(GPIOE, 1, GPIO_MODER_ALT_FUNC);
    setMcuGpioMode(GPIOE, 7, GPIO_MODER_ALT_FUNC);
    setMcuGpioMode(GPIOE, 8, GPIO_MODER_ALT_FUNC);
    setMcuGpioMode(GPIOE, 9, GPIO_MODER_ALT_FUNC);
    setMcuGpioMode(GPIOE, 10, GPIO_MODER_ALT_FUNC);
    setMcuGpioMode(GPIOE, 11, GPIO_MODER_ALT_FUNC);
    setMcuGpioMode(GPIOE, 12, GPIO_MODER_ALT_FUNC);
    setMcuGpioMode(GPIOE, 13, GPIO_MODER_ALT_FUNC);
    setMcuGpioMode(GPIOE, 14, GPIO_MODER_ALT_FUNC);
    setMcuGpioMode(GPIOE, 15, GPIO_MODER_ALT_FUNC);
    setMcuGpioMode(GPIOF, 0, GPIO_MODER_ALT_FUNC);
    setMcuGpioMode(GPIOF, 1, GPIO_MODER_ALT_FUNC);
    setMcuGpioMode(GPIOF, 2, GPIO_MODER_ALT_FUNC);
    setMcuGpioMode(GPIOF, 3, GPIO_MODER_ALT_FUNC);
    setMcuGpioMode(GPIOF, 4, GPIO_MODER_ALT_FUNC);
    setMcuGpioMode(GPIOF, 5, GPIO_MODER_ALT_FUNC);
    setMcuGpioMode(GPIOF, 11, GPIO_MODER_ALT_FUNC);
    setMcuGpioMode(GPIOF, 12, GPIO_MODER_ALT_FUNC);
    setMcuGpioMode(GPIOF, 13, GPIO_MODER_ALT_FUNC);
    setMcuGpioMode(GPIOF, 14, GPIO_MODER_ALT_FUNC);
    setMcuGpioMode(GPIOF, 15, GPIO_MODER_ALT_FUNC);
    setMcuGpioMode(GPIOG, 0, GPIO_MODER_ALT_FUNC);
    setMcuGpioMode(GPIOG, 1, GPIO_MODER_ALT_FUNC);
    setMcuGpioMode(GPIOG, 4, GPIO_MODER_ALT_FUNC);
    setMcuGpioMode(GPIOG, 5, GPIO_MODER_ALT_FUNC);
    setMcuGpioMode(GPIOG, 8, GPIO_MODER_ALT_FUNC);
    setMcuGpioMode(GPIOG, 15, GPIO_MODER_ALT_FUNC);

    setMcuGpioAltfunc(GPIOB, 5, GPIO_AFR_SDRAM);
    setMcuGpioAltfunc(GPIOB, 6, GPIO_AFR_SDRAM);
    setMcuGpioAltfunc(GPIOC, 0, GPIO_AFR_SDRAM);
    setMcuGpioAltfunc(GPIOD, 0, GPIO_AFR_SDRAM);
    setMcuGpioAltfunc(GPIOD, 1, GPIO_AFR_SDRAM);
    setMcuGpioAltfunc(GPIOD, 8, GPIO_AFR_SDRAM);
    setMcuGpioAltfunc(GPIOD, 9, GPIO_AFR_SDRAM);
    setMcuGpioAltfunc(GPIOD, 10, GPIO_AFR_SDRAM);
    setMcuGpioAltfunc(GPIOD, 14, GPIO_AFR_SDRAM);
    setMcuGpioAltfunc(GPIOD, 15, GPIO_AFR_SDRAM);
    setMcuGpioAltfunc(GPIOE, 0, GPIO_AFR_SDRAM);
    setMcuGpioAltfunc(GPIOE, 1, GPIO_AFR_SDRAM);
    setMcuGpioAltfunc(GPIOE, 7, GPIO_AFR_SDRAM);
    setMcuGpioAltfunc(GPIOE, 8, GPIO_AFR_SDRAM);
    setMcuGpioAltfunc(GPIOE, 9, GPIO_AFR_SDRAM);
    setMcuGpioAltfunc(GPIOE, 10, GPIO_AFR_SDRAM);
    setMcuGpioAltfunc(GPIOE, 11, GPIO_AFR_SDRAM);
    setMcuGpioAltfunc(GPIOE, 12, GPIO_AFR_SDRAM);
    setMcuGpioAltfunc(GPIOE, 13, GPIO_AFR_SDRAM);
    setMcuGpioAltfunc(GPIOE, 14, GPIO_AFR_SDRAM);
    setMcuGpioAltfunc(GPIOE, 15, GPIO_AFR_SDRAM);
    setMcuGpioAltfunc(GPIOF, 0, GPIO_AFR_SDRAM);
    setMcuGpioAltfunc(GPIOF, 1, GPIO_AFR_SDRAM);
    setMcuGpioAltfunc(GPIOF, 2, GPIO_AFR_SDRAM);
    setMcuGpioAltfunc(GPIOF, 3, GPIO_AFR_SDRAM);
    setMcuGpioAltfunc(GPIOF, 4, GPIO_AFR_SDRAM);
    setMcuGpioAltfunc(GPIOF, 5, GPIO_AFR_SDRAM);
    setMcuGpioAltfunc(GPIOF, 11, GPIO_AFR_SDRAM);
    setMcuGpioAltfunc(GPIOF, 12, GPIO_AFR_SDRAM);
    setMcuGpioAltfunc(GPIOF, 13, GPIO_AFR_SDRAM);
    setMcuGpioAltfunc(GPIOF, 14, GPIO_AFR_SDRAM);
    setMcuGpioAltfunc(GPIOF, 15, GPIO_AFR_SDRAM);
    setMcuGpioAltfunc(GPIOG, 0, GPIO_AFR_SDRAM);
    setMcuGpioAltfunc(GPIOG, 1, GPIO_AFR_SDRAM);
    setMcuGpioAltfunc(GPIOG, 4, GPIO_AFR_SDRAM);
    setMcuGpioAltfunc(GPIOG, 5, GPIO_AFR_SDRAM);
    setMcuGpioAltfunc(GPIOG, 8, GPIO_AFR_SDRAM);
    setMcuGpioAltfunc(GPIOG, 15, GPIO_AFR_SDRAM);

    setMcuGpioOspeed(GPIOB, 5, GPIO_SPEED_FAST);
    setMcuGpioOspeed(GPIOB, 6, GPIO_SPEED_FAST);
    setMcuGpioOspeed(GPIOC, 0, GPIO_SPEED_FAST);
    setMcuGpioOspeed(GPIOD, 0, GPIO_SPEED_FAST);
    setMcuGpioOspeed(GPIOD, 1, GPIO_SPEED_FAST);
    setMcuGpioOspeed(GPIOD, 8, GPIO_SPEED_FAST);
    setMcuGpioOspeed(GPIOD, 9, GPIO_SPEED_FAST);
    setMcuGpioOspeed(GPIOD, 10, GPIO_SPEED_FAST);
    setMcuGpioOspeed(GPIOD, 14, GPIO_SPEED_FAST);
    setMcuGpioOspeed(GPIOD, 15, GPIO_SPEED_FAST);
    setMcuGpioOspeed(GPIOE, 0, GPIO_SPEED_FAST);
    setMcuGpioOspeed(GPIOE, 1, GPIO_SPEED_FAST);
    setMcuGpioOspeed(GPIOE, 7, GPIO_SPEED_FAST);
    setMcuGpioOspeed(GPIOE, 8, GPIO_SPEED_FAST);
    setMcuGpioOspeed(GPIOE, 9, GPIO_SPEED_FAST);
    setMcuGpioOspeed(GPIOE, 10, GPIO_SPEED_FAST);
    setMcuGpioOspeed(GPIOE, 11, GPIO_SPEED_FAST);
    setMcuGpioOspeed(GPIOE, 12, GPIO_SPEED_FAST);
    setMcuGpioOspeed(GPIOE, 13, GPIO_SPEED_FAST);
    setMcuGpioOspeed(GPIOE, 14, GPIO_SPEED_FAST);
    setMcuGpioOspeed(GPIOE, 15, GPIO_SPEED_FAST);
    setMcuGpioOspeed(GPIOF, 0, GPIO_SPEED_FAST);
    setMcuGpioOspeed(GPIOF, 1, GPIO_SPEED_FAST);
    setMcuGpioOspeed(GPIOF, 2, GPIO_SPEED_FAST);
    setMcuGpioOspeed(GPIOF, 3, GPIO_SPEED_FAST);
    setMcuGpioOspeed(GPIOF, 4, GPIO_SPEED_FAST);
    setMcuGpioOspeed(GPIOF, 5, GPIO_SPEED_FAST);
    setMcuGpioOspeed(GPIOF, 11, GPIO_SPEED_FAST);
    setMcuGpioOspeed(GPIOF, 12, GPIO_SPEED_FAST);
    setMcuGpioOspeed(GPIOF, 13, GPIO_SPEED_FAST);
    setMcuGpioOspeed(GPIOF, 14, GPIO_SPEED_FAST);
    setMcuGpioOspeed(GPIOF, 15, GPIO_SPEED_FAST);
    setMcuGpioOspeed(GPIOG, 0, GPIO_SPEED_FAST);
    setMcuGpioOspeed(GPIOG, 1, GPIO_SPEED_FAST);
    setMcuGpioOspeed(GPIOG, 4, GPIO_SPEED_FAST);
    setMcuGpioOspeed(GPIOG, 5, GPIO_SPEED_FAST);
    setMcuGpioOspeed(GPIOG, 8, GPIO_SPEED_FAST);
    setMcuGpioOspeed(GPIOG, 15, GPIO_SPEED_FAST);

    // RCC FMC setup
    setMcuRccFmcEn(true);

    FmcSdramSdcr obj = {
                        FMC_SDRAM_COL_ADDR_8BIT,
                        FMC_SDRAM_ROW_ADDR_12BIT,
                        FMC_SDRAM_DBUS_WIDTH_16BIT,
                        FMC_SDRAM_INT_BANK_FOUR,
                        3,
                        false,
                        2,
                        false,
                        FMC_SDRAM_RPIPE_1_HCLK_DELAY,
						0
                    };
   
    // SDCR setup
    setMcuFmcSdramSdcr2(obj);
	
    // SDTR setup
    FMC_Bank5_6->SDTR[0] = 0x00105000;
    FMC_Bank5_6->SDTR[1] = 0x00010351;
//	setMcuFmcSdramTmrd(FMC_SDRAM_BANK2, 1);
//	setMcuFmcSdramTxsr(FMC_SDRAM_BANK2, 4);
//	setMcuFmcSdramTras(FMC_SDRAM_BANK2, 2);
//	setMcuFmcSdramTrc(FMC_SDRAM_BANK1, 4); // BANK2 Don't care
//	setMcuFmcSdramTwr(FMC_SDRAM_BANK2, 1);
//	setMcuFmcSdramTrp(FMC_SDRAM_BANK1, 1); // BANK2 Don't care
//	setMcuFmcSdramTrcd(FMC_SDRAM_BANK2, 1);

	waitMcuFmcSdramBusy();
   
    // Clock Configuration Enable
    setMcuFmcSdramCmd(0, 0, false, true, 1);

    for(volatile unsigned long i=0;i<1000000;i++);

    // All Bank Precharge command
    waitMcuFmcSdramBusy();
    setMcuFmcSdramCmd(0, 0, false, true, 2);

    // Auto-refresh command
    waitMcuFmcSdramBusy();
    setMcuFmcSdramCmd(0, 7, false, true, 3);

    // Load Mode Register
    waitMcuFmcSdramBusy();
    buf = FMC_SDRAM_SDCMR_BURST_LENGTH_1
        | FMC_SDRAM_SDCMR_BURST_TYPE_SEQUENTIAL
        | FMC_SDRAM_SDCMR_CAS_LATENCY_3
        | FMC_SDRAM_SDCMR_OPERATING_MODE_STANDARD
        | FMC_SDRAM_SDCMR_WRITEBURST_MODE_SINGLE;

    setMcuFmcSdramCmd(buf, 0, false, true, 4);

    // SDRTR setup
    setMcuFmcSdramRtr(1292);

    waitMcuFmcSdramBusy();
}


extern "C"
{
	void initSystem(void)
	{
		initClock();
		setMcuFlashDataCacheEn(true);
		setMcuFlashInstCacheEn(true);
		initSdram();
		initLtdc();
	}
}

