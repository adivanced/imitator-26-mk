#ifndef INC_MODBUS_H_
#define INC_MODBUS_H_
#include "inttypes.h"
#include "string.h"


// assume 16 coils - 12 buttons, switch and a 2-channel+button spinner
// then:
// coil 0 - test btn
// coil 1 - air temp btn
// coil 2 - air humid btn
// coil 3 - calibr btn
// coil 4 - speed hor wind btn
// coil 5 - atm pressure btn
// coil 6 - brightness btn
// coil 7 - dir hor wind btn
// coil 8 - obj temp btn
// coil 9 - measure btn
// coil 10 - speed vert wind btn
// coil 11 - stable vert smth btn 	
// 
// coil 12 - switch 								PF10
//
// coil 13 - spinner channel A 						PC7 
// coil 14 - spinner btn 							PF8
// coil 15 - spinner channel B 						PC6


uint8_t get_coil_val(int coil){
	if(coil <= 11){
		uint16_t val = keyboard_state;
		val = val >> coil;
		val &= 1;
		return (uint8_t)val;
	}else if(coil == 12){
		return (uint8_t)switch_state;
	}else if(coil == 13){
		return (uint8_t)HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_7);
	}else if(coil == 14){
		return (uint8_t)spinner_button_state;
	}else if(coil == 15){
		return (uint8_t)HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_6);
	}else{
		return 0;
	}
}


uint16_t get_holding_reg_val(){
	return keyboard_state | (switch_state << 12) | (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_7) << 13) | (spinner_button_state << 14) | (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_6) << 15);
}




// ---------COMMANDS------------------------------//
#define MB_FN_READ_COILS			(0x01)
#define MB_FN_READ_DISCRETE		(0x02)
#define MB_FN_READ_HOLDING		(0x03)
#define MB_FN_READ_INPUT			(0x04)
#define MB_FN_WRITE_S_COIL		(0x05)
#define MB_FN_WRITE_S_HOLDING	(0x06)
#define MB_FN_WRITE_M_COIL		(0x0F)
#define MB_FN_WRITE_M_HOLDING	(0x10)
//---------EXCEPTION CODES------------------------//
#define MB_EXCEPTION_OK							(0x00)
#define MB_EXCEPTION_FN_UNSUPPORTED (0x01)
#define MB_EXCEPTION_DATA_ADDR			(0x02)
#define MB_EXCEPTION_DATA_VAL				(0x03)
//---------MB TCP RELATED------------------------//
#define MB_MBAP_TRANSACTION_ID_H	(0)
#define MB_MBAP_TRANSACTION_ID_L	(1)
#define MB_MBAP_PROTOCOL_ID_H 		(2)
#define MB_MBAP_PROTOCOL_ID_L 		(3)
#define MB_MBAP_LEN_H 						(4)
#define MB_MBAP_LEN_L 						(5)
#define MB_MBAP_CLIENT_ID 				(6)
#define MB_MBAP_SIZE 							(7)
#define MB_TCP_PORT 							(502)
#define MB_MBAP_END								(MB_MBAP_CLIENT_ID)

#define MB_PDU_MAXSIZE (253)
// -------------------------- CONFIG START-------------------------------//
#define MB_ADU_MAXSIZE	(MB_PDU_MAXSIZE + MB_MBAP_SIZE)
#define MB_PDU_START		(MB_MBAP_END+1)

#define MB_COILS_ST			(0)
#define MB_COILS_Q			(0xFF)
#define MB_DISCRETE_ST	(MB_COILS_ST + MB_COILS_Q)
#define MB_DISCRETE_Q		(0)
#define MB_HOLDING_ST 	(MB_DISCRETE_ST + MB_DISCRETE_Q)
#define MB_HOLDING_Q		(4)
#define MB_INPUT_ST			(MB_HOLDING_ST + MB_HOLDING_Q)
#define MB_INPUT_Q			(0)
#define MB_MEMORY_SIZE	(MB_COILS_Q + MB_DISCRETE_Q + MB_HOLDING_Q + MB_INPUT_Q)
// -------------------------- CONFIG END-------------------------------//

//---------BYTE POSITIONS IN PDU------------------------//
#define MB_PDU_FN									(MB_PDU_START)
#define MB_PDU_R_ST_ADDR_H				(MB_PDU_START + 1)
#define MB_PDU_R_ST_ADDR_L				(MB_PDU_START + 2)
#define MB_PDU_R_QUANTITY_H				(MB_PDU_START + 3)
#define MB_PDU_R_QUANTITY_L				(MB_PDU_START + 4)

