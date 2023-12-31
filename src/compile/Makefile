# Makefile for DUOS: Last Updated on October 28, 2022
TOP=../kern
MCU=stm32f446re
CC=arm-none-eabi-gcc
MACH=cortex-m4
TARGET = target
FPU = -mfloat-abi=softfp -mfpu=fpv4-sp-d16
OBJECT = object
USERLAND = ../userland
INCLUDE=-I$(TOP)/arch/include -I$(TOP)/arch/$(MCU)/include -I$(TOP)/include -I$(TOP)/include/kern -I$(TOP)/include/testprog -I$(TOP)/arch/$(MCU)/include -I$(TOP)/arch/$(MCU)/include/dev -I$(TOP)/arch/include/cm4 -I$(TOP)/arch/$(MCU)/include/sys -I$(USERLAND)/include -I$(TOP)/arch/$(MCU)/include/utilities -I$(TOP)/dev/include
MAPDIR = mapfiles
CFLAGS=-c -mcpu=$(MACH) -mthumb $(FPU) -std=gnu11 -Wall -O0
LDFLAGS = -nostdlib -nostartfiles -nodefaultlibs -fno-exceptions  -mcpu=$(MACH) -mthumb $(FPU) -T $(TOP)/arch/$(MCU)/linker/linker.ld -Wl,-Map=$(MAPDIR)/duos.map -O0
.PHONY: all clean load
all: kstring.o kmath.o cm4.o kfloat.o clock.o usart.o gpio.o timer.o kmain.o kstdio.o stm32_startup.o sys_init.o unistd.o times.o kunistd.o ktimes.o syscall.o seven_segment.o  sys.o test_interrupt.o duos

kstdio.o: $(TOP)/lib/kstdio.c
	$(CC) $(CFLAGS) $(INCLUDE) $^ -o $(OBJECT)/$@
	
kstring.o: $(TOP)/lib/kstring.c
	$(CC) $(CFLAGS) $(INCLUDE) $^ -o $(OBJECT)/$@

kmain.o: $(TOP)/kmain/kmain.c
	$(CC) $(CFLAGS) $(INCLUDE) $^ -o $(OBJECT)/$@
	
kmain.o: $(TOP)/kmain/kmain.c
	$(CC) $(CFLAGS) $(INCLUDE) $^ -o $(OBJECT)/$@
	
sys_init.o: $(TOP)/lib/sys_init.c
	$(CC) $(CFLAGS) $(INCLUDE) $^ -o $(OBJECT)/$@

clock.o: $(TOP)/arch/$(MCU)/dev/clock.c
	$(CC) $(CFLAGS) $(INCLUDE) $^ -o $(OBJECT)/$@

gpio.o: $(TOP)/arch/$(MCU)/dev/gpio.c
	$(CC) $(CFLAGS) $(INCLUDE) $^ -o $(OBJECT)/$@
	
usart.o: $(TOP)/arch/$(MCU)/dev/usart.c
	$(CC) $(CFLAGS) $(INCLUDE) $^ -o $(OBJECT)/$@
	
timer.o: $(TOP)/arch/$(MCU)/dev/timer.c
	$(CC) $(CFLAGS) $(INCLUDE) $^ -o $(OBJECT)/$@

kmath.o: $(TOP)/lib/kmath.c
	$(CC) $(CFLAGS) $(INCLUDE) $^ -o $(OBJECT)/$@

test_interrupt.o: $(TOP)/lib/testprog/test_interrupt.c
	$(CC) $(CFLAGS) $(INCLUDE) $^ -o $(OBJECT)/$@
	
stm32_startup.o: $(TOP)/arch/$(MCU)/sys/stm32_startup.c
	$(CC) $(CFLAGS) $(INCLUDE) $^ -o $(OBJECT)/$@

cm4.o: $(TOP)/arch/cm4/cm4.c
	$(CC) $(CFLAGS) -I$(INCLUDE) $^ -o $(OBJECT)/$@

kfloat.o: $(TOP)/lib/kfloat.c
	$(CC) $(CFLAGS) $(INCLUDE) $^ -o $(OBJECT)/$@

unistd.o: $(USERLAND)/utils/unistd.c
	$(CC) $(CFLAGS) $(INCLUDE) $^ -o $(OBJECT)/$@

kunistd.o: $(TOP)/lib/kunistd.c
	$(CC) $(CFLAGS) $(INCLUDE) $^ -o $(OBJECT)/$@

ktimes.o: $(TOP)/lib/ktimes.c
	$(CC) $(CFLAGS) $(INCLUDE) $^ -o $(OBJECT)/$@
	
times.o: $(USERLAND)/utils/times.c
	$(CC) $(CFLAGS) $(INCLUDE) $^ -o $(OBJECT)/$@
	
syscall.o: $(TOP)/syscall/syscall.c
	$(CC) $(CFLAGS) $(INCLUDE) $^ -o $(OBJECT)/$@ 

seven_segment.o: $(TOP)/dev/seven_segment.c
	$(CC) $(CFLAGS) $(INCLUDE) $^ -o $(OBJECT)/$@

sys.o: $(TOP)/arch/$(MCU)/sys/sys.c
	$(CC) $(CFLAGS) $(INCLUDE) $^ -o $(OBJECT)/$@

duos: $(OBJECT)/kmath.o $(OBJECT)/kfloat.o  $(OBJECT)/cm4.o $(OBJECT)/kstring.o $(OBJECT)/kmain.o $(OBJECT)/stm32_startup.o $(OBJECT)/sys.o $(OBJECT)/clock.o $(OBJECT)/usart.o $(OBJECT)/gpio.o $(OBJECT)/timer.o $(OBJECT)/kstdio.o $(OBJECT)/sys_init.o $(OBJECT)/unistd.o $(OBJECT)/times.o $(OBJECT)/kunistd.o $(OBJECT)/ktimes.o $(OBJECT)/syscall.o $(OBJECT)/seven_segment.o $(OBJECT)/test_interrupt.o 
	$(CC) $(LDFLAGS) $^ -o $(TARGET)/$@

clean:
	rm -rf $(OBJECT)/*.o $(MAPDIR)/*.map $(TARGET)/* *.o *.elf

# To Students -- Modify to match with the appropriate driver file.
load:
	openocd -f board/stm32f4discovery.cfg -c "program target/duos verify reset exit"


	

