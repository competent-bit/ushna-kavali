#pragma once

#include <cstdint>
#include "stm32_registers_config.h"

class GpuIO
{
    public:
    void InitGpio();
    void SetLed();
    void UnsetLed();
    void Toggle();

};