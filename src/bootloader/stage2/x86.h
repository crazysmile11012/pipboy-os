#pragma once
#include "stdint.h"
#include "stdio.h"
void _cdecl x86_div64_32(uint64_t dividend, uint32_t divisor, uint64_t* quotientOut, uint32_t* remainderOut);
void _cdecl x86_Video_WriteCharTeletype(char c, uint8_t page);
void irq0_();
void irq1_();
void irq2_();
void irq3_();
void irq4_();
void irq5_();
void irq6_();
void irq7_();
void irq8_();
void irq9_();
void irq10_();
void irq11_();
void irq12_();
void irq13_();
void irq14_();
void irq15_();
void irq_common_stub();
void irqtest_();
