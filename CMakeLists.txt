cmake_minimum_required(VERSION 3.20)

project(
    UshnaKavali
    VERSION 1.0
    LANGUAGES C CXX ASM
)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)

add_executable(
    ushna-kavali
)

target_sources(
    ushna-kavali
    PRIVATE
        src/main.cpp
        startup/startup_stm32f103.s
)

target_compile_options(
    ushna-kavali
    PRIVATE
        -mcpu=cortex-m3
        -mthumb
        -ffreestanding
        -fno-exceptions
        -fno-rtti
        -Wall
        -Wextra
)

target_link_options(
    ushna-kavali
    PRIVATE
        -mcpu=cortex-m3
        -mthumb
        -nostdlib
        -T${CMAKE_SOURCE_DIR}/linker/stm32f103.ld
        -Wl,-Map=${CMAKE_BINARY_DIR}/ushna-kavali.map
)

add_custom_command(
    TARGET ushna-kavali
    POST_BUILD
    COMMAND arm-none-eabi-objcopy
        -O binary
        ushna-kavali
        ushna-kavali.bin
)
