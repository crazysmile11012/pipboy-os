#pragma once
#include "stdint.h"
#include "system.h"
void _cdecl x86_div64_32(uint64_t dividend, uint32_t divisor, uint64_t* quotientOut, uint32_t* remainderOut);
void _cdecl x86_Video_WriteCharTeletype(char c, uint8_t page);
//void _cdecl panic();
//void _cdec1 debugasmfunc();
