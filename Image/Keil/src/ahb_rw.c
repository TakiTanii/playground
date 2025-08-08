
#include "print_led.h"

/* 8 bit word AHB read/write functions */
void write_ahb8(unsigned long ahb_addr, char write_value) {
    *(char *)ahb_addr = write_value;
}

char read_ahb8(unsigned long ahb_addr) {
    char retval;
    retval = *(char *)ahb_addr;
    return retval;
}


/* 16 bit word AHB read/write functions */
void write_ahb16(unsigned long ahb_addr, unsigned short write_value) {
    *(unsigned short *)ahb_addr = write_value;
}

unsigned short read_ahb16(unsigned long ahb_addr) {
    unsigned short retval;
    retval = *(unsigned short *)ahb_addr;
    return retval;
}

/* 32 bit word AHB read/write functions */
void write_ahb32(unsigned long ahb_addr, volatile unsigned long write_value) {
    *(volatile unsigned long *)ahb_addr = write_value;
}

unsigned long read_ahb32(unsigned long ahb_addr) {
    volatile unsigned long retval;
    retval = *(volatile unsigned long *)ahb_addr;
    return retval;
}

//////
void read_cmp8(int addr,char val) {
    char rdval;
    //__asm { LDRB rdval, [addr] }
    rdval = *(char *)addr;   // read value from data memory
    if(rdval != val) {
	printf_led("read data error at %x,data read is %x,expected data is %x \n",addr,rdval,val);
    }	
}

void read_cmp16(int addr,unsigned short val) {
    unsigned short rdval;
    //__asm { LDRH rdval, [addr] }
    rdval = *(unsigned short *)addr;   // read value from data memory
    if(rdval != val) {
	printf_led("read data error at %x,data read is %x,expected data is %x \n",addr,rdval,val);
    }	
}
void read_cmp16_protect(int addr,unsigned short val) {                 // by liuzhitong 2020.1.6
    unsigned short rdval;
    //__asm { LDRH rdval, [addr] }
    rdval = *(unsigned short *)addr;   // read value from data memory
    if(rdval != val) {
	printf_led("read data  at %x,data read is %x,expected data is %x \n",addr,rdval,val);
    }	
}

void read_cmp16_opt(int addr,unsigned short val) {
    unsigned short rdval;
    //__asm { LDRH rdval, [addr] }
    rdval = *(unsigned short *)addr;   // read value from data memory
    if(   (rdval&0xffff) != (   ( (~(val<<8))&0xff00 )+(val&0x00ff)   )   ) {
	printf_led("read data error at %x,data read is %x,expected data is %x \n",addr,rdval,(((~(val<<8))&0xff00)+(val&0x00ff)));
    }	
	//printf_led("at %x,data read is %x,expected data is %x \n",addr,rdval,(((~(val<<8))&0xff00)+(val&0x00ff)) );
}

void read_cmp32(int addr,unsigned int val) {
    unsigned int rdval;
    rdval = *(unsigned int *)addr;   // read value from data memory
    if(rdval != val) {
	printf_led("read data error at %x,data read is %x,expected data is %x \n",addr,rdval,val);
    }	
}
    
//check bit n
void poll_ahb32(int addr,int n) {
    int rdval;
    do{
        rdval = *(int *)addr;
        rdval &= (0x01<<n);
    }while(rdval==0);
}
