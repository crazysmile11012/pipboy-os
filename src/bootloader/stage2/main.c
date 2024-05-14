#include "stdint.h"
#include "stdio.h"
#include "system.h"
#include "x86.h"
#define FB_COMMAND_PORT         0x3D4
#define FB_DATA_PORT            0x3D5

/* The I/O port commands */
#define FB_HIGH_BYTE_COMMAND    14
#define FB_LOW_BYTE_COMMAND     15
#define FB_GREEN 2
#define FB_DARK_GREY 8

#define FB_BASE_ADDRESS 0xB8000
#define SERIAL_COM1_BASE                0x3F8      /* COM1 base port */
#define KBD_DATA_PORT   0x60
#define SERIAL_DATA_PORT(base)          (base)
#define SERIAL_FIFO_COMMAND_PORT(base)  (base + 2)
#define SERIAL_LINE_COMMAND_PORT(base)  (base + 3)
#define SERIAL_MODEM_COMMAND_PORT(base) (base + 4)
#define SERIAL_LINE_STATUS_PORT(base)   (base + 5)
#define SERIAL_LINE_ENABLE_DLAB         0x80
#define KEYBOARD_MAX_ASCII 83 
/* misc memory addresses*/
#define SPK_ADDR 0x0
#define MIC_ADDR 0x0
#define GPS_X_ADDR 0x0
#define GPS_Y_ADDR 0x0
unsigned char mouse_cycle=0;     //unsigned char
signed char mouse_byte[3];    //signed char
signed char mouse_x=0;         //signed char
signed char mouse_y=0;         //signed char
char scancode;
int i;
//int ret1;
int o;
int input;
char msg[] = "handshake\n";
static char *fb = (char *)FB_BASE_ADDRESS;
void _cdecl cstart_(uint16_t bootDrive){
	driverloader();
	_status_();
	scancode = read_scan_code();
	keyboard_scan_code_to_ascii(scancode);
	loop();
	//irq_install();
	_asm("sti \r\n");
	
	for(;;);
	
};

