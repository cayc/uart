OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")  
OUTPUT_ARCH(arm)  
ENTRY(_start)  

SECTIONS{  
. = .;  
.text : {  
	*(.text)  
	*(.rodata)  
} 

.data ALIGN(4): {  
	*(.data)  
}  

.bss ALIGN(4): {  
	*(.bss)  
}  
}  
