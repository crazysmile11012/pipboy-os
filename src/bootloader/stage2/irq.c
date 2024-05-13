#include "system.h"
// We define these Interrupt Service Requests on our own
// to point to a special IRQ handler instead of the regular
// fault_handler.
/*
extern void irq0();
extern void irq1();
extern void irq2();
extern void irq3();
extern void irq4();
extern void irq5();
extern void irq6();
extern void irq7();
extern void irq8();
extern void irq9();
extern void irq10();
extern void irq11();
extern void irq12();
extern void irq13();
extern void irq14();
extern void irq15();
*/
// Pointer array to handle custom ORQ handlers of a special IRQ
void *irq_routines[16] =
{
 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0
};
// With this function we can define a custom IRQ handler
// for an IRQ. So we manage the target functions that are called
// when an interrupt occurs on our own.
void irq_install_handler(int irq, void (*handler)(struct regs *r))
{
 irq_routines[irq] = handler;
}
// By setting the pointer of an interrupt routine to 0
// we will unload the handler.
void irq_uninstall_handler(int irq)
{
 irq_routines[irq] = 0;
};
// Here we remap our IRQs (0-15 to 32-47) as explained in the
// tutorial.
void irq_remap(void)
{
 outb(0x20, 0x11);
 outb(0xA0, 0x11);
 outb(0x21, 0x20);
 outb(0xA1, 0x28);
 outb(0x21, 0x04);
 outb(0xA1, 0x02);
 outb(0x21, 0x01);
 outb(0xA1, 0x01);
 outb(0x21, 0x0);
 outb(0xA1, 0x0);
}
// Identical to defining the exception handlers we will
// install the appropriate Interrupt Service Routines to the
// corresponding entries in the IDT.
void irq_install()
{
 irq_remap();
 /*
 idt_set_gate(32, (unsigned)irq0, 0x08, 0x8E);
 idt_set_gate(33, (unsigned)irq1, 0x08, 0x8E);
 idt_set_gate(34, (unsigned)irq2, 0x08, 0x8E);
 idt_set_gate(35, (unsigned)irq3, 0x08, 0x8E);
 idt_set_gate(36, (unsigned)irq4, 0x08, 0x8E);
 idt_set_gate(37, (unsigned)irq5, 0x08, 0x8E);
 idt_set_gate(38, (unsigned)irq6, 0x08, 0x8E);
 idt_set_gate(39, (unsigned)irq7, 0x08, 0x8E);
 idt_set_gate(40, (unsigned)irq8, 0x08, 0x8E);
 idt_set_gate(41, (unsigned)irq9, 0x08, 0x8E);
 idt_set_gate(42, (unsigned)irq10, 0x08, 0x8E);
 idt_set_gate(43, (unsigned)irq11, 0x08, 0x8E);
 idt_set_gate(44, (unsigned)irq12, 0x08, 0x8E);
 idt_set_gate(45, (unsigned)irq13, 0x08, 0x8E);
 idt_set_gate(46, (unsigned)irq14, 0x08, 0x8E);
 idt_set_gate(47, (unsigned)irq15, 0x08, 0x8E);
 */
}
// Each service routine of an Interrupt Request points to this
// function. After handling the ISR we need to tell the interrupt
// controllers that we are done handling the interrupt. As said
// in the tutorial this happens by putting the hex value 0x20 to
// the adress 0x20 for the first controller and for the second
// controller we write 0x20 to 0xA0.
// If the second controller (IRQ from 8 to 15) receives and interrupt
// we need to tell the first controller, too, that we have finished
// the interrupt routine.
void irq_handler(struct regs *r)
{
// Blank function pointer
 void (*handler)(struct regs *r);
 // If we have a routine defined for this interrupt call it!
 handler = irq_routines[r->int_no - 32];
 if (handler)
 {
 handler(r);
 }
// Here we are already done with the handling of our interrupt!

// If the entry in the IDT that we called had an index >= 40
// we will have to send an "End of Interrupt" (0x20) to the
// second controller.
 if (r->int_no >= 40)
 {
 outb(0xA0, 0x20);
 }
// In both cases we need to tell the first controller that
// we are done handling our Interrupt Routine.
 outb(0x20, 0x20);
}
