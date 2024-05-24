bits 16
%define ENDL 0x0D, 0x0A

extern __SYSTEM_H 
extern puts_
extern fault_handler_
extern irq_handler_
extern irq_install_
global _x86_div64_32
global _x86_Video_WriteCharTeletype
global _debugasmfunc
global isr0_
global isr1_
global isr2_
global isr3_
global isr4_
global isr5_
global isr6_
global isr7_
global isr8_
global isr9_
global isr10_
global isr11_
global isr12_
global isr13_
global isr14_
global isr15_
global isr16_
global isr17_
global isr18_
global isr19_
global isr20_
global isr21_
global isr22_
global isr23_
global isr24_
global isr25_
global isr26_
global isr27_
global isr28_
global isr29_
global isr30_
global isr31_

global irq0_
global irq1_
global irq2_
global irq3_
global irq4_
global irq5_
global irq6_
global irq7_
global irq8_
global irq9_
global irq10_
global irq11_
global irq12_
global irq13_
global irq14_
global irq15_
global irqtest_
;section _TEXT class=CODE
section .text
; 0: Divide By Zero Exception
isr0_:
 push byte 0
 push byte 0
 jmp isr_common_stub
; 1: Debug Exception
isr1_:
 push byte 0
 push byte 1
 jmp isr_common_stub
; 2: Non Maskable Interrupt Exception
isr2_:
 ;cli
 push byte 0
 push byte 2
 jmp isr_common_stub
; 3: Int 3 Exception
isr3_:
 ;cli
 push byte 0
 push byte 3
 jmp isr_common_stub
; 4: INTO Exception
isr4_:
 ;cli
 push byte 0
 push byte 4
 jmp isr_common_stub
; 5: Out of Bounds Exception
isr5_:
 ;cli
 push byte 0
 push byte 5
 jmp isr_common_stub
; 6: Invalid Opcode Exception
isr6_:
 ;cli
 push byte 0
 push byte 6
 jmp isr_common_stub
; 7: Coprocessor Not Available Exception
isr7_:
 ;cli
 push byte 0
 push byte 7
 jmp isr_common_stub
; 8: Double Fault Exception (With Error Code!)
isr8_:
 ;cli
 push byte 8
 jmp isr_common_stub
; 9: Coprocessor Segment Overrun Exception
isr9_:
 ;cli
 push byte 0
 push byte 9
 jmp isr_common_stub
; 10: Bad TSS Exception (With Error Code!)
isr10_:
 ;cli
 push byte 10
 jmp isr_common_stub
; 11: Segment Not Present Exception (With Error Code!)
isr11_:
 ;cli
 push byte 11
 jmp isr_common_stub
; 12: Stack Fault Exception (With Error Code!)
isr12_:
 ;cli
 push byte 12
 jmp isr_common_stub
; 13: General Protection Fault Exception (With Error Code!)
isr13_:
 ;cli
 push byte 13
 jmp isr_common_stub
; 14: Page Fault Exception (With Error Code!)
isr14_:
 ;cli
 push byte 14
 jmp isr_common_stub
; 15: Reserved Exception
isr15_:
 ;cli
 push byte 0
 push byte 15
 jmp isr_common_stub
; 16: Floating Point Exception
isr16_:
 ;cli
 push byte 0
 push byte 16
 jmp isr_common_stub
; 17: Alignment Check Exception
isr17_:
 ;cli
 push byte 0
 push byte 17
 jmp isr_common_stub
; 18: Machine Check Exception
isr18_:
 ;cli
 push byte 0
 push byte 18
 jmp isr_common_stub
; 19: Reserved
isr19_:
 ;cli
 push byte 0
 push byte 19
 jmp isr_common_stub
; 20: Reserved
isr20_:
 ;cli
 push byte 0
 push byte 20
 jmp isr_common_stub
; 21: Reserved
isr21_:
 ;cli
 push byte 0
 push byte 21
 jmp isr_common_stub
; 22: Reserved
isr22_:
 ;cli
 push byte 0
 push byte 22
 jmp isr_common_stub
; 23: Reserved
isr23_:
 ;cli
 push byte 0
 push byte 23
 jmp isr_common_stub
; 24: Reserved
isr24_:
 ;cli
 push byte 0
 push byte 24
 jmp isr_common_stub
; 25: Reserved
isr25_:
 ;cli
 push byte 0
 push byte 25
 jmp isr_common_stub
; 26: Reserved
isr26_:
 ;cli
 push byte 0
 push byte 26
 jmp isr_common_stub
; 27: Reserved
isr27_:
 ;cli
 push byte 0
 push byte 27
 jmp isr_common_stub
; 28: Reserved
isr28_:
 ;cli
 push byte 0
 push byte 28
 jmp isr_common_stub
; 29: Reserved
isr29_:
 ;cli
 push byte 0
 push byte 29
 jmp isr_common_stub
; 30: Reserved
isr30_:
 ;cli
 push byte 0
 push byte 30
 jmp isr_common_stub
; 31: Reserved
isr31_:
 ;cli
 push byte 0
 push byte 31
 jmp isr_common_stub
; In isr_common_stub we will use a C function called "fault_handler"

; Here we save the processor state, calls the C fault handler
; and restores the stack frame in the end.
isr_common_stub:
 pusha
 push ds
 push es
 push fs
 push gs
 mov ax, 0x10
 mov ds, ax
 mov es, ax
 mov fs, ax
 mov gs, ax
 mov eax, esp
 push eax
 mov eax, fault_handler_
 call eax
 mov si, debug
 call puts_
 pop eax
 pop gs
 pop fs
 pop es
 pop ds
 popa
 add esp, 8
 iret
