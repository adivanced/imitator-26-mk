#include "lwip/opt.h"
#include "lwip/api.h"
#include "lwip/sys.h"
#include "modbus.h"

static struct netconn* conn;
static struct netconn* newconn;

static struct netbuf *netbuf;
char mb_req_buf[MB_ADU_MAXSIZE];
char mb_repl_buf[MB_ADU_MAXSIZE];

int tcp_ether_init(){
	conn = netconn_new(NETCONN_TCP);
	if(conn == NULL){return -1;}
	if(netconn_bind(conn, IP_ADDR_ANY, 502) == ERR_OK){
		netconn_listen(conn);
		for(;;){
			int stt = 228;
			if(netconn_accept(conn, &newconn) == ERR_OK){
				return 0;
			}
		}
	}else{
		return -2;
	}
}

int ether_state = 0;

void state_ether(){

	switch(ether_state){
		case 0:{
			if(netconn_recv(newconn, &netbuf) == ERR_OK){
				ether_state = 1;
			}
			break;
		}
		case 1:{
			for(uint32_t i = 0; i < netbuf->p->len; i++){mb_req_buf[i]=((char*)netbuf->p->payload)[i];} // get the message from the client
			uint16_t buf_len = netbuf->p->len;
			buf_len = mb_process(mb_repl_buf, mb_req_buf, buf_len); // process the data
			netconn_write(newconn, mb_repl_buf, buf_len, NETCONN_COPY); // send the message back to the client
			if(netbuf_next(netbuf) <= 0){
				netbuf_delete(netbuf);
				ether_state = 0;
			}
			break;
		}
	}

}
