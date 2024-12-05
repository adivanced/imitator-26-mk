#ifndef __SPINNER_H__
#define __SPINNER_H__

// SPINNER PORTS:
// CHANNEL IN: PC6 PC7
// (button)IN: PF8

#define SPINNER_COUNT_BOUNDRY 40

uint32_t spinner_button_state = 0;
uint32_t spinner_button_count = 0;
uint32_t spinner_position = 10000;
uint32_t spinner_stage = 0;

uint32_t pluscnt = 0;
uint32_t minuscnt = 0;


void spinner_GPIO_init(){
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	/*Configure GPIO pins : PF8 */
	GPIO_InitStruct.Pin = GPIO_PIN_8;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

	/*Configure GPIO pins : PC7 PC6 */
	GPIO_InitStruct.Pin = GPIO_PIN_6;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = GPIO_PIN_7;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);	
}

void get_current_spinner_button_state(){
	GPIO_PinState val = HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_8);
	if(val == GPIO_PIN_RESET){
		if(spinner_button_count < SPINNER_COUNT_BOUNDRY+SPINNER_COUNT_BOUNDRY/2){
				spinner_button_count++;
		}
	}else{
		if(spinner_button_count >= 3){
			spinner_button_count-=3;
		}
	}
	if(spinner_button_count >= SPINNER_COUNT_BOUNDRY){
		spinner_button_state=1;
	}else{
		spinner_button_state=0;
	}
}


void get_spinner_position_change(){
	switch(spinner_stage){
		case 0:{
			if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_7) == GPIO_PIN_RESET){
				if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_6) == GPIO_PIN_RESET){
					spinner_stage = 1;
				}else{
					spinner_stage = 3;
				}
			}
			break;
		}
		case 1:{
			if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_6) == GPIO_PIN_SET){
				//if(spinner_position){
					//spinner_position--;
				minuscnt++;
				pluscnt=0;
				if(minuscnt >= 4){
					spinner_position--;
					minuscnt=0;
				}
				//}
				spinner_stage = 2;
			}
			break;			
		}
		case 2:{
			if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_7) == GPIO_PIN_SET){
				spinner_stage = 0;
			}
			break;			
		}
		case 3:{
			if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_6) == GPIO_PIN_RESET){
				//if(spinner_position < 1000){
					//spinner_position++;
				pluscnt++;
				minuscnt=0;
				if(pluscnt>=2){
					spinner_position++;
					pluscnt=0;
				}
				//}				
				spinner_stage = 4;
			}
			break;			
		}
		case 4:{
			if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_7) == GPIO_PIN_SET){
				spinner_stage = 5;
			}
			break;
		}
		case 5:{
			if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_6) == GPIO_PIN_SET){
				spinner_stage = 0;
			}
			break;
		}
	}
}



#endif