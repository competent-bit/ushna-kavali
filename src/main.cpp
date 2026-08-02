#include <cstdint>
#include "gpio.h"
#include "delay.h"
extern "C"
void SystemInit()
{
}


int main()
{

    
    GpuIO gpio;
    gpio.InitGpio();
    
    while(true)
    {
        //gpio.SetLed();

       // delay::ms(500);

        gpio.UnsetLed();

        delay::ms(1);
    }


    return 0;
}
