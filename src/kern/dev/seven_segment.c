#include "seven_segment.h"

uint32_t module_init(void)
{
    RCC->AHB1ENR |= (1<<0);
    GPIOA->MODER |= (1<<a*2) | (1<<(b*2)) | (1<<(c*2)) | (1<<(d*2)) | (1<<(e*2)) | (1<<(f*2)) | (1<<(g*2));  
                    //  a           b             c             d            e            f            g
    return 0;
}

void module_exit(void){}

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