; Handling Hardware Interrupt Requests


; 32: IRQ0
irq0_:
 
 push byte 0
 push byte 32
 jmp irq_common_stub
; 33: IRQ1
irq1_:
 
 push byte 0
 push byte 33
 jmp irq_common_stub
; 34: IRQ2
irq2_:
 ;;cli
 push byte 0
 push byte 34
 jmp irq_common_stub
; 35: IRQ3
irq3_:
 ;;cli
 push byte 0
 push byte 35
 jmp irq_common_stub
; 36: IRQ4
irq4_:
 ;;cli
 push byte 0
 push byte 36
 jmp irq_common_stub
; 37: IRQ5
irq5_:
 ;;cli
 push byte 0
 push byte 37
 jmp irq_common_stub
; 38: IRQ6
irq6_:
 ;;cli
 push byte 0
 push byte 38
 jmp irq_common_stub
; 39: IRQ7
irq7_:
 ;;cli
 push byte 0
 push byte 39
 jmp irq_common_stub
; 40: IRQ8
irq8_:
 ;;cli
 push byte 0
 push byte 40
 jmp irq_common_stub
; 41: IRQ9
irq9_:
 ;;cli
 push byte 0
 push byte 41
 jmp irq_common_stub
; 42: IRQ10
irq10_:
 ;;cli
 push byte 0
 push byte 42
 jmp irq_common_stub
; 43: IRQ11
irq11_:
 ;;cli
 push byte 0
 push byte 43
 jmp irq_common_stub
; 44: IRQ12
irq12_:
 ;;cli
 push byte 0
 push byte 44
 jmp irq_common_stub
; 45: IRQ13
irq13_:
 ;;cli
 push byte 0
 push byte 45
 jmp irq_common_stub
; 46: IRQ14
irq14_:
 ;;cli
 push byte 0
 push byte 46
 jmp irq_common_stub
; 47: IRQ15
irq15_:
 ;;cli
 push byte 0
 push byte 47
 jmp irq_common_stub

irq_common_stub:
 pusha
 push ds
 push es
 push fs
 push gs
 mov ax, 0x10
 mov ds, ax
 mov es, ax
 mov fs, ax
 mov gs, ax
 mov eax, esp
 push eax
 ;mov eax, irq_handler_
 ;call eax
 call irq_handler_
 mov si, debug
 ;call puts_
 pop eax
 pop gs
 pop fs
 pop es
 pop ds
 popa
 add esp, 8
 ;iret
 ret
;;
; void _cdecl x86_div64_32(uint64_t dividend, uint32_t divisor, uint64_t* quotientOut, uint32_t* remainderOut);
;
; puts:
    ; ; save registers we will modify
    ; push si
    ; push ax
    ; push bx

; .loop:
    ; lodsb               ; loads next character in al
    ; or al, al           ; verify if next character is null?
    ; jz .done

    ; mov ah, 0x0E        ; call bios interrupt
    ; mov bh, 0           ; set page number to 0
    ; int 0x10

    ; jmp .loop

; .done:
    ; pop bx
    ; pop ax
    ; pop si    
    ; ret

_x86_div64_32:

    ; make new call frame
    push bp             ; save old call frame
    mov bp, sp          ; initialize new call frame

    push bx

    ; divide upper 32 bits
    mov eax, [bp + 8]   ; eax <- upper 32 bits of dividend
    mov ecx, [bp + 12]  ; ecx <- divisor
    xor edx, edx
    div ecx             ; eax - quot, edx - remainder

    ; store upper 32 bits of quotient
    mov bx, [bp + 16]
    mov [bx + 4], eax

    ; divide lower 32 bits
    mov eax, [bp + 4]   ; eax <- lower 32 bits of dividend
                        ; edx <- old remainder
    div ecx

    ; store results
    mov [bx], eax
    mov bx, [bp + 18]
    mov [bx], edx

    pop bx

    ; restore old call frame
    mov sp, bp
    pop bp
    ret

; int 10h ah=0Eh
; args: character, page
;
_x86_Video_WriteCharTeletype:
    
    ; make new call frame
    push bp             ; save old call frame
    mov bp, sp          ; initialize new call frame

    ; save bx
    push bx

    ; [bp + 0] - old call frame
    ; [bp + 2] - return address (small memory model => 2 bytes)
    ; [bp + 4] - first argument (character)
    ; [bp + 6] - second argument (page)
    ; note: bytes are converted to words (you can't push a single byte on the stack)
    mov ah, 0Eh
    mov al, [bp + 4]
    mov bh, [bp + 6]

    int 10h

    ; restore bx
    pop bx

    ; restore old call frame
    mov sp, bp
    pop bp
    ret
_debugasmfunc:
	push ax				; push reg to ram
	push bx
	pop ax 				; pop reg from ram
	pop bx
irqtest_:
	call irq_install_
	ret

section .data
system_timer_fractions:  resd 1          ; Fractions of 1 ms since timer initialized
system_timer_ms:         resd 1          ; Number of whole ms since timer initialized
IRQ0_fractions:          resd 1          ; Fractions of 1 ms between IRQs
IRQ0_ms:                 resd 1          ; Number of whole ms between IRQs
IRQ0_frequency:          resd 1          ; Actual frequency of PIT
PIT_reload_value:        resw 1          ; Current PIT reload value
debug:  db 'debugmsg', ENDL ,0