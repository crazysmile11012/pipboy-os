#include "system.h"
extern void idt_load();
// An entry entry in the IDT table
struct idt_entry{
 unsigned short base_lo;
 unsigned short sel; // The kernel segment
 unsigned char always0; // This value is always ... 0!
 unsigned char flags;
 unsigned short base_hi;
};//__attribute__((packed)); // We use the smalest alignment, meaning no zeros between
// our variables.
struct idt_ptr{
 unsigned short limit;
 unsigned int base;
}; ////////////__attribute__((packed));
// The IDT with 256 entries. We will only use 32 entries. If any other
// IDT entry is called it will cause an "Unhandled Interrupt" exception.
struct idt_entry idt[256];
struct idt_ptr idtp;
// This extern function is defined in start.asm. It initializes a new
// IDT (idtp). This can once again only be done in assembler.
//extern void idt_load();
// Set an entry in the IDT.
void idt_set_gate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags)
{
 // IR's base address
 idt[num].base_lo = (base & 0xFFFF);
 idt[num].base_hi = (base >> 16) & 0xFFFF;
// Other properties are set here
 idt[num].sel = sel;
 idt[num].always0 = 0;
 idt[num].flags = flags;
}
// Initialize the IDT
void idt_install()
{
 // Sets the max address of the IDT
 idtp.limit = (sizeof (struct idt_entry) * 256) - 1;
// Sets the start address of the IDT
 idtp.base = &idt;
 // Set the entire IDT to zero
 memset(&idt, 0, sizeof(struct idt_entry) * 256);
// Here you can add new ISRs to the IDT via idt_set_gate
 // Tells the Processor where the new IDT can be found
 idt_load();
}
