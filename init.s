.equ GPBCON,0x56000010
.equ GPBDAT,0x56000014

.section .text
.globl _start
.globl myhello
.globl xmain
_start:
	ldr r0,=0x53000000
	mov r1,#0x0
	str r1,[r0]
	bl initmem		

	ldr sp,=0x33000000
	adr lr,loop1
	ldr pc,=xmain
loop1:
    b loop1
initmem:			
	ldr r0, =0x48000000	
	ldr r1, =0x48000034
	adr r2, memdata	
initmemloop:
	ldr r3, [r2], #4
	str r3, [r0], #4
	teq r0, r1
	bne initmemloop
	mov pc,lr
memdata:
	.word	0x22000000 		
	.word	0x00000700	
	.word	0x00000700
	.word	0x00000700
	.word	0x00000700  	
	.word	0x00000700	
	.word	0x00000700
	.word	0x00018005		
	.word	0x00018005	
	.word	0x008e07a3
	.word	0x000000b1
	.word	0x00000030		
	.word	0x00000030	
