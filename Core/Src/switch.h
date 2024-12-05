#ifndef __SWITCH_H__
#define __SWITCH_H__

// SWITCH PORTS:
// IN: F10 (PULLUP)

uint32_t switch_state = 0;

void switch_GPIO_init(){
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	/*Configure GPIO pin : PF10 */
	GPIO_InitStruct.Pin = GPIO_PIN_10;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);
}

void get_current_switch_state(){
	GPIO_PinState val = HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_10);
	if(val == GPIO_PIN_SET){
		switch_state = 0;
	}else{
		switch_state = 1;
	}
}

#endif