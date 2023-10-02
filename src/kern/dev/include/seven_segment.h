#ifndef __SEVEN_SEGMENT_H
#define __SEVEN_SEGMENT_H
#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>
#include <gpio.h>>

#define a 8
#define b 9
#define c 10
#define d 11
#define e 4
#define f 5
#define g 6

uint32_t module_init(void); //return 0 for successful otherwise unsuccessfull
void module_exit(void); //disable or offload the device

#ifdef __cplusplus
}
#endif
#endif
#endif
