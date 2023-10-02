/*
 * Copyright (c) 2022
 * Computer Science and Engineering, University of Dhaka
 * Credit: CSE Batch 25 (starter) and Prof. Mosaddek Tushar
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE UNIVERSITY AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE UNIVERSITY OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <stm32_startup.h>
#include <stm32_peps.h>
#include <kstdio.h>
#include <cm4.h>
void Reset_Handler(void)
{
	uint32_t size = (uint32_t)&_edata - (uint32_t)&_sdata;
	uint8_t *pDst = (uint8_t *)&_sdata;
	uint8_t *pSrc = (uint8_t *)&_la_data;
	for (uint32_t i = 0; i < size; i++)
	{
		*pDst++ = *pSrc++;
	}
	size = (uint32_t)&_ebss - (uint32_t)&_sbss;
	pDst = (uint8_t *)&_sbss;
	for (uint32_t i = 0; i < size; i++)
	{
		*pDst++ = 0;
	}
	_text_size = (uint32_t)&_etext - (uint32_t)&_stext;
	_data_size = (uint32_t)&_edata - (uint32_t)&_sdata;
	_bss_size = (uint32_t)&_ebss - (uint32_t)&_sbss;
	kmain();
}
void Default_Handler(void)
{
	while (1)
		;
}
// 2. implement the fault handlers
void HardFault_Handler(void)
{
	kprintf("Exception : Hardfault\n");
	SCB->AIRCR = (0x5FA << 16) | (0x4 << 0);
	// while (1)
	// 	;
}

void MemManage_Handler(void)
{
	//	printf("Exception : MemManage\n");
	while (1)
		;
}

void BusFault_Handler(void)
{
	//	printf("Exception : BusFault\n");
	while (1)
		;
}

uint32_t getMsCount(void)
{
	return __mscount;
}
uint32_t timer = 0;
void Delay(uint32_t ms)
{
	timer = ms/1000;
	while (timer != 0)
		;
}
int milliseconds = 0;
void SysTick_Handler(void)
{
	 //kprintf("\n%d : Systic Handler\n", SYSTICK->LOAD);
	
	milliseconds++; // Increment the milliseconds counter
	if(milliseconds==100)
	{
		__mscount++;
		timer--;
		milliseconds = 0;
	}
	// Print something every, for example, 1000 milliseconds (1 second)
	//	kprintf("%d\n", milliseconds);
	// if (milliseconds == 1000)
	// {
	// 	timer = 0;
	// 	milliseconds = 0;
	// }
	// SYSTICK->CTRL &= ~(1 << 1);
	//// kmain();
}
// __asm void SVCall_Handler(void)
// {
// 	TST LR, #4
// 	ITE EQ; Test bit 2 of EXC_RETURN
// 	MRSEQ R0, MSP; if 0, stacking used MSP, copy to R0
// 	MRSNE R0, PSP; if 1, stacking used PSP, copy to R0
// 	B __cpp(SVC_Handler_C)
// 	ALIGN 4
// }

void SVC_Handler_main(unsigned int * svc_args)
{
	// Stack frame contains:
	// r0, r1, r2, r3, r12, r14, the return address and xPSR
	// - Stacked R0 = svc_args[0];
	// - Stacked R1 = svc_args[1];
	// - Stacked R2 = svc_args[2];
	// - Stacked R3 = svc_args[3];
	// - Stacked R12 = svc_args[4]
	// - Stacked LR = svc_args[5]
	// - Stacked PC = svc_args[6]
	// - Stacked xPSR = svc_args[7]
	unsigned int svc_number;
	svc_number = ((char *)svc_args[6])[-2];
	syscall(svc_number);

	return;
}
