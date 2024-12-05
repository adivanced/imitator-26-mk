#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__

// KEYBOARD PORTS: 
// ROWS(OUT): G6 B4 G7 I0  }
// COLUMNS(IN): H6 I3 I2   }=> PULLDOWN all


#define BUTTON_TEST 						(1 << 0)
#define BUTTON_AIR_TEMPERATURE 				(1 << 1)
#define BUTTON_AIR_HUMIDITY 				(1 << 2)
#define BUTTON_CALIBRATION 					(1 << 3)
#define BUTTON_HORIZONTAL_WIND_SPEED 		(1 << 4)
#define BUTTON_ATMOSPHERIC_PRESSURE 		(1 << 5)
#define BUTTON_BRIGHTNESS 					(1 << 6)
#define BUTTON_HORIZONTAL_WIND_DIRECTION 	(1 << 7)
#define BUTTON_OBJECT_TEMPERATURE 			(1 << 8)
#define BUTTON_MEASURE 						(1 << 9)
#define BUTTON_VERTICAL_WIND_SPEED 			(1 << 10)
#define BUTTON_VERTICAL_STABILITY 			(1 << 11)

#define KEY_COUNT_BOUNDRY 15

uint32_t key_count[4][3] = {0};
uint32_t stage = 0;
uint16_t keyboard_state = 0;


void keyboard_GPIO_init(){
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7|GPIO_PIN_6, GPIO_PIN_RESET);

	/*Configure GPIO pin : PB4 */
	GPIO_InitStruct.Pin = GPIO_PIN_4;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	/*Configure GPIO pins : PI3 PI2 */
	GPIO_InitStruct.Pin = GPIO_PIN_3|GPIO_PIN_2;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	HAL_GPIO_Init(GPIOI, &GPIO_InitStruct);

	/*Configure GPIO pins : PI0 */
	GPIO_InitStruct.Pin = GPIO_PIN_0;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOI, &GPIO_InitStruct);

	/*Configure GPIO pins : PG7 PG6 */
	GPIO_InitStruct.Pin = GPIO_PIN_7|GPIO_PIN_6;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

	/*Configure GPIO pin : PH6 */
	GPIO_InitStruct.Pin = GPIO_PIN_6;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	HAL_GPIO_Init(GPIOH, &GPIO_InitStruct);
}

