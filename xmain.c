/* xmain.c */
/* GPIO registers */
#define	GPHCON				(*(volatile unsigned long *)0x56000070)
#define	GPHDAT				(*(volatile unsigned long *)0x56000074)
#define	GPHUP				(*(volatile unsigned long *)0x56000078)
/*UART registers*/
#define	ULCON0				(*(volatile unsigned long *)0x50000000)
#define	UCON0				(*(volatile unsigned long *)0x50000004)
#define	UFCON0			 	(*(volatile unsigned long *)0x50000008)
#define	UMCON0				(*(volatile unsigned long *)0x5000000c)
#define	UTRSTAT0			(*(volatile unsigned long *)0x50000010)
#define	UTXH0		 		(*(volatile unsigned char *)0x50000020)
#define	URXH0		 		(*(volatile unsigned char *)0x50000024)
#define	UBRDIV0				(*(volatile unsigned long *)0x50000028)
 
#define	TXD0READY	(1<<2)  
#define	RXD0READY	(1)	
	
/* UART串口初始化 */
void uart_init( )
{
	GPHCON |= 0xa0;		//GPH2,GPH3 used as TXD0,RXD0
	GPHUP	 = 0x0;		//GPH2,GPH3内部上拉
	ULCON0	 = 0x03;	//8N1	
	UCON0	 = 0x05;	//查询方式为轮询或中断;时钟选择为PCLK
	UFCON0 = 0x00;		//不使用FIFO
	UMCON0 = 0x00;		//不使用流控
	UBRDIV0 = 12;		//波特率为57600,PCLK=12Mhz
}

/* UART串口单个字符打印函数 */
extern void putc(unsigned char c)
{
	while( ! (UTRSTAT0 & TXD0READY) );
	UTXH0 = c;
}

/* UART串口接受单个字符函数 */
extern unsigned char getc(void)
{
	while( ! (UTRSTAT0 & RXD0READY) );
	return URXH0;
}

/* UART串口字符串打印函数 */
extern int printk(const char* str)
{
	int i = 0;
	while( str[i] ){
		putc( (unsigned char) str[i++] );
	}
	return i;
}

__inline void delay(int msec)
{
	int i, j;
	for(i = 1000; i > 0; i--)
		for(j = msec*10; j > 0; j--)
			/* do nothing */;
}


void xmain()
{
	int counter=10;
	uart_init();
	while(counter-- > 0)
    {
    	delay(3000);
    	printk("Uart\r\n");
    }
}

