CROSS =  arm-unknown-linux-gnueabi-
CFLAGS = -nostdlib -g 
  
uart.bin:init.s xmain.c 
	${CROSS}gcc $(CFLAGS) -c -o init.o init.s  
	${CROSS}gcc $(CFLAGS) -c -o xmain.o xmain.c  
	${CROSS}ld -Tuart.lds init.o xmain.o -o uart.elf  
	${CROSS}objcopy --only-keep-debug -O binary -S uart.elf uart.bin  
	rm -f  *.o  

clean:  
	rm -f *.elf *.o  
	rm -f uart.bin