#define MB_PDU_W_REG_ADDR_H				(MB_PDU_START + 1)
#define MB_PDU_W_REG_ADDR_L				(MB_PDU_START + 2)
#define MB_PDU_W_REG_VAL_H				(MB_PDU_START + 3)
#define MB_PDU_W_REG_VAL_L				(MB_PDU_START + 4)

#define MB_PDU_EXCEPTION_CODE			(MB_PDU_START + 1)
#define MB_PDU_REPL_N							(MB_PDU_START + 1)

// process request and returns ADU size of reply
uint16_t mb_process(char *mb_repl_buf, char *mb_req_buf, uint16_t req_buf_len);


typedef enum {
	BROADCAST_FUNC = 0,
	MB_READ_COILS_FUNC = 1,
	MB_READ_HOLDING_REGISTERS_FUNC = 3,
	MB_WRITE_MULTIPLE_REGISTERS_FUNC = 16,
	MB_WRITE_IMAGE_FUNC = 100
} MB_FUNC;

static void mb_mbap_copy(char *mb_repl_buf, char *mb_req_buf);


static void mb_mbap_copy(char *mb_repl_buf, char *mb_req_buf) {
	mb_repl_buf[MB_MBAP_TRANSACTION_ID_H] = mb_req_buf[MB_MBAP_TRANSACTION_ID_H];
	mb_repl_buf[MB_MBAP_TRANSACTION_ID_L] = mb_req_buf[MB_MBAP_TRANSACTION_ID_L];
	mb_repl_buf[MB_MBAP_PROTOCOL_ID_H] = mb_req_buf[MB_MBAP_PROTOCOL_ID_H];
	mb_repl_buf[MB_MBAP_PROTOCOL_ID_L] = mb_req_buf[MB_MBAP_PROTOCOL_ID_L];
	mb_repl_buf[MB_MBAP_CLIENT_ID] = mb_req_buf[MB_MBAP_CLIENT_ID];
}


// 01 03 01 00 00 01 85 f6


uint16_t nmbs_crc_calc(const uint8_t* data, uint32_t length) {
    uint16_t crc = 0xFFFF;
    for (uint32_t i = 0; i < length; i++) {
        crc ^= (uint16_t) data[i];
        for (int j = 8; j != 0; j--) {
            if ((crc & 0x0001) != 0) {
                crc >>= 1;
                crc ^= 0xA001;
            }
            else
                crc >>= 1;
        }
    }

    return (uint16_t) (crc << 8) | (uint16_t) (crc >> 8);	
}	


uint16_t mb_process(char* mb_repl_buf, char* mb_req_buf, uint16_t req_buf_len){
	memset(mb_repl_buf, '\0', MB_ADU_MAXSIZE);
	char* MB_BUFFER = mb_repl_buf + 7;

	switch(mb_req_buf[1]){
		case 3:{
			MB_BUFFER[0] = 1;
			MB_BUFFER[1] = 3;
			MB_BUFFER[2] = 2;

			uint16_t val = get_holding_reg_val();
			MB_BUFFER[3] = (uint8_t)(val>>8);
			MB_BUFFER[4] = (uint8_t)(val);

			uint16_t crc_answer = nmbs_crc_calc(MB_BUFFER, 3 + 2);

			MB_BUFFER[5] = crc_answer >> 8;
			MB_BUFFER[6] = crc_answer;

			return 7;

		}
		default:{
			return 0;
		}
	}	
}


// uint16_t mb_process(char* mb_repl_buf, char* mb_req_buf, uint16_t req_buf_len){
// 	memset(mb_repl_buf, '\0', MB_ADU_MAXSIZE);
// 	mb_mbap_copy(mb_repl_buf, mb_req_buf);

// 	char* MB_BUFFER = mb_repl_buf + 7;

// 	switch(mb_req_buf[1]){
// 		case 3:{
// 			MB_BUFFER[0] = 1;
// 			MB_BUFFER[1] = 3;
// 			MB_BUFFER[2] = 2;

// 			uint16_t val = get_holding_reg_val();
// 			MB_BUFFER[3] = (uint8_t)(val>>8);
// 			MB_BUFFER[4] = (uint8_t)(val);

// 			uint16_t crc_answer = nmbs_crc_calc(MB_BUFFER, 3 + 2);

// 			MB_BUFFER[5] = crc_answer >> 8;
// 			MB_BUFFER[6] = crc_answer;

// 			return 7 + 7;

// 		}
// 		default:{
// 			return 0;
// 		}
// 	}
// }



#endif /* INC_MODBUS_H_ */
