#include <stdint.h>
#include <pru_cfg.h>
#include "resource_table_empty.h"
#include "prugpio.h"

// #define BUS_SPEED 1000000
// #define CLOCK_SPEED 200000000
// #define BIT_DIVISIONS 10
// #define CYCLES_PER_BIT (CLOCK_SPEED/BUS_SPEED)
// #define PULSE_CYCLES ((CYCLES_PER_BIT/BIT_DIVISIONS)-1)
// #define SAMPLE_POINT 50

#define P9_31_R30 0x00000001

#define bit01() {\
	__R30 &= ~P9_31_R30;\
        __delay_cycles(899);\
	__R30 |= P9_31_R30;\
	__delay_cycles(199);\
	__R30 &= ~P9_31_R30;\
	__delay_cycles(899);}

#define bit10() {\
	__R30 |= P9_31_R30;\
	__delay_cycles(899);\
	__R30 &= ~P9_31_R30;\
	__delay_cycles(199);\
	__R30 |= P9_31_R30;\
	__delay_cycles(899);}


#define bit1() {\
	__R30 |= P9_31_R30;\
	__delay_cycles(1999);}

#define bit0() {\
	__R30 &= ~P9_31_R30;\
	__delay_cycles(1999);}

volatile register uint32_t __R30;
volatile register uint32_t __R31;

void main(void)
{
	uint32_t gpio = P9_31;	// Select which pin to toggle.;

	/* Clear SYSCFG[STANDBY_INIT] to enable OCP master port */
	CT_CFG.SYSCFG_bit.STANDBY_INIT = 0;

	while(1) {
		/* New Message Attempt
		//SOF
		bit0() 
		
		//ID Attack
		bit0()
		bit0()
		bit0()
		bit0()
		bit1()
		bit0()
		bit10()
		bit0()
		bit01()
		bit0()
		bit1()
		bit0()
		
		//IDE and Reserved Bit
		bit0()
		bit0()
		bit0()
		
		//Control (currently has stuff bit)
		bit1()
		bit0()
		bit0()
		bit0()
		
		//DB1-Attack
		bit0()
		bit0()
		bit1()
		bit0()
		bit1()
		bit0()
		bit01()
		bit1()
		bit0()
		
		//DB2-Attack
		bit0()
		bit10()
		bit0()
		bit01()
		bit10()
		bit1()
		bit01()
		bit10()
		
		//DB3-Attack (only one message has a stuff bit)
		bit0()
		bit1()
		bit0()
		bit10()
		bit01()
		bit10()
		bit0()
		bit1()
		
		//Data Field Byte 4
		bit0()
		bit0()
		bit0()
		bit0()
		bit0()
		bit1()
		bit0()
		bit0()
		bit0()
		
		//Data Field Byte 5
		bit0()
		bit0()
		bit1()
		bit0()
		bit0()
		bit0()
		bit0()
		bit0()
		bit1()
		bit0()
		
		//Data Field Byte 6
		bit0()
		bit0()
		bit0()
		bit0()
		bit1()
		bit0()
		bit0()
		bit0()
		bit0()
		//Data Field Byte 7
		bit0()
		bit1()
		bit0()
		bit0()
		bit0()
		bit0()
		bit0()
		bit1()
		bit0()
		bit0()
		//Data Field Byte 8
		bit0()
		bit0()
		bit0()
		bit1()
		bit0()
		bit0()
		bit0()
		bit0()
		bit0()
		bit1()
		//CRC Attack
		bit10()
		bit10()
		bit1()
		bit10()
		bit0()
		bit1()
		bit10()
		bit10()
		bit01()
		bit10()
		bit01()
		bit1()
		bit10()
		bit01()
		bit0()
		bit1()//bit10()
		
		//EOF
		bit1()
		bit1()
		bit1()
		bit1()
		bit1()
		bit1()

		//IFS
		bit1()
		bit1()
		bit1()
		*/

		//Old Message
		//SOF
		bit0()
		
		//ID
		bit0()
		bit0()
		bit1()
		
		bit0()
		bit0()
		bit1()
		bit0()
		
		bit0()
		bit0()
		bit1()
		bit1()
		
		bit0()
		bit0()
		bit0()
		
		//CTRL
		bit0()
		bit1()
		bit0()
		bit0()
		
		//DATA[0] = 0x00
		bit0()
		bit0()
		bit0()
		bit1()//stuff
		bit0()
		bit0()
		bit0()
		bit0()
		bit0()
		
		bit1()//stuff
		
		//DATA[1] = 0x01
		bit0()
		bit0()
		bit0()
		bit0()
		bit0()
		bit1()//stuff
		bit0()
		bit0()
		bit1()
		
		//DATA[2] = 0x02
		bit0()
		bit0()
		bit0()
		bit0()
		bit0()
		bit1()//stuff
		bit0()
		bit1()
		bit0()
		
		//DATA[3] = 0x03
		bit0()
		bit0()
		bit0()
		bit0()
		bit1()//stuff
		bit0()
		bit0()
		bit1()
		bit1()
		
		//CRC
		bit0()
		bit0()
		bit0()
		bit0()
		bit0()
		bit1()//stuff
		bit1()
		bit1()
		bit0()
		bit1()
		bit0()
		bit1()
		bit1()
		bit1()
		bit0()
		
		//CRC Delim
		bit1()
		
		//ACK
		bit1()
		
		//ACK Delim
		bit1()
		
		//EOF
		bit1()
		bit1()
		bit1()
		bit1()
		bit1()
		bit1()
		bit1()
		
		//IFS
		bit1()
		bit1()
		bit1()
		
		
	}
}
