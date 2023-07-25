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
#include <gpio.h>
//#include <stm32_peps.h>

#define a 8
#define b 9
#define c 10
#define d 11
#define e 4
#define f 5
#define g 6

void DRV_GPIO_INIT(GPIO_TypeDef* gpio)
{
gpio->MODER |= 1<<0;	
}

void led_init()
{
    RCC->AHB1ENR |= (1<<0);
    GPIOA->MODER |= (1<<a*2) | (1<<(b*2)) | (1<<(c*2)) | (1<<(d*2)) | (1<<(e*2)) | (1<<(f*2)) | (1<<(g*2));  
                    //  a           b             c             d            e            f            g
    return;
}

void led_on(uint8_t led_no)
{
	GPIOA->BSRR |= (1<<led_no);
    return;
}

void led_off(uint8_t led_no)
{
	GPIOA->BSRR |= (1<<led_no) << 16;
    return;
}

void show_digit(uint8_t n)
{
    if(n==0)
    {
        led_on(a);
        led_on(b);
        led_on(c);
        led_on(d);
        led_on(e);
        led_on(f);
        led_off(g);
    }

    else if(n==1)
    {
        led_off(a);
        led_on(b);
        led_on(c);
        led_off(d);
        led_off(e);
        led_off(f);
        led_off(g);
    }

    else if(n==2)
    {
        led_on(a);
        led_on(b);
        led_off(c);
        led_on(d);
        led_on(e);
        led_off(f);
        led_on(g);
    }

    else if(n==3)
    {
        led_on(a);
        led_on(b);
        led_on(c);
        led_on(d);
        led_off(e);
        led_off(f);
        led_on(g);
    }

    else if(n==4)
    {
        led_off(a);
        led_on(b);
        led_on(c);
        led_off(d);
        led_off(e);
        led_on(f);
        led_on(g);
    }

    else if(n==5)
    {
        led_on(a);
        led_off(b);
        led_on(c);
        led_on(d);
        led_off(e);
        led_on(f);
        led_on(g);
    }

    else if(n==6)
    {
        led_on(a);
        led_off(b);
        led_on(c);
        led_on(d);
        led_on(e);
        led_on(f);
        led_on(g);
    }

    else if(n==7)
    {
        led_on(a);
        led_on(b);
        led_on(c);
        led_off(d);
        led_off(e);
        led_off(f);
        led_off(g);
    }

    else if(n==8)
    {
        led_on(a);
        led_on(b);
        led_on(c);
        led_on(d);
        led_on(e);
        led_on(f);
        led_on(g);
    }

    else if(n==9)
    {
        led_on(a);
        led_on(b);
        led_on(c);
        led_on(d);
        led_off(e);
        led_on(f);
        led_on(g);
    }

    else {
        led_on(a);
        led_off(b);
        led_off(c);
        led_on(d);
        led_on(e);
        led_on(f);
        led_on(g);
    }
    
}

