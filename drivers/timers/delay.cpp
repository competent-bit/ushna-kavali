#include <stdint.h>
#include "delay.h"


namespace delay
{

void ms(unsigned int value)
{
    while(value--)
    {
        for (volatile uint32_t i = 0; i < 10000000; i++)
        {
            __asm volatile("nop");
        }
    }
}

}