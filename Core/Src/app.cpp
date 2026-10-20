#include "app.h"
#include "main.h"

int i = 0, j = 0;


void DAC_LED_Fade(void){
	for (i = 0; i <= 4095; i+=8) {
		HAL_DAC_SetValue(&hdac1, DAC_CHANNEL_1, DAC_ALIGN_12B_R, i);
		HAL_Delay(5);
	}
	for (j = 4095; j > 0; j-=8) {
		HAL_DAC_SetValue(&hdac1, DAC_CHANNEL_1, DAC_ALIGN_12B_R, j);
		HAL_Delay(5);
	}

}

void App_Init(void)
{
	HAL_DAC_Start(&hdac1, DAC_CHANNEL_1);
}

void App_Run(void)
{
	DAC_LED_Fade();
}
