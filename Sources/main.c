/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "fsl_device_registers.h"

#define delay 500000

static unsigned int i = 0;

int main(void)
{

    /* Write your code here */
	/* Enable Port B */
	SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK;

	/* Enable RED LED as GPIO */
	PORTB_PCR10 |= PORT_PCR_MUX(1);
	/* Enable GREEN LED as GPIO */
	PORTB_PCR11 |= PORT_PCR_MUX(1);
	/* Enable BLUE LED as GPIO */
	PORTB_PCR13 |= PORT_PCR_MUX(1);

	/* Set PTB10, PTB11 and PTB13 as outputs */
	GPIOB_PDDR |= 1 << 10 | 1 << 11 | 1 << 13;

	/* Turn off LEDs */
	GPIOB_PSOR = 1 << 10 | 1 << 11 | 1 << 13;

    while(1){
    	/* Turn on RED LED */
    	GPIOB_PCOR = 1 << 10;
    	for(i = 0; i < delay; i++); /* delay */
    	/* Turn off RED LED */
    	GPIOB_PSOR = 1 << 10;
    	for(i = 0; i < delay; i++); /* delay */

    	/* Turn on GREEN LED */
    	GPIOB_PCOR = 1 << 11;
    	for(i = 0; i < delay; i++); /* delay */
    	/* Turn off GREEN LED */
    	GPIOB_PSOR = 1 << 11;
    	for(i = 0; i < delay; i++); /* delay */

    	/* Turn on BLUE LED */
    	GPIOB_PCOR = 1 << 13;
    	for(i = 0; i < delay; i++); /* delay */
    	/* Turn off BLUE LED */
    	GPIOB_PSOR = 1 << 13;
    	for(i = 0; i < delay; i++); /* delay */
    }
    /* Never leave main */
    return 0;
}
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
