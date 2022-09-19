 /* 
 * File:   main.c
 * Author: shin
 *
 * Created on 2015/03/16, 21:12
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mcc.h"
#include "device_config.h"
#include "pin_manager.h"
#include "spi.h"


/*
#include "msTimer.h"
#include "UART.h"
#include "I2C1.h"
#include "MT9.h"
#include "cmd_analyze.h"
#include "tlm_frame.h"
#include "FIFO.h"
*/
/*
#define DEF_SHUTTER (unsigned long)(0x0000003F)
#define DEF_GAIN    (unsigned int)(0x0008)
 * */
//#define DEF_SHUTTER (unsigned long)(0x00000100)
//#define DEF_GAIN    (unsigned int)(0x0008)
/*
#define CMD_BUFFER_MAX 32
unsigned char   rec_buffer[CMD_BUFFER_MAX];
int             rec_byte;
*/


void main(void)
{
    SYSTEM_Initialize();
    int W;
    while (1){
    
     LATBbits.LATB6 = 0; //SS=0
        SPI_Exchange8bit(0x06);
        SPI_Exchange8bit(0x02);
        SPI_Exchange8bit(0x00);
        SPI_Exchange8bit(0x00);
        for(W=1; W<=16384; W++){
            SPI_Exchange8bit(0xAA);
            SPI_Exchange8bit(0x55);
        }
        W=1;
      //  LATAbits.LATA5 = 1; 
          LATBbits.LATB6 = 1; //SS=1
          
        LATBbits.LATB6 = 0; //SS=0
        SPI_Exchange8bit(0x03);
        SPI_Exchange8bit(0x00);
        SPI_Exchange8bit(0x00);
        for(W=1; W=32768; W++){
            SPI_Exchange8bit(0xAA);
           
        }
        W=1;
        LATBbits.LATB5 = 1;//SS=1
    }
    
}