void _status_(){
	_clear_(); //calls clear screen code
	puts("os distro: natewebos -> pipboyos                                       \r\n");
	puts("=########==============================================================\r\n");
	puts("I#STATUS#I WEAPONS I ARMOUR I CLOTHES I MISC I DATA I MAP I            \r\n");
	puts("=########==============================================================\r\n");
	puts(" BIOMETRIC DATA: NAN                                                   \r\n");
	puts(" ERR: bio driver not found                                             \r\n");
	puts(" contact 1-800-robco for support                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("====================================================================== \r\n");
	puts("I CAPS: NAN I NAME: NULL I LEVEL: NAN                      I           \r\n");
}
void _weapons_()
{
	_clear_(); //calls clear screen code
	puts("os distro: natewebos -> pipboyos                                       \r\n");
	puts("==========#########====================================================\r\n");
	puts("I STATUS I#WEAPONS#I ARMOUR I CLOTHES I MISC I DATA I MAP I            \r\n");
	puts("==========#########====================================================\r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("====================================================================== \r\n");
	puts("I CAPS: NAN I NAME: NULL I LEVEL: NAN                      I           \r\n"); //nice
}
void _armour_()
{
	_clear_(); //calls clear screen code
	puts("os distro: natewebos -> pipboyos\r\n");
	puts("====================########==========================================\r\n");
	puts("I STATUS I WEAPONS I#ARMOUR#I CLOTHES I MISC I DATA I MAP I           \r\n");
	puts("====================########==========================================\r\n");
	puts("                                                                      \r\n");
	puts("                                                                      \r\n");
	puts("                                                                      \r\n");
	puts("                                                                      \r\n");
	puts("                                                                      \r\n");
	puts("                                                                      \r\n");
	puts("                                                                      \r\n");
	puts("                                                                      \r\n");
	puts("                                                                      \r\n");
	puts("                                                                      \r\n");
	puts("                                                                      \r\n");
	puts("                                                                      \r\n");
	puts("                                                                      \r\n");
	puts("                                                                      \r\n");
	puts("                                                                      \r\n");
	puts("                                                                      \r\n");
	puts("                                                                      \r\n");
	puts("                                                                      \r\n");
	puts("======================================================================\r\n");
	puts("I CAPS: NAN I NAME: NULL I LEVEL: NAN                      I          \r\n"); //nice
}
void _clothes_()
{
	_clear_(); //calls clear screen code
	puts("os distro: natewebos -> pipboyos\r\n");
	puts("=============================#########=================================\r\n");
	puts("I STATUS I WEAPONS I ARMOUR I#CLOTHES#I MISC I DATA I MAP I            \r\n");
	puts("=============================#########=================================\r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("====================================================================== \r\n");
	puts("I CAPS: NAN I NAME: NULL I LEVEL: NAN                    I             \r\n"); //nice
}
void _misc_()
{
	_clear_(); //calls clear screen code
	puts("os distro: natewebos -> pipboyos\r\n");
	puts("=======================================######==========================\r\n");
	puts("I STATUS I WEAPONS I ARMOUR I CLOTHES I#MISC#I DATA I MAP I            \r\n");
	puts("=======================================######==========================\r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("====================================================================== \r\n");
	puts("I CAPS: NAN I NAME: NULL I LEVEL: NAN                     I            \r\n"); //nice
}
void _data_()
{
	_clear_(); //calls clear screen code
	puts("os distro: natewebos -> pipboyos\r\n");
	puts("==============================================######===================\r\n");
	puts("I STATUS I=WEAPONS I ARMOUR I CLOTHES I MISC I#DATA#I MAP I            \r\n");
	puts("==============================================######===================\r\n");
	puts("NULL                                                                   \r\n");
	puts("MISC QUESTS V                                                          \r\n");
	puts("NULL                                                                   \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("====================================================================== \r\n");
	puts("I CAPS: NAN I NAME: NULL I LEVEL: NAN                      I           \r\n"); //nice
}
void _map_()
{
	_clear_(); //calls clear screen code
	puts("os distro: natewebos -> pipboyos\r\n");
	puts("=====================================================#####=============\r\n");
	puts("I STATUS I WEAPONS I ARMOUR I CLOTHES I MISC I DATA I#MAP#I            \r\n");
	puts("=====================================================#####=============\r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                   MAPDATA NOT FOUND FOR AREA                          \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("                                                                       \r\n");
	puts("====================================================================== \r\n");
	puts("I CAPS: NAN I NAME: NULL I LEVEL: NAN                      I           \r\n"); //nice
	
	
}
void _clear_()
{
	puts("\r\n");
	puts("\r\n");
	puts("\r\n");
	puts("\r\n");
	puts("\r\n");
	puts("\r\n");
	puts("\r\n");
	puts("\r\n");
	puts("\r\n");
	puts("\r\n");
	puts("\r\n");
	puts("\r\n");
	puts("\r\n");
	puts("\r\n");
	puts("\r\n");
	puts("\r\n");
	puts("\r\n");
	puts("\r\n");
	puts("\r\n");
	puts("\r\n");
	puts("\r\n");
	puts("\r\n");
	puts("\r\n");
	puts("\r\n");
	puts("\r\n");
	puts("\r\n");
	puts("\r\n");
	puts("\r\n");
	puts("\r\n");
	puts("\r\n");
	puts("\r\n");
	puts("\r\n");
	puts("\r\n");
	puts("\r\n");
	puts("\r\n");
	puts("\r\n");
	puts("\r\n");
	puts("\r\n");
	puts("\r\n");
	puts("\r\n");
	puts("\r\n");
	puts("\r\n");
	puts("\r\n");
	puts("\r\n");
	puts("\r\n");
	puts("\r\n");
	puts("\r\n");
	puts("\r\n");
	puts("\r\n");
	puts("\r\n");
	puts("\r\n");
	puts("\r\n");
	puts("\r\n");
	puts("\r\n");
	puts("\r\n");
}
void fb_write_cell(unsigned int i, char c, unsigned char fg, unsigned char bg)
    {
        char *fb = (char *) 0x000B8000;
        fb[i] = c;
        fb[i + 1] = ((fg & 0x0F) << 4) | (bg & 0x0F);
    }

    /** fb_move_cursor:
     *  Moves the cursor of the framebuffer to the given position
     *
     *  @param pos The new position of the cursor
     */
void fb_move_cursor(unsigned short pos)
    {
        outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
        outb(FB_DATA_PORT,    ((pos >> 8) & 0x00FF));
        outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
        outb(FB_DATA_PORT,    pos & 0x00FF);
		
    }
unsigned char inb(unsigned short port)
{
	char ret1;
	_asm("mov dx, port \r\n");
	_asm("in al, dx \r\n");
	_asm("mov ret1, al \r\n");
	return ret1;
}
void outb(unsigned short port, unsigned char data)
{
	_asm("mov al, data \r\n");
	_asm("mov dx, port \r\n");
	_asm("out dx, al \r\n");
	
}
int fb_write(char *buf, unsigned int len) {
  unsigned int indexToBuffer = 0;
  while (indexToBuffer < len) {
    fb_write_cell(indexToBuffer, buf[indexToBuffer], FB_GREEN, FB_DARK_GREY);
    fb_move_cursor(indexToBuffer);
    indexToBuffer++;
  }
  return 0;
}
void serial_configure_baud_rate(unsigned short com, unsigned short divisor)
    {
        outb(SERIAL_LINE_COMMAND_PORT(com),
             SERIAL_LINE_ENABLE_DLAB);
        outb(SERIAL_DATA_PORT(com),
             (divisor >> 8) & 0x00FF);
        outb(SERIAL_DATA_PORT(com),
             divisor & 0x00FF);
    }
void serial_configure_line(unsigned short com)
    {
        /* Bit:     | 7 | 6 | 5 4 3 | 2 | 1 0 |
         * Content: | d | b | prty  | s | dl  |
         * Value:   | 0 | 0 | 0 0 0 | 0 | 1 1 | = 0x03
         */
        outb(SERIAL_LINE_COMMAND_PORT(com), 0x03);
    }
	void serial_configure_fifo_buffer(unsigned short com) {
  /* Bit:     | 7 6 | 5  | 4 | 3   | 2   | 1   | 0 |
   * Content: | lvl | bs | r | dma | clt | clr | e |
   * Value:   | 1 1 | 0  | 0 | 0   | 1   | 1   | 1 | = 0xC7
   */
  outb(SERIAL_FIFO_COMMAND_PORT(com), 0xC7);
}
void serial_configure_modem(unsigned short com) {
  /* Bit:     | 7 | 6 | 5  | 4  | 3   | 2   | 1   | 0   |
   * Content: | r | r | af | lb | ao2 | ao1 | rts | dtr |
   * Value:   | 0 | 0 | 0  | 0  | 0   | 0   | 1   | 1 | = 0x03
   */
  outb(SERIAL_MODEM_COMMAND_PORT(com), 0x03);
}
int serial_is_transmit_fifo_empty(unsigned int com)
    {
        /* 0x20 = 0010 0000 */
        return inb(SERIAL_LINE_STATUS_PORT(com)) & 0x20;
    }
int serial_write(unsigned short com, char *buf, unsigned int len) {
  unsigned int indexToBuffer = 0;
  while (indexToBuffer < len) {
    if (serial_is_transmit_fifo_empty(com)) {
      serial_write_byte(com, buf[indexToBuffer]);
      indexToBuffer++;
    }
  }
  return 0;
}
void serial_write_byte(unsigned short port, char byteData) {
  outb(port, byteData);
}
void serial_configure(unsigned short port, unsigned short baudRate) {
  serial_configure_baud_rate(port, baudRate);
  serial_configure_line(port);
  serial_configure_fifo_buffer(port);
  serial_configure_modem(port);
}
void segments_load_gdt(){
	//_asm("lgdt [esp + 4] \r\n");
}
void segments_load_registers()
{
	/*
	_asm("mov ax, 0x10 \r\n");
	_asm("mov ds, ax \r\n");
	_asm("mov ss, ax \r\n");
	_asm("mov es, ax \r\n");
	_asm("mov fs, ax \r\n");
	_asm("mov gs, ax \r\n");
	*/
}
int read_scan_code(void)
    {
        return inb(KBD_DATA_PORT);
    }

void loop(){
	char scancode;//declare vars out of loop so it does not flood the ram
	while(true){
		
		//watch out for memory leaks here :)
		scancode = read_scan_code();
		//puts(scancode);
		
		//printf(mouse_x);
		//puts("\r\n");
		//printf(mouse_y);
		//puts("\r\n");
		keyboard_scan_code_to_ascii(scancode);
	}
	
}
int lastpage = 1;
char lastchar = '0';
void keyboard_scan_code_to_ascii(char scan_code)
{
	char ascii[255] =
	{
		 ' ', '1', '2', '3', '4', '5', '6',		// 0 - 7
		'7', '8', '9', '0', '-', '=', ' ', ' ',		// 8 - 15
		'q', 'w', 'e', 'r', 't', 'y', 'u', 'i',		// 16 - 23
		'o', 'p', '[', ']', '\n', ' ', 'a', 's',	// 24 - 31
		'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',		// 32 - 39
		'\'', '`', ' ', '\\', 'z', 'x', 'c', 'v',	// 40 - 47
		'b', 'n', 'm', ',', '.', '/', ' ', '*',		// 48 - 55
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',		// 56 - 63
		' ', ' ', ' ', ' ', ' ', ' ', ' ', '7',		// 64 - 71
		'8', '9', '-', '4', '5', '6', '+', '1',		// 72 - 79
		'2', '3', '0', '.'	// 80 - 83
	};
	

	
	if (ascii[scan_code-1] == '\0'){
		//do nothing
	
	}else if (ascii[scan_code-1] == '`'){//backspace
		puts("\b");
	
	}else if (ascii[scan_code-1] == '1'){//page1
		if(lastpage != 1){
			_status_();
			lastpage = 1;
		}
	}else if (ascii[scan_code-1] == '2'){//page2
		if(lastpage != 2){
			_weapons_();
			lastpage = 2;
			
		}
	
	}else if (ascii[scan_code-1] == '3'){//page3
		if(lastpage != 3){
			_armour_();
			lastpage = 3;
		}
	
	}else if (ascii[scan_code-1] == '4'){//page4
		if(lastpage != 4){
			_clothes_();
			lastpage = 4;
		}
	
	}else if (ascii[scan_code-1] == '5'){//page5
		if(lastpage != 5){
			_misc_();
			lastpage = 5;
		}
	
	}else if (ascii[scan_code-1] == '6'){//page6
		if(lastpage != 6){
			_data_();
			lastpage =6;
		}
	
	}else if (ascii[scan_code-1] == '7'){//page7
		if(lastpage != 7){
			_map_();
			lastpage = 7;
		}
	
	}else if (ascii[scan_code-1] == '8'){//serialcom
		if(lastpage != 8){
			//serial_write(0x3f8,msg,4); // serialtest
			//outb(0x2F8,"D#L");
			lastpage = 8;
		}
	
	}else if (ascii[scan_code-1] == '9'){//page9
		if(lastpage != 9){
			// run holotape program
			
			
			lastpage = 9;
		}
	
	}else{
		//printf("%c",ascii[scan_code-1]);
		if(lastpage == 1){
			if(ascii[scan_code-1]=='r'){
				//radaway
				if (lastchar != 'r'){
					lastchar = 'r';
					_status_();
					puts("radaway");
					
				}
			}else if(ascii[scan_code-1]=='e'){
				//stim
				if (lastchar != 'e'){
					lastchar = 'e';
					_status_();
					puts("stim");
					
				}
			}
		}
		if(lastpage == 2){
			if(ascii[scan_code-1]=='r'){
				//radaway
				if (lastchar != 'r'){
					lastchar = 'r';
					_weapons_();
					puts("drop");
					
				}
			}else if(ascii[scan_code-1]=='e'){
				//stim
				if (lastchar != 'e'){
					lastchar = 'e';
					_weapons_();
					puts("equip");
					
				}
			}
		}
		if(lastpage == 3){
			if(ascii[scan_code-1]=='r'){
				//radaway
				if (lastchar != 'r'){
					lastchar = 'r';
					_armour_();
					puts("drop");
					
				}
			}else if(ascii[scan_code-1]=='e'){
				//stim
				if (lastchar != 'e'){
					lastchar = 'e';
					_armour_();
					puts("equip");
					
				}
			}
		}
		if(lastpage == 4){
			if(ascii[scan_code-1]=='r'){
				//radaway
				if (lastchar != 'r'){
					lastchar = 'r';
					_clothes_();
					puts("drop");
					
				}
			}else if(ascii[scan_code-1]=='e'){
				//stim
				if (lastchar != 'e'){
					lastchar = 'e';
					_clothes_();
					puts("equip");
					
				}
			}
		}
		if(lastpage == 5){
			
		}
		if(lastpage == 6){
			
		}
		if(lastpage == 7){
			
		}
	
	}
	
}

//Mouse.inc by SANiK
//License: Use as you wish, except to cause damage


//Mouse functions
void mouse_handler(struct regs *a_r) //struct regs *a_r (not used but just there)
{
  switch(mouse_cycle)
  {
    case 0:
      mouse_byte[0]=inb(0x60);
      mouse_cycle++;
      break;
    case 1:
      mouse_byte[1]=inb(0x60);
      mouse_cycle++;
      break;
    case 2:
      mouse_byte[2]=inb(0x60);
      mouse_x=mouse_byte[1];
      mouse_y=mouse_byte[2];
      mouse_cycle=0;
      break;
  }
}

inline void mouse_wait(unsigned char a_type) //unsigned char
{
  unsigned int _time_out=100000; //unsigned int
  if(a_type==0)
  {
    while(_time_out--) //Data
    {
      if((inb(0x64) & 1)==1)
      {
        return;
      }
    }
    return;
  }
  else
  {
    while(_time_out--) //Signal
    {
      if((inb(0x64) & 2)==0)
      {
        return;
      }
    }
    return;
  }
}

inline void mouse_write(unsigned char a_write) //unsigned char
{
  //Wait to be able to send a command
  mouse_wait(1);
  //Tell the mouse we are sending a command
  outb(0x64, 0xD4);
  //Wait for the final part
  mouse_wait(1);
  //Finally write
  outb(0x60, a_write);
}

unsigned char mouse_read()
{
  //Get's response from mouse
  mouse_wait(0);
  return inb(0x60);
}

void mouse_install()
{
  unsigned char _status;  //unsigned char

  //Enable the auxiliary mouse device
  mouse_wait(1);
  outb(0x64, 0xA8);
 
  //Enable the interrupts
  mouse_wait(1);
  outb(0x64, 0x20);
  mouse_wait(0);
  _status=(inb(0x60) | 2);
  mouse_wait(1);
  outb(0x64, 0x60);
  mouse_wait(1);
  outb(0x60, _status);
 
  //Tell the mouse to use default settings
  mouse_write(0xF6);
  mouse_read();  //Acknowledge
 
  //Enable the mouse
  mouse_write(0xF4);
  mouse_read();  //Acknowledge

  //Setup the mouse handler
  //irq_install_handler(12, mouse_handler);
  irq_install(12,mouse_handler);
  //init8259APIC();
}
void *memcpy(void *dest, const void *src, size_t count)
{
 const char *sp = (const char *)src;
 char *dp = (char *)dest;
 for(; count != 0; count--) *dp++ = *sp++;
 return dest;
};
// set count bytes in dest to val
void *memset(void *dest, char val, size_t count)
{
 char *temp = (char *)dest;
 for( ; count != 0; count--) *temp++ = val;
 return dest;
};
// Same as above, but this time, we're working with a 16-bit 'val' and dest pointer.
unsigned short *memsetw(unsigned short *dest, unsigned short val, size_t count)
{
 unsigned short *temp = (unsigned short *)dest;
 for( ; count != 0; count--) *temp++ = val;
 return dest;
};
// Returns the length of a character array.
size_t strlen(const char *str){
 size_t retval;
 for(retval = 0; *str != '\0'; str++) retval++;
 return retval;
};
// Reading from IO ports

/*
unsigned char inportb (unsigned short _port)
{
 unsigned char rv;
 _asm("inb %1, %0" : "=a" (rv) : "dN" (_port));
 return rv;
};
// Writing to IO ports
void outputb (unsigned short _port, unsigned char _data){
 _asm("outb %1, %0" : : "dN" (_port), "a" (_data));
};
*/
void driverloader(){
	//put your driver function calls here
	//usbtest();
	init8259APIC();
	//mouse driver disabled for the time being
	//mouse_install();//install mouse driver @ irq 12
};
void usbtest(){
	unsigned short inputport = 0x0001;
	unsigned char outputport;
	outputport = inb(inputport);
	printf("%c",outputport);
	
};
void init8259APIC(){
	//init 8259A PIC legacy device
	// most motherboards are backward compatable
	// ps2, serial,diskette, cmos, parallel port, esc...
	__asm("	mov al, 0x11 \r\n");
	__asm("	out 0x20, al \r\n");
	__asm("	out 0xA0, al \r\n");
	__asm("	mov al, 0x20 \r\n");
	__asm("	out 0x21, al \r\n");
	__asm("	mov al, 0x28 \r\n");
	__asm("	out 0xA1, al \n");
	__asm("	mov al, 0x4 \n");
	__asm("	out 0x21, al \n");
	__asm("	mov al, 0x2 \n");
	__asm("	out 0xA1, al \n");
	__asm("	mov al, 0x1 \n");
	__asm("	out 0x21, al \n");
	__asm("	out 0xA1, al \n");
	__asm("	mov al, 0x0 \n");
	__asm("	out 0x21, al \r\n");
	__asm("	out 0xA1, al \r\n");
};


