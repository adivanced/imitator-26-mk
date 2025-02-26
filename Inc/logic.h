#ifndef __LOGIC_H__
#define __LOGIC_H__

#include "keyboard.h"
#include "spinner.h"
#include "switch.h"
#include "disp.h"



//#define tick_fun HAL_GetTick
#define tick_fun xTaskGetTickCount


extern LTDC_HandleTypeDef  hLtdcHandler;
extern uint32_t ActiveLayer;

#define check_switch()\
			if(!sw_st){\
				system_state = 0;\
				system_angle = 180;\
				need_out = 1;\
			}\

#define check_brightness()\
			if(!just_changed_brightness){\
				just_changed_brightness = 1;\
				if(kbd_st & BUTTON_BRIGHTNESS){\
					if(cur_alpha == 2){\
						cur_alpha = 0;\
					}else{cur_alpha++;}\
					HAL_LTDC_SetAlpha(&hLtdcHandler, alpha_vals[cur_alpha], ActiveLayer);\
				}\
			}else{\
				just_changed_brightness = 0;\
			}\

#define check_data()\
			if(kbd_st & BUTTON_AIR_TEMPERATURE){\
				need_out = 1; \
				system_state = 10;\
			}else if(kbd_st & BUTTON_HORIZONTAL_WIND_SPEED){\
				need_out = 1;\
				system_state = 11;\
			}else if(kbd_st & BUTTON_HORIZONTAL_WIND_DIRECTION){\
				need_out = 1;\
				system_state = 12;\
			}else if(kbd_st & BUTTON_VERTICAL_WIND_SPEED){\
				need_out = 1;\
				system_state = 13;\
			}else if(kbd_st & BUTTON_AIR_HUMIDITY){\
				need_out = 1;\
				system_state = 14;\
			}else if(kbd_st & BUTTON_ATMOSPHERIC_PRESSURE){\
				need_out = 1;\
				system_state = 15;\
			}else if(kbd_st & BUTTON_OBJECT_TEMPERATURE){\
				need_out = 1;\
				system_state = 16;\
			}else if(kbd_st & BUTTON_VERTICAL_STABILITY){\
				need_out = 1;\
				system_state = 17;\
			}\


uint32_t cur_alpha = 2;
uint32_t alpha_vals[] = {75, 175, 255};
uint32_t just_changed_brightness = 0;

uint32_t system_state = 0;
// state 0 - initial, wait for switch
// state 1 - Проверка аппаратуры, Горит 1 секунду
// state 2 - Готовность аппаратуры, Горит 1 секунду
// state 3 - Готовность к тестированию - ожидание нажатия кнопки "ТЕСТ"
// state 4 - ТЕСТ с прогресс баром
// state 5 - ТРЕБУЕТСЯ КАЛИБРОВКА, ожидание нажатия кнопки "КАЛИБР"
// state 6 - КЛИБРОВКА с прогресс баром
// state 7 - ВВЕСТИ УГОЛ ОТКЛОНЕНИЯ - крутилка
// state 8 - ИЗМЕРЕНИЯ спрогресс баром
// state 9 - ДАННЫЕ ГОТОВЫ




//                       П     Р      О     В     Е     Р     К     А    _      А     П     П    А      Р     А     Т     У     Р     Ы    
char state1_string[] = {0xcf, 0xd0, 0xce, 0xc2, 0xc5, 0xd0, 0xca, 0xc0, 0xbf, 0xc0, 0xcf, 0xcf, 0xc0, 0xd0, 0xc0, 0xd2, 0xd3, 0xd0, 0xdb, 0x0};
//                       Г      О     Т     О     В     Н     О     С     Т     Ь     _     А     П     П    А      Р     А     Т     У     Р     Ы    
char state2_string[] = {0xc3, 0xce, 0xd2, 0xce, 0xc2, 0xcd, 0xce, 0xd1, 0xd2, 0xdc, 0xbf, 0xc0, 0xcf, 0xcf, 0xc0, 0xd0, 0xc0, 0xd2, 0xd3, 0xd0, 0xdb, 0x0};
//                       Г      О     Т     О     В     Н     О     С     Т     Ь     _     К     _     Т    Е      С    Т     И     Р     О     В     А     Н     И     Ю
char state3_string[] = {0xc3, 0xce, 0xd2, 0xce, 0xc2, 0xcd, 0xce, 0xd1, 0xd2, 0xdc, 0xbf, 0xca, 0xbf, 0xd2, 0xc5, 0xd1, 0xd2, 0xc8, 0xd0, 0xce, 0xc2, 0xc0, 0xcd, 0xc8, 0xde, 0x0};
//						 Т     Е     С     Т
char state4_string[] = {0xd2, 0xc5, 0xd1, 0xd2, 0x0};
//                       Т     Р     Е     Б     У     Е     Т     С     Я     _     К     А     Л     И     Б     Р     О     В     К     А
char state5_string[] = {0xd2, 0xd0, 0xc5, 0xc1, 0xd3, 0xc5, 0xd2, 0xd1, 0xdf, 0xbf, 0xca, 0xc0, 0xcb, 0xc8, 0xc1, 0xd0, 0xce, 0xc2, 0xca, 0xc0, 0x0};
//                       К     А     Л     И     Б     Р     О     В     К     А
char state6_string[] = {0xca, 0xc0, 0xcb, 0xc8, 0xc1, 0xd0, 0xce, 0xc2, 0xca, 0xc0, 0x0};
//                       В     В     Е     С     Т     И     _     У     Г     О     Л     _     О     Т     К     Л     О     Н     Е     Н     И     Я
char state7_string[] = {0xc2, 0xc2, 0xc5, 0xd1, 0xd2, 0xc8, 0xbf, 0xd3, 0xc3, 0xce, 0xcb, 0xbf, 0xce, 0xd2, 0xca, 0xcb, 0xce, 0xcd, 0xc5, 0xcd, 0xc8, 0xdf, 0x0};
//                       И     З     М     Е     Р     Е     Н     И     Я
char state8_string[] = {0xc8, 0xc7, 0xcc, 0xc5, 0xd0, 0xc5, 0xcd, 0xc8, 0xdf, 0x0};
//                       Д     А     Н     Н     Ы     Е     _     Г     О     Т     О     В     Ы
char state9_string[] = {0xc4, 0xc0, 0xcd, 0xcd, 0xdb, 0xc5, 0xbf, 0xc3, 0xce, 0xd2, 0xce, 0xc2, 0xdb, 0x0};
//                        Т     е     м     п     е     р     а     т     у     р     а     _     в     о     з     д     у     х     а
char state10_string[] = {0xd2, 0xe5, 0xec, 0xef, 0xe5, 0xf0, 0xe0, 0xf2, 0xf3, 0xf0, 0xe0, 0xbf, 0xe2, 0xee, 0xe7, 0xe4, 0xf3, 0xf5, 0xe0, 0x0};
//                        С     к     о     р     о     с     т     ь     _     г     о     р     и     з     о     н     т     а     л     ь     н     о     г     о     _     в     е     т     р     а 
char state11_string[] = {0xd1, 0xea, 0xee, 0xf0, 0xee, 0xf1, 0xf2, 0xfc, 0xbf, 0xe3, 0xee, 0xf0, 0xe8, 0xe7, 0xee, 0xed, 0xf2, 0xe0, 0xeb, 0xfc, 0xed, 0xee, 0xe3, 0xee, 0xbf, 0xe2, 0xe5, 0xf2, 0xf0, 0xe0, 0x00};
//                        Н     а     п     р     а     в     л     е     н     и     е     _     г     о     р     и     з     о     н     т     а     л     ь     н     о     г     о     _     в     е     т     р     а 
char state12_string[] = {0xcd, 0xe0, 0xef, 0xf0, 0xe0, 0xe2, 0xeb, 0xe5, 0xed, 0xe8, 0xe5, 0xbf, 0xe3, 0xee, 0xf0, 0xe8, 0xe7, 0xee, 0xed, 0xf2, 0xe0, 0xeb, 0xfc, 0xed, 0xee, 0xe3, 0xee, 0xbf, 0xe2, 0xe5, 0xf2, 0xf0, 0xe0, 0x00};
//                        С     к     о     р     о     с     т     ь     _     в     е     р     т     и     к     а     л     ь     н     о     г     о     _     в     е     т     р     а 
char state13_string[] = {0xd1, 0xea, 0xee, 0xf0, 0xee, 0xf1, 0xf2, 0xfc, 0xbf, 0xe2, 0xe5, 0xf0, 0xf2, 0xe8, 0xea, 0xe0, 0xeb, 0xfc, 0xed, 0xee, 0xe3, 0xee, 0xbf, 0xe2, 0xe5, 0xf2, 0xf0, 0xe0, 0x00};
//                        В     л     а     ж     н     о     с     т     ь     _     в     о     з     д     у     х     в
char state14_string[] = {0xc2, 0xeb, 0xe0, 0xe6, 0xed, 0xee, 0xf1, 0xf2, 0xfc, 0xbf, 0xe2, 0xee, 0xe7, 0xe4, 0xf3, 0xf5, 0xe0, 0x0};
//                        А     т     м     о     с     ф     е     р     н     о     е     _     д     а     в     л     е     н     и     е
char state15_string[] = {0xc0, 0xf2, 0xec, 0xee, 0xf1, 0xf4, 0xe5, 0xf0, 0xed, 0xee, 0xe5, 0xbf, 0xe4, 0xe0, 0xe2, 0xeb, 0xe5, 0xed, 0xe8, 0xe5, 0x0};
//                        Т     е     м     п     е     р     а     т     у     р     а     _     о     б     ъ     е     к     т     а
char state16_string[] = {0xd2, 0xe5, 0xec, 0xef, 0xe5, 0xf0, 0xe0, 0xf2, 0xf3, 0xf0, 0xe0, 0xbf, 0xee, 0xe1, 0xfa, 0xe5, 0xea, 0xf2, 0xe0, 0x0};
//                        С     т     е     п     е     н     ь     _     в     е     р     т     и     к     а     л     ь     н     о     й     _     у     с     т     о     й     ч     и     в     о     с     т     и
char state17_string[] = {0xd1, 0xf2, 0xe5, 0xef, 0xe5, 0xed, 0xfc, 0xbf, 0xe2, 0xe5, 0xf0, 0xf2, 0xe8, 0xea, 0xe0, 0xeb, 0xfc, 0xed, 0xee, 0xe9, 0xbf, 0xf3, 0xf1, 0xf2, 0xee, 0xe9, 0xf7, 0xe8, 0xe2, 0xee, 0xf1, 0xf2, 0xe8, 0x0};

