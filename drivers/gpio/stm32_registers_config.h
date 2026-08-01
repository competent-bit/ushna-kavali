#pragma once
#include <cstdint>
namespace stm32_config{
struct RCC{
    volatile uint32_t CR;          // 0x00
    volatile uint32_t CFGR;        // 0x04
    volatile uint32_t CIR;         // 0x08
    volatile uint32_t APB2RSTR;    // 0x0C
    volatile uint32_t APB1RSTR;    // 0x10
    volatile uint32_t AHBENR;      // 0x14
    volatile uint32_t APB2ENR;     // 0x18  <-- required
};
struct GPIO{
    volatile uint32_t CRL;     // 0x00
    volatile uint32_t CRH;     // 0x04  <-- PC13 config
    volatile uint32_t IDR;     // 0x08
    volatile uint32_t ODR;     // 0x0C
    volatile uint32_t BSRR;    // 0x10  <-- set pin
    volatile uint32_t BRR;     // 0x14  <-- clear pin
};

namespace stm32_reg_base{
    inline constexpr uintptr_t _rcc_base    =   0x40021000;
    inline constexpr uintptr_t _gpio_base   =   0x40011000;
}

inline RCC *_stm32_rcc = reinterpret_cast<RCC*>(stm32_reg_base::_rcc_base);
inline GPIO *_stm32_gpio = reinterpret_cast<GPIO*>(stm32_reg_base::_gpio_base);
}