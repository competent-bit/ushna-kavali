
#include "delay.h"


namespace delay
{

void ms(unsigned int value)
{
    while(value--)
    {
        for(volatile int i = 0; i < 8000; i++)
        {

        }
    }
}

}