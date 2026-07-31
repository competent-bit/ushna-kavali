.syntax unified

.cpu cortex-m3
.thumb


.global Reset_Handler


.section .isr_vector

.word 0x20005000
.word Reset_Handler



.section .text


Reset_Handler:

    bl SystemInit

    bl main


Infinite_Loop:

    b Infinite_Loop
