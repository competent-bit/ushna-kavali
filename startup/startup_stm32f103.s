.syntax unified

.cpu cortex-m3
.thumb


.global Reset_Handler
.type Reset_Handler, %function


.section .isr_vector,"a",%progbits

.word 0x20005000
.word Reset_Handler


.section .text.Reset_Handler,"ax",%progbits

Reset_Handler:

    bl main

Loop:
    b Loop