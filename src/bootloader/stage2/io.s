global inb
global outb
outb:
        mov al, [esp + 8]   ; move the data to be sent into the al register
        mov dx, [esp + 4]   ; move the address of the I/O port into the dx register
        out dx, al          ; send the data to the I/O port
        ret                 ; return to the calling function
inb:
        mov dx, [esp + 4]       ; move the address of the I/O port to the dx register
        in  al, dx              ; read a byte from the I/O port and store it in the al register
        ret                     ; return the read byte
