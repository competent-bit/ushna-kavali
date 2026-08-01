#include "gpio.h"

void GpuIO::InitGpio(){
    stm32_config::_stm32_rcc->APB2RSTR |= (1<<4);
    stm32_config::_stm32_gpio->CRH &= ~(0xF<<20);
    stm32_config::_stm32_gpio->CRH |= (0x2<<20);
}

void GpuIO::SetLed(){
    stm32_config::_stm32_gpio->BRR |= (1<<13);
}
void GpuIO::UnsetLed(){
    stm32_config::_stm32_gpio->BSRR |= (1<<13);
}
void GpuIO::Toggle(){

    if(stm32_config::_stm32_gpio->ODR & (1 << 13))
    {
        SetLed();
    }
    else
    {
        UnsetLed();
    }

}