void get_current_keyboard_state(){
	stage = (stage+1)%8;
	switch(stage){
		case 0:{
			HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);			
			HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOG, GPIO_PIN_6, GPIO_PIN_SET);
			break;
		}
		case 1:{
			if(HAL_GPIO_ReadPin(GPIOH, GPIO_PIN_6) == GPIO_PIN_SET){if(key_count[0][0]<KEY_COUNT_BOUNDRY+KEY_COUNT_BOUNDRY/2){key_count[0][0]++;}}else{if(key_count[0][0]){key_count[0][0]--;}}
			if(HAL_GPIO_ReadPin(GPIOI, GPIO_PIN_3) == GPIO_PIN_SET){if(key_count[0][1]<KEY_COUNT_BOUNDRY+KEY_COUNT_BOUNDRY/2){key_count[0][1]++;}}else{if(key_count[0][1]){key_count[0][1]--;}}
			if(HAL_GPIO_ReadPin(GPIOI, GPIO_PIN_2) == GPIO_PIN_SET){if(key_count[0][2]<KEY_COUNT_BOUNDRY+KEY_COUNT_BOUNDRY/2){key_count[0][2]++;}}else{if(key_count[0][2]){key_count[0][2]--;}}

			if(key_count[0][0] >= KEY_COUNT_BOUNDRY){keyboard_state|=BUTTON_TEST;}else{keyboard_state&=~BUTTON_TEST;}
			if(key_count[0][1] >= KEY_COUNT_BOUNDRY){keyboard_state|=BUTTON_AIR_TEMPERATURE;}else{keyboard_state&=~BUTTON_AIR_TEMPERATURE;}
			if(key_count[0][2] >= KEY_COUNT_BOUNDRY){keyboard_state|=BUTTON_AIR_HUMIDITY;}else{keyboard_state&=~BUTTON_AIR_HUMIDITY;}
			break;
		}
		case 2:{	
			HAL_GPIO_WritePin(GPIOG, GPIO_PIN_6, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_RESET);	
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET);			
			break;
		}
		case 3:{
			if(HAL_GPIO_ReadPin(GPIOH, GPIO_PIN_6) == GPIO_PIN_SET){if(key_count[1][0]<KEY_COUNT_BOUNDRY+KEY_COUNT_BOUNDRY/2){key_count[1][0]++;}}else{if(key_count[1][0]){key_count[1][0]--;}}
			if(HAL_GPIO_ReadPin(GPIOI, GPIO_PIN_3) == GPIO_PIN_SET){if(key_count[1][1]<KEY_COUNT_BOUNDRY+KEY_COUNT_BOUNDRY/2){key_count[1][1]++;}}else{if(key_count[1][1]){key_count[1][1]--;}}
			if(HAL_GPIO_ReadPin(GPIOI, GPIO_PIN_2) == GPIO_PIN_SET){if(key_count[1][2]<KEY_COUNT_BOUNDRY+KEY_COUNT_BOUNDRY/2){key_count[1][2]++;}}else{if(key_count[1][2]){key_count[1][2]--;}}
	
			if(key_count[1][0] >= KEY_COUNT_BOUNDRY){keyboard_state|=BUTTON_CALIBRATION;}else{keyboard_state&=~BUTTON_CALIBRATION;}
			if(key_count[1][1] >= KEY_COUNT_BOUNDRY){keyboard_state|=BUTTON_HORIZONTAL_WIND_SPEED;}else{keyboard_state&=~BUTTON_HORIZONTAL_WIND_SPEED;}
			if(key_count[1][2] >= KEY_COUNT_BOUNDRY){keyboard_state|=BUTTON_ATMOSPHERIC_PRESSURE;}else{keyboard_state&=~BUTTON_ATMOSPHERIC_PRESSURE;}
			break;
		}
		case 4:{
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOG, GPIO_PIN_6, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_SET);			
			break;
		}
		case 5:{
			if(HAL_GPIO_ReadPin(GPIOH, GPIO_PIN_6) == GPIO_PIN_SET){if(key_count[2][0]<KEY_COUNT_BOUNDRY+KEY_COUNT_BOUNDRY/2){key_count[2][0]++;}}else{if(key_count[2][0]){key_count[2][0]--;}}
			if(HAL_GPIO_ReadPin(GPIOI, GPIO_PIN_3) == GPIO_PIN_SET){if(key_count[2][1]<KEY_COUNT_BOUNDRY+KEY_COUNT_BOUNDRY/2){key_count[2][1]++;}}else{if(key_count[2][1]){key_count[2][1]--;}}
			if(HAL_GPIO_ReadPin(GPIOI, GPIO_PIN_2) == GPIO_PIN_SET){if(key_count[2][2]<KEY_COUNT_BOUNDRY+KEY_COUNT_BOUNDRY/2){key_count[2][2]++;}}else{if(key_count[2][2]){key_count[2][2]--;}}

			if(key_count[2][0] >= KEY_COUNT_BOUNDRY){keyboard_state|=BUTTON_BRIGHTNESS;}else{keyboard_state&=~BUTTON_BRIGHTNESS;}
			if(key_count[2][1] >= KEY_COUNT_BOUNDRY){keyboard_state|=BUTTON_HORIZONTAL_WIND_DIRECTION;}else{keyboard_state&=~BUTTON_HORIZONTAL_WIND_DIRECTION;}
			if(key_count[2][2] >= KEY_COUNT_BOUNDRY){keyboard_state|=BUTTON_OBJECT_TEMPERATURE;}else{keyboard_state&=~BUTTON_OBJECT_TEMPERATURE;}
			break;
		}
		case 6:{
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOG, GPIO_PIN_6, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_SET);			
			break;
		}
		case 7:{
			if(HAL_GPIO_ReadPin(GPIOH, GPIO_PIN_6) == GPIO_PIN_SET){if(key_count[3][0]<KEY_COUNT_BOUNDRY+KEY_COUNT_BOUNDRY/2){key_count[3][0]++;}}else{if(key_count[3][0]){key_count[3][0]--;}}
			if(HAL_GPIO_ReadPin(GPIOI, GPIO_PIN_3) == GPIO_PIN_SET){if(key_count[3][1]<KEY_COUNT_BOUNDRY+KEY_COUNT_BOUNDRY/2){key_count[3][1]++;}}else{if(key_count[3][1]){key_count[3][1]--;}}
			if(HAL_GPIO_ReadPin(GPIOI, GPIO_PIN_2) == GPIO_PIN_SET){if(key_count[3][2]<KEY_COUNT_BOUNDRY+KEY_COUNT_BOUNDRY/2){key_count[3][2]++;}}else{if(key_count[3][2]){key_count[3][2]--;}}

			if(key_count[3][0] >= KEY_COUNT_BOUNDRY){keyboard_state|=BUTTON_MEASURE;}else{keyboard_state&=~BUTTON_MEASURE;}
			if(key_count[3][1] >= KEY_COUNT_BOUNDRY){keyboard_state|=BUTTON_VERTICAL_WIND_SPEED;}else{keyboard_state&=~BUTTON_VERTICAL_WIND_SPEED;}
			if(key_count[3][2] >= KEY_COUNT_BOUNDRY){keyboard_state|=BUTTON_VERTICAL_STABILITY;}else{keyboard_state&=~BUTTON_VERTICAL_STABILITY;}
			break;
		}

	}
}


#endif