//                          2     0     .     2     7     _     dgr   C
char state10_string_2[] = {0x32, 0x30, 0x2e, 0x32, 0x37, 0xbf, 0xb7, 0xd1, 0x0};
//                          0     .     2     5     _     M     /     C
char state11_string_2[] = {0x30, 0x2e, 0x32, 0x35, 0xbf, 0xcc, 0x2f, 0xd1, 0x0};
//                          3     0     3     .     4     2     _     г     р      а     д    .     
char state12_string_2[] = {0x33, 0x30, 0x33, 0x2e, 0x34, 0x32, 0xbf, 0xe3, 0xf0, 0xe0, 0xe4, 0x2e, 0x0};
//                          С     _     З     А     П     А     Д     А     -     С     Е     В     Е     Р     О     -     З     А     П     А     Д     А
char state12_string_3[] = {0xd1, 0xbf, 0xc7, 0xc0, 0xcf, 0xc0, 0xc4, 0xc0, 0x2d, 0xd1, 0xc5, 0xc2, 0xc5, 0xd0, 0xce, 0x2d, 0xc7, 0xc0, 0xcf, 0xc0, 0xc4, 0xc0, 0x0};
//                          н     а     _     В     О     С     Т     О     К     -     Ю     Г     О     -     В     О     С     Т     О     К
char state12_string_4[] = {0xed, 0xe0, 0xbf, 0xc2, 0xce, 0xd1, 0xd2, 0xce, 0xca, 0x2d, 0xde, 0xc3, 0xce, 0x2d, 0xc2, 0xce, 0xd1, 0xd2, 0xce, 0xca, 0x0};
//                          0     .     3     0     _     M     /     C
char state13_string_2[] = {0x30, 0x2e, 0x30, 0x33, 0xbf, 0xcc, 0x2f, 0xd1, 0x0};
//                          7     0     .     4     3     _     %
char state14_string_2[] = {0x37, 0x30, 0x2e, 0x34, 0x33, 0xbf, 0x25, 0x0};
//                          7     5     8     .     5     2     _     м     м     .     р     т     .     с     т
char state15_string_2[] = {0x37, 0x35, 0x38, 0x2e, 0x35, 0x32, 0xbf, 0xec, 0xec, 0x2e, 0xf0, 0xf2, 0x2e, 0xf1, 0xf2, 0x0};
//                          0     .     0     0     _     dgr   C 
char state16_string_2[] = {0x30, 0x2e, 0x30, 0x30, 0xbf, 0xb7, 0xd1, 0x0};
//                          Ш     Т     И     Л     Ь
char state17_string_2[] = {0xd8, 0xd2, 0xc8, 0xcb, 0xdc, 0x0};

