#ifndef __DISP_H__
#define __DISP_H__

#include "font.h"
#include <string.h>

#define SCRWIDTH 480
#define SCRHEIGHT 272

extern LTDC_HandleTypeDef  hLtdcHandler;
extern uint32_t ActiveLayer;


#define framebuf ((uint16_t*)(hLtdcHandler.LayerCfg[ActiveLayer].FBStartAdress))
//uint16_t* framebuf[SCRWIDTH*SCRHEIGHT] = {0};


void print_square(uint32_t x, uint32_t y, uint32_t l, uint32_t color){
	for(uint32_t i = y; i < y+l; i++){
		for(uint32_t j = x; j < x+l; j++){
			//framebuf[i * SCRWIDTH + j] = color;
			BSP_LCD_DrawPixel(j, i, color);
		}
	}
}

void print_square_empty(uint32_t x, uint32_t y, uint32_t l, uint32_t color){
	for(uint32_t i = y; i < y+l; i++){
		for(uint32_t j = x; j < x+l; j++){
			if(i != y && i != y+l-1){
				BSP_LCD_DrawPixel(x, i, color);
				BSP_LCD_DrawPixel(x+1-1, i, color);
				//framebuf[i*SCRWIDTH+x] = color;
				//framebuf[i*SCRWIDTH+x+l-1] = color;
				break;
			}
			//framebuf[i * SCRWIDTH + j] = color;
			BSP_LCD_DrawPixel(j, i, color);
		}
	}
}

void print_rectangle(uint32_t x, uint32_t y, uint32_t w, uint32_t h, uint32_t color){
	for(uint32_t i = y; i < y+h; i++){
		for(uint32_t j = x; j < x+w; j++){
			//framebuf[i*SCRWIDTH+j] = color;
			BSP_LCD_DrawPixel(j, i, color);
		}
	}
}

void print_rectangle_empty(uint32_t x, uint32_t y, uint32_t w, uint32_t h, uint32_t color){
	for(uint32_t i = y; i < y+h; i++){
		for(uint32_t j = x; j < x+w; j++){
			if(i != y && i != y+h-1){
				//framebuf[i*SCRWIDTH+x] = color;
				//framebuf[i*SCRWIDTH+x+w-1] = color;
				BSP_LCD_DrawPixel(x, i, color);
				BSP_LCD_DrawPixel(x+w-1, i, color);
				break;
			}
			//framebuf[i*SCRWIDTH+j] = color;
			BSP_LCD_DrawPixel(j, i, color);
		}
	}
}


void print_char(uint32_t x, uint32_t y, uint8_t index, uint32_t color){
	uint8_t* sym = Font_12x16_Data+index*24;//get_char_data_addr(ch);

	uint32_t xiter = x;
	for(uint8_t* fptr = sym; fptr < sym + 12; fptr++){
		uint32_t yiter = y;
		uint8_t mask = 0b00000001;
		for(uint32_t i = 0; i < 8; i++){
			if(*fptr & mask){
				//framebuf[yiter * SCRWIDTH + xiter] = color;
				BSP_LCD_DrawPixel(xiter, yiter, color);
			}else{
				//framebuf[yiter * SCRWIDTH + xiter] = 0;
				BSP_LCD_DrawPixel(xiter, yiter, 0xFF000000);
			}
			mask = mask << 1;
			yiter++;
		}
		xiter++;
	}
	xiter = x;
	for(uint8_t* fptr = sym+12; fptr < sym+24; fptr++){
		uint32_t yiter = y+8;
		uint8_t mask = 0b00000001;
		for(uint32_t i = 0; i < 8; i++){
			if(*fptr & mask){
				//framebuf[yiter * 480 + xiter] = color;
				BSP_LCD_DrawPixel(xiter, yiter, color);
			}else{
				//framebuf[yiter * SCRWIDTH + xiter] = 0;
				BSP_LCD_DrawPixel(xiter, yiter, 0xFF000000);
			}
			mask = mask << 1;
			yiter++;
		}
		xiter++;
	}

}


