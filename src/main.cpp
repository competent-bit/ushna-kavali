#include <cstdint>


extern "C"
void SystemInit()
{
}


int main()
{

    volatile uint32_t counter = 0;


    while(true)
    {
        counter++;
    }


    return 0;
}
