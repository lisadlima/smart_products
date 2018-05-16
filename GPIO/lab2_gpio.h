// Filename: lab2_gpio.h
#ifndef LAB2_GPIO
#define LAB2_GPIO

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <fcntl.h>
#include <ctype.h>
#include <termios.h>
#include <sys/types.h>
#include <sys/mman.h>

#define PERPH_BASE 0x3F000000
#define GPIO_BASE 0x200000
#define GPIO_READ0 0x0034
#define GPIO_READ1 0x0038
#define GPIO_HIGH0 0x001C
#define GPIO_HIGH1 0x0020
#define GPIO_LOW0 0x0028
#define GPIO_LOW1 0x002C
#define MAP_SIZE 4096UL
#define MAP_MASK (MAP_SIZE-1)
#define MEM_PATH "/dev/mem"
#define GPIO_PATH "/dev/gpiomem"		
#define GP_MASK 0x7

// Raspberry Pi addresses using the tech spec for RPi3.
// Page 90 of BCM2835-ARM-Peripherals spec sheet: https://www.raspberrypi.org/app/uploads/2012/02/BCM2835-ARM-Peripherals.pdf
//-----------------------------------------------------------------------------------------------------------------------------------------
#define GPFSEL0	0x0000
#define GPFSEL1 0x0004
#define GPFSEL2	0x0008
#define GPFSEL3	0x000C
#define GPFSEL4	0x0010
#define GPFSEL5	0x0014
//-----------------------------------------------------------------------------------------------------------------------------------------

typedef enum{ HIGH = 1, LOW = 0} outValue ;

typedef enum {
	INPUT =  0x0,
	OUTPUT = 0x1,
	ALT0 = 0x4,
	ALT1 = 0x5,
	ALT2 = 0x6,
	ALT3 = 0x7,
	ALT4 = 0x3,
	ALT5 = 0x2
	} pinModes;

class lab2_gpio
{
private:
	void *ptr_base;
	int memfd;
public:
	int  pinMode(int, pinModes);
	int  pinModeRead(int, pinModes);
	int digitalRead(int);
	int digitalWrite(int, outValue);
	lab2_gpio()
	{
		// Complete offset + base for GPIO
		off_t gpio_base = (PERPH_BASE+GPIO_BASE);// base address for GPIO

        // Access the driver using the open() function with the following arguments:
        // 𝒐𝒑𝒆𝒏("/𝑑𝑒𝑣/𝑚𝑒𝑚",𝑂_𝑅𝐷𝑊𝑅 | 𝑂_𝑆𝑌𝑁𝐶)
        // 1. A pointer to the name of the device/file to be opened.
        // 2. A mode specifying how the opened device/file can be used by the program.
        // http://man7.org/linux/man-pages/man2/open.2.html
		memfd = open(MEM_PATH, O_RDWR|O_SYNC);// open driver

		if (memfd<0)  printf("Cannot open");
        
        // Map the addresses using the mmap() function with 6 arguments:
        // 𝒎𝒎𝒂𝒑(𝒗𝒐𝒊𝒅 ∗𝑎𝑑𝑑𝑟, 𝒔𝒊𝒛𝒆_𝒕 𝑙𝑒𝑛𝑔𝑡ℎ,𝒊𝒏𝒕 𝑝𝑟𝑜𝑡,𝒊𝒏𝒕 𝑓𝑙𝑎𝑔𝑠,𝒊𝒏𝒕 𝑓𝑑, 𝒐𝒇𝒇_𝒕 𝑜𝑓𝑓𝑠𝑒𝑡);
        // 1. The address where the device should be mapped into (usually set to NULL to allow the
        //    program to find the best location), which needs to be in our programming virtual memory space.
        // 2. The amount of memory for the mapping. One page is sufficient. (4096UL for Raspbian).
        // 3. A mode specifying the protection given to the mapped memory. This cannot conflict with the
        //    protection specified in the open operation. We want to read from and write to this memory.
        // 4. A mode specifying whether this mapped memory should or should not be shared with other
        //    processes. We will allow sharing. You may wish to have more than one program accessing the GPIO at the same time.
        // 5. The file descriptor to the device being mapped. This came from our call to open
        // 6. The physical memory location of the I/O device.
        // http://man7.org/linux/man-pages/man2/mmap.2.html
		ptr_base = mmap(NULL, MAP_SIZE, (PROT_READ|PROT_WRITE), MAP_SHARED, memfd, gpio_base);// mapping
	}
	~lab2_gpio()
	{
		munmap(ptr_base,MAP_SIZE);
		close(memfd);
	}	
};
#endif