void print_char_scaled(uint32_t x, uint32_t y, uint8_t index, uint32_t color, uint32_t scale){
	uint8_t* sym = Font_12x16_Data+index*24;//get_char_data_addr(ch);

	uint32_t xiter = x;
	for(uint8_t* fptr = sym; fptr < sym + 12; fptr++){
		uint32_t yiter = y;
		uint8_t mask = 0b00000001;
		for(uint32_t i = 0; i < 8; i++){
			if(*fptr & mask){
				for(uint32_t iy = yiter; iy < yiter+scale; iy++){
					for(uint32_t ix = xiter; ix < xiter+scale; ix++){
						//framebuf[iy * SCRWIDTH + ix] = color;	
						BSP_LCD_DrawPixel(ix, iy, color);
					}
				}
				
			}else{
				for(uint32_t iy = yiter; iy < yiter+scale; iy++){
					for(uint32_t ix = xiter; ix < xiter+scale; ix++){
						//framebuf[iy * SCRWIDTH + ix] = 0;
						BSP_LCD_DrawPixel(ix, iy, 0xFF000000);
					}
				}
			}
			mask = mask << 1;
			yiter+=scale;
		}
		xiter+=scale;
	}
	xiter = x;
	for(uint8_t* fptr = sym+12; fptr < sym+24; fptr++){
		uint32_t yiter = y+8*scale;
		uint8_t mask = 0b00000001;
		for(uint32_t i = 0; i < 8; i++){
			if(*fptr & mask){
				for(uint32_t iy = yiter; iy < yiter+scale; iy++){
					for(uint32_t ix = xiter; ix < xiter+scale; ix++){
						//framebuf[iy * SCRWIDTH + ix] = color;	
						BSP_LCD_DrawPixel(ix, iy, color);
					}
				}
			}else{
				for(uint32_t iy = yiter; iy < yiter+scale; iy++){
					for(uint32_t ix = xiter; ix < xiter+scale; ix++){
						//framebuf[iy * SCRWIDTH + ix] = 0;
						BSP_LCD_DrawPixel(ix, iy, 0xFF000000);
					}
				}
			}
			mask = mask << 1;
			yiter+=scale;
		}
		xiter+=scale;
	}
}


void print_char_scaled_y(uint32_t x, uint32_t y, uint8_t index, uint32_t color, uint32_t scale){
	uint8_t* sym = Font_12x16_Data+index*24;//get_char_data_addr(ch);

	uint32_t xiter = x;
	for(uint8_t* fptr = sym; fptr < sym + 12; fptr++){
		uint32_t yiter = y;
		uint8_t mask = 0b00000001;
		for(uint32_t i = 0; i < 8; i++){
			if(*fptr & mask){
				for(uint32_t iy = yiter; iy < yiter+scale; iy++){
					//framebuf[iy * SCRWIDTH + xiter] = color;	
					BSP_LCD_DrawPixel(xiter, iy, color);
				}
				
			}else{
				for(uint32_t iy = yiter; iy < yiter+scale; iy++){
					//framebuf[iy * SCRWIDTH + xiter] = 0;
					BSP_LCD_DrawPixel(xiter, iy, 0xFF000000);
				}
			}
			mask = mask << 1;
			yiter+=scale;
		}
		xiter++;
	}
	xiter = x;
	for(uint8_t* fptr = sym+12; fptr < sym+24; fptr++){
		uint32_t yiter = y+8*scale;
		uint8_t mask = 0b00000001;
		for(uint32_t i = 0; i < 8; i++){
			if(*fptr & mask){
				for(uint32_t iy = yiter; iy < yiter+scale; iy++){
					//framebuf[iy * SCRWIDTH + xiter] = color;	
					BSP_LCD_DrawPixel(xiter, iy, color);
				}
			}else{
				for(uint32_t iy = yiter; iy < yiter+scale; iy++){
					//framebuf[iy * SCRWIDTH + xiter] = 0;
					BSP_LCD_DrawPixel(xiter, iy, 0xFF000000);
				}
			}
			mask = mask << 1;
			yiter+=scale;
		}
		xiter++;
	}
}

// . . . . .     . . . . . .    . . . . .
// 0 0 0 0 0     1 1 1 1 0 0    1 0 1 1 1    
// ARGB - 0xFF00FFFF


void print_string(uint32_t x, uint32_t y, char* string, uint32_t color){
	uint32_t len = strlen(string);
	for(char* i = string; i < string+len; i++){
		print_char(x, y, *i, color);
		x += 12;
		//y += 16;
	}
}

void print_string_scaled(uint32_t x, uint32_t y, char* string, uint32_t color, uint32_t scale){
	uint32_t len = strlen(string);
	for(char* i = string; i < string+len; i++){
		print_char_scaled(x, y, *i, color, scale);
		x += 12*scale;
		//y += 16*scale;
	}
}

void print_string_scaled_y(uint32_t x, uint32_t y, char* string, uint32_t color, uint32_t scale){
	uint32_t len = strlen(string);
	for(char* i = string; i < string+len; i++){
		print_char_scaled_y(x, y, *i, color, scale);
		x += 12;
		//y += 16*scale;
	}
}

// 51
// 43
// 480
// 8
//
// 16
// 12
// 272
// 4

void fill_screen(uint32_t color){
	//for(uint16_t* i = framebuf; i < framebuf+SCRWIDTH*SCRHEIGHT; i++){
	//	*i = color;
	//}
	print_rectangle(0, 0, SCRWIDTH, SCRHEIGHT, color);
}


void print_number(uint32_t x, uint32_t y, uint32_t number, uint32_t color, uint32_t scale){
	if(!number){
		print_char_scaled(x+scale * 12, y, number % 10 + 0x30, color, scale);
	}

	uint32_t numlen = 0;
	uint32_t num_cp = number;
	while(num_cp){
		numlen++;
		num_cp /= 10;
	}

	x += numlen * scale * 12;
	while(number){
		print_char_scaled(x, y, number % 10 + 0x30, color, scale);
		x -= scale * 12;
		number /= 10;
	}
}


#endif