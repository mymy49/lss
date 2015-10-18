#include <stm32f429.h>

void setMcuLtdcFrameBuffer(void* fb)
{
	setMcuLtdcLayerFrameBuffer(LTDC_Layer1, (unsigned long)fb);
	setMcuLtdcImediateReload();
}