uint32_t need_out = 1;


uint32_t state_progress = 0;
uint32_t mem_sp_st = 0; // memorized spinner position for diff
uint32_t system_angle = 180;

void print_fat_rectangle(){
	uint32_t x = 80;
	uint32_t y = 80;
	uint32_t width = 320;
	uint32_t height = 100;
	for(uint8_t i = 0; i < 6; i++){
		print_rectangle_empty(x, y, width, height, 0xFF00FFFF);
		x++;
		y++;
		width -= 2;
		height -= 2;
	}
}


void state_machine(){
	uint32_t kbd_st = keyboard_state;
	uint32_t sw_st = switch_state;
	uint32_t spb_st = spinner_button_state;
	uint32_t sp_st = spinner_position;


	static uint32_t state_time = 0;

	//char tststr[] = {0xc0 ,0x0};
	//tststr[0] += system_state;
	//print_string_scaled_y(115, 120, tststr, 0xFF00FFFF, 2);

	switch(system_state){
		case 0:{
			if(need_out){
				fill_screen(0xFF000000);
				need_out = 0;
			}

			if(sw_st){
				system_state = 1;
				need_out = 1;

				state_time = tick_fun();
			}
			break;
		}
		case 1:{
			if(need_out){
				fill_screen(0xFF000000);
				print_fat_rectangle();
				print_string_scaled_y(115, 120, state1_string, 0xFF00FFFF, 2);
				need_out = 0;
			}

			if(tick_fun() - state_time >= 1000){
				system_state = 2;
				need_out = 1;
				state_time = tick_fun();
			}

			check_brightness();
			check_switch();
			break;
		}
		case 2:{
			if(need_out){
				fill_screen(0xFF000000);
				print_fat_rectangle();
				print_string_scaled_y(115, 120, state2_string, 0xFF00FFFF, 2);
				need_out = 0;
			}


			if(tick_fun() - state_time >= 1000){
				system_state = 3;
				need_out = 1;

				state_time = 0;
			}

			check_brightness();
			check_switch();
			break;
		}
		case 3:{
			if(need_out){
				fill_screen(0xFF000000);
				print_fat_rectangle();
				print_string_scaled_y(90, 120, state3_string, 0xFF00FFFF, 2);
				need_out = 0;
			}

			if(kbd_st & BUTTON_TEST){
				state_progress = 0;
				state_time = 0;
				system_state = 4;
				need_out = 1;
			}

			check_brightness();
			check_switch();
			break;
		}
		case 4:{
			if(need_out){
				fill_screen(0xFF000000);
				print_fat_rectangle();
				print_string_scaled(185, 105, state4_string, 0xFF00FFFF, 2);
				print_rectangle_empty(100, 150, 280, 10, 0xFF00FFFF);
				need_out = 0;
			}
			if(!state_time){state_time = tick_fun();}else{
				if(tick_fun() - state_time >= 300){
					state_time = 0;
					state_progress += 10;
				}
			}
			if(state_progress){
				print_rectangle(100, 150, (280 / 10) * (state_progress/10), 10, 0xFF00FFFF);
			}

			if(state_progress == 100){
				state_progress = 0;
				state_time = 0;
				need_out = 1;
				system_state = 5;
			}

			check_brightness();
			check_switch();
			break;
		}
		case 5:{
			if(need_out){
				fill_screen(0xFF000000);
				print_fat_rectangle();
				print_string_scaled_y(120, 120, state5_string, 0xFF00FFFF, 2);
				need_out = 0;
			}

			if(kbd_st & BUTTON_CALIBRATION){
				system_state = 6;
				need_out = 1;
				state_time = 0;
				state_progress = 0;
			}

			check_brightness();
			check_switch();
			break;
		}
		case 6:{
			if(need_out){
				fill_screen(0xFF000000);
				print_fat_rectangle();
				print_string_scaled_y(180, 100, state6_string, 0xFF00FFFF, 2);
				print_rectangle_empty(100, 150, 280, 10, 0xFF00FFFF);
				need_out = 0;

			}

			if(!state_time){state_time = tick_fun();}else{
				if(tick_fun() - state_time >= 300){
					state_time = 0;
					state_progress += 10;
				}
			}
			if(state_progress){
				print_rectangle(100, 150, (280 / 10) * (state_progress/10), 10, 0xFF00FFFF);
			}

			if(state_progress == 100){
				state_progress = 0;
				state_time = 0;
				need_out = 1;
				system_state = 7;
			}			

			check_brightness();
			check_switch();
			break;
		}
		case 7:{
			if(need_out){
				fill_screen(0xFF000000);
				print_fat_rectangle();
				print_string_scaled_y(110, 90, state7_string, 0xFF00FFFF, 2);	
				print_number(180, 130, system_angle, 0xFF00FFFF, 2);
				need_out = 0;
			}


			if(!mem_sp_st){
				mem_sp_st = sp_st;
			}else{
				if(mem_sp_st > sp_st){
					if(((int32_t)(system_angle - (mem_sp_st - sp_st)*2)) >= 0){
						system_angle -= (mem_sp_st - sp_st)*2;
					}
					print_rectangle(180, 130, 100, 40, 0);
					print_number(180, 130, system_angle, 0xFF00FFFF, 2);
					mem_sp_st = 0;
				}else if(mem_sp_st < sp_st){
					if(system_angle + (sp_st - mem_sp_st)*2 <= 360){
						system_angle += (sp_st - mem_sp_st)*2;
					}
					print_rectangle(180, 130, 20, 20, 0);
					print_number(180, 130, system_angle, 0xFF00FFFF, 2);
					mem_sp_st = 0;
				}	
			}

			if(spb_st){
				mem_sp_st = 0;
				need_out = 1;
				system_state = 8;
			}

			check_brightness();
			check_switch();
			break;
		}
		case 8:{
			if(need_out){
				fill_screen(0xFF000000);
				print_fat_rectangle();
				print_string_scaled_y(180, 100, state8_string, 0xFF00FFFF, 2);
				print_rectangle_empty(100, 150, 280, 10, 0xFF00FFFF);
				need_out = 0;

			}

			if(!state_time){state_time = tick_fun();}else{
				if(tick_fun() - state_time >= 300){
					state_time = 0;
					state_progress += 10;
				}
			}
			if(state_progress){
				print_rectangle(100, 150, (280 / 10) * (state_progress/10), 10, 0xFF00FFFF);
			}

			if(state_progress == 100){
				state_progress = 0;
				state_time = 0;
				need_out = 1;
				system_state = 9;
			}			

			check_brightness();
			check_switch();
			break;
		}
		case 9:{
			if(need_out){
				fill_screen(0xFF000000);
				print_fat_rectangle();
				print_string_scaled_y(165, 105, state9_string, 0xFF00FFFF, 2);
				need_out = 0;
			}

			check_data();

			check_brightness();
			check_switch();
			break;
		}
		case 10:{
			if(need_out){
				fill_screen(0xFF000000);
				print_string(10, 40, state10_string, 0xFF00FFFF);
				print_string_scaled(10, 100, state10_string_2, 0xFF00FFFF, 3);
				need_out = 0;
			}

			check_data();
		
			check_brightness();
			check_switch();
			break;			
		}
		case 11:{
			if(need_out){
				fill_screen(0xFF000000);
				print_string(10, 40, state11_string, 0xFF00FFFF);
				print_string_scaled(10, 100, state11_string_2, 0xFF00FFFF, 3);
				need_out = 0;
			}			

			check_data();
		
			check_brightness();
			check_switch();
			break;			
		}
		case 12:{
			if(need_out){
				fill_screen(0xFF000000);
				print_string(10, 40, state12_string, 0xFF00FFFF);
				print_string_scaled(10, 100, state12_string_2, 0xFF00FFFF, 3);
				print_string_scaled_y(10, 145, state12_string_3, 0xFF00FFFF, 2);
				print_string_scaled_y(50, 180, state12_string_4, 0xFF00FFFF, 2);

				need_out = 0;
			}

			check_data();
		
			check_brightness();
			check_switch();
			break;			
		}
		case 13:{
			if(need_out){
				fill_screen(0xFF000000);
				print_string(10, 40, state13_string, 0xFF00FFFF);
				print_string_scaled(10, 100, state13_string_2, 0xFF00FFFF, 3);
				need_out = 0;
			}

			check_data();
		
			check_brightness();
			check_switch();
			break;			
		}
		case 14:{
			if(need_out){
				fill_screen(0xFF000000);
				print_string(10, 40, state14_string, 0xFF00FFFF);
				print_string_scaled(10, 100, state14_string_2, 0xFF00FFFF, 3);
				need_out = 0;
			}

			check_data();
		
			check_brightness();
			check_switch();
			break;			
		}
		case 15:{
			if(need_out){
				fill_screen(0xFF000000);
				print_string(10, 40, state15_string, 0xFF00FFFF);
				print_string_scaled(10, 100, state15_string_2, 0xFF00FFFF, 2);
				need_out = 0;
			}

			check_data();
		
			check_brightness();
			check_switch();
			break;			
		}
		case 16:{
			if(need_out){
				fill_screen(0xFF000000);
				print_string(10, 40, state16_string, 0xFF00FFFF);
				print_string_scaled(10, 100, state16_string_2, 0xFF00FFFF, 3);
				need_out = 0;
			}

			check_data();
		
			check_brightness();
			check_switch();
			break;			
		}
		case 17:{
			if(need_out){
				fill_screen(0xFF000000);
				print_string(10, 40, state17_string, 0xFF00FFFF);
				print_string_scaled(10, 100, state17_string_2, 0xFF00FFFF, 3);
				need_out = 0;
			}

			check_data();
		
			check_brightness();
			check_switch();
			break;			
		}																				
	}
}



#endif