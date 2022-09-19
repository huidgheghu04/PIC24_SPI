/**
  MSSP Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    spi.c

  @Summary
    This is the generated driver implementation file for the MSSP driver using 
    PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This source file provides APIs SPI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC18F45K20
        Driver Version    :  2.02
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.05 and above
        MPLAB 	          :  MPLAB X 5.20
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

/**
  Section: Included Files
*/

#include <xc.h>
#include "spi.h"

/**
  Section: Macro Declarations
*/

#define SPI_RX_IN_PROGRESS 0x0

/**
  Section: Module APIs
*/

/*void SPI_Initialize(void)
{
    // Set the SPI module to the options selected in the User Interface
    
    // R_nW write_noTX; P stopbit_notdetected; S startbit_notdetected; BF RCinprocess_TXcomplete; SMP Middle; UA dontupdate; CKE Idle to Active; D_nA lastbyte_address; 
    SSPSTAT = 0x00;
    
    // SSPEN enabled; WCOL no_collision; CKP Idle:High, Active:Low; SSPM FOSC/4; SSPOV no_overflow; 
    SSPCON1 = 0x30;
    
    // SSPADD 0; 
    SSPADD = 0x00;
}
*/

void SPI_Initialize(void)
{
    RPINR20bits.SDI1R = 7;  //SDI?RP7(RB7)?
    RPOR2bits.RP4R = 8;     //SCK1?RP28(RB4)?
    RPOR9bits.RP18R = 7;     //SDO1?RP18(RB5)?
    RPOR3bits.RP6R = 7;     //SS1?RP6(RB6)?
    // Set the SPI module to the options selected in the User Interface
    
    //SPI????
    // R_nW write_noTX; P stopbit_notdetected; S startbit_notdetected; BF RCinprocess_TXcomplete; SMP Middle; UA dontupdate; CKE Idle to Active; D_nA lastbyte_address; 
    //SSPSTAT = 0x00;
    SPI1CON1 = 0x20; //0010 0000
    SPI1CON2 = 0x00; //0000 0000
    
    SPI1STAT = 0x8000;   //1000 0000 0000 0000
           
    // SSPEN enabled; WCOL no_collision; CKP Idle:High, Active:Low; SSPM FOSC/4; SSPOV no_overflow; 
    //SSPCON1 = 0x30;     //11 0000
    //SPI1CON1 = 0x20; //0010 0000
    //bit5mastermode

    // SSPADD 0; 
   // SSPADD = 0x00;
}

uint8_t SPI_Exchange8bit(uint8_t data)
{
    // Clear the Write Collision flag, to allow writing
   // SSPCON1bits.WCOL = 0;

    SPI1BUF = data;     //main?16???????

    /*while(SSPSTATbits.BF == SPI_RX_IN_PROGRESS)     //  //BF?Buffer full status//?????SSPBUF?????
    {
    }

    return (SSPBUF);
     */
    
    /*while(SPI1STATbits.SPITBF == SPI_RX_IN_PROGRESS)     //BF?Buffer full status// Receive is not complete, SPIxRXB is empty
    {
    }

    return (SPI1BUF);
     */
    //while (!SPI1STATbits.SPITBF);        // SPI??????//TBF=1???????//1 = Transmit has not yet started, SPIxTXB is full
    while(SPI1STATbits.SPITBF != SPI_RX_IN_PROGRESS)
    {
    }
    
}

/*uint8_t SPI_Exchange8bit(uint8_t data)
{
    // Clear the Write Collision flag, to allow writing
    //SSPCON1bits.WCOL = 0;

    SPI1BUF = data;

    while(SSPSTATbits.BF == SPI_RX_IN_PROGRESS)
    {
    }

    return (SSPBUF);
}*/
/*
uint8_t SPI_Exchange8bitBuffer(uint8_t *dataIn, uint8_t bufLen, uint8_t *dataOut)
{
    uint8_t bytesWritten = 0;

    if(bufLen != 0)
    {
        if(dataIn != NULL)
        {
            while(bytesWritten < bufLen)
            {
                if(dataOut == NULL)
                {
                    SPI_Exchange8bit(dataIn[bytesWritten]);
                }
                else
                {
                    dataOut[bytesWritten] = SPI_Exchange8bit(dataIn[bytesWritten]);
                }

                bytesWritten++;
            }
        }
        else
        {
            if(dataOut != NULL)
            {
                while(bytesWritten < bufLen )
                {
                    dataOut[bytesWritten] = SPI_Exchange8bit(SPI_DUMMY_DATA);

                    bytesWritten++;
                }
            }
        }
    }

    return bytesWritten;
}


 End of File
*/