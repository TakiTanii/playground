#include "all.h"

#define DC_CMD  0
#define DC_DATA 1

#define IMG_W  24
#define IMG_H  31

#define BIG
//#define SMALL

#ifdef SMALL
#define CMR_W  100
#define CMR_H  100
#define LCD_W  128
#define LCD_H  160 
#endif

#ifdef BIG 
#define CMR_W  160
#define CMR_H  160
#define LCD_W  320
#define LCD_H  240
#endif

void LCD_Init_GPIO (void)
{
	//GPIOA->AFRL|=0x10110000;
	GPIOA->AFRL|=0x11110010;
	GPIOA->DIRR|=0xFF;
	GPIOA->BSRR|=0xFF;
	GPIOA->PUPDR |= 0x00;
	GPIOF->AFRL|=0x1000;
	dly(400000);
}

void LCD_Init_SPI (void)
{
	RCC_SPI1EN(1);
	
    SPI_FRF     	(0x00);	// SPI
    SPI_SPI_FRF 	(0x00);	// Std_SPI
    SPI_TMOD   		(0x01);	// To
	
    SPI_INST_L  	(0x00);	// DC_CMD   0 bit
    SPI_ADDR_L  	(0x00);	// Addr  0 bit 
    SPI_DFS32       (0x07); // DC_DATA  8 bit
	
    SPI_SER         (0x01);
    SPI_SSTE        (0x00); // No Toogle
	SPI_BAUDR       (0x02);
    SPI_TRANS_TYPE  (0x00); // Std_DC_CMD Std_ADDR
	SPI_WAIT_CYCLES (0x02);
	
	ON();
}

void LCD_In_Pin (uint8_t num, uint8_t value)
{
	if (value)
		GPIOA->BSRR=0x1<<num;
	else
		GPIOA->BRR=0x1<<num;
}

void LCD_In_SPI (uint8_t sel, uint8_t tx)
{
	LCD_In_Pin(2,sel);
	//LCD_In_Pin(1,0);
	SPI_DR(tx);
	dly(1);
	//LCD_In_Pin(1,1);
}

void LCD_Init (void)
{
	LCD_In_Pin(0,0);
	dly(400);
	LCD_In_Pin(0,1);
	dly(400000);

	LCD_In_SPI(DC_CMD, 0x11);
	dly(400000);
	
	LCD_In_SPI(DC_CMD, 0xB1);
	LCD_In_SPI(DC_DATA, 0x00);
	LCD_In_SPI(DC_DATA, 0x08);
	LCD_In_SPI(DC_DATA, 0x05);
	
	LCD_In_SPI(DC_CMD, 0xB2);
	LCD_In_SPI(DC_DATA, 0x05);
	LCD_In_SPI(DC_DATA, 0x3A);
	LCD_In_SPI(DC_DATA, 0x3A);

	LCD_In_SPI(DC_CMD, 0xB3);
	LCD_In_SPI(DC_DATA, 0x05);
	LCD_In_SPI(DC_DATA, 0x3A);
	LCD_In_SPI(DC_DATA, 0x3A);	
	LCD_In_SPI(DC_DATA, 0x05);
	LCD_In_SPI(DC_DATA, 0x3A);
	LCD_In_SPI(DC_DATA, 0x3A);	
	
	LCD_In_SPI(DC_CMD, 0xB4);
	LCD_In_SPI(DC_DATA, 0x03);	
	
	LCD_In_SPI(DC_CMD, 0xC0);
	LCD_In_SPI(DC_DATA, 0x62);
	LCD_In_SPI(DC_DATA, 0x02);
	LCD_In_SPI(DC_DATA, 0x04);

	LCD_In_SPI(DC_CMD, 0xC1);
	LCD_In_SPI(DC_DATA, 0xC0);

	LCD_In_SPI(DC_CMD, 0xC2);
	LCD_In_SPI(DC_DATA, 0x0D);
	LCD_In_SPI(DC_DATA, 0x00);

	LCD_In_SPI(DC_CMD, 0xC3);
	LCD_In_SPI(DC_DATA, 0x8D);
	LCD_In_SPI(DC_DATA, 0x6A);
	
	LCD_In_SPI(DC_CMD, 0xC4);
	LCD_In_SPI(DC_DATA, 0x8D);
	LCD_In_SPI(DC_DATA, 0xEE);

	LCD_In_SPI(DC_CMD, 0xC5);
	LCD_In_SPI(DC_DATA, 0x08);

	LCD_In_SPI(DC_CMD, 0xE0);
	LCD_In_SPI(DC_DATA, 0x03);
	LCD_In_SPI(DC_DATA, 0x1B);
	LCD_In_SPI(DC_DATA, 0x12);
	LCD_In_SPI(DC_DATA, 0x11);
	LCD_In_SPI(DC_DATA, 0x3F);
	LCD_In_SPI(DC_DATA, 0x3A);
	LCD_In_SPI(DC_DATA, 0x32);
	LCD_In_SPI(DC_DATA, 0x34);
	LCD_In_SPI(DC_DATA, 0x2F);
	LCD_In_SPI(DC_DATA, 0x2B);
	LCD_In_SPI(DC_DATA, 0x30);
	LCD_In_SPI(DC_DATA, 0x3A);
	LCD_In_SPI(DC_DATA, 0x00);
	LCD_In_SPI(DC_DATA, 0x01);
	LCD_In_SPI(DC_DATA, 0x02);
	LCD_In_SPI(DC_DATA, 0x05);
	
	LCD_In_SPI(DC_CMD, 0xE1);
	LCD_In_SPI(DC_DATA, 0x03);
	LCD_In_SPI(DC_DATA, 0x1B);
	LCD_In_SPI(DC_DATA, 0x12);
	LCD_In_SPI(DC_DATA, 0x11);
	LCD_In_SPI(DC_DATA, 0x32);
	LCD_In_SPI(DC_DATA, 0x2F);
	LCD_In_SPI(DC_DATA, 0x2A);
	LCD_In_SPI(DC_DATA, 0x2F);
	LCD_In_SPI(DC_DATA, 0x2E);
	LCD_In_SPI(DC_DATA, 0x2C);
	LCD_In_SPI(DC_DATA, 0x35);
	LCD_In_SPI(DC_DATA, 0x3F);
	LCD_In_SPI(DC_DATA, 0x00);
	LCD_In_SPI(DC_DATA, 0x00);
	LCD_In_SPI(DC_DATA, 0x01);
	LCD_In_SPI(DC_DATA, 0x05);	

	LCD_In_SPI(DC_CMD, 0x3A);
	LCD_In_SPI(DC_DATA, 0x05);
	
	LCD_In_SPI(DC_CMD, 0x36);
	LCD_In_SPI(DC_DATA, 0x40);
	
	LCD_In_SPI(DC_CMD, 0x29);
	LCD_In_SPI(DC_CMD, 0X2C);
	
	LCD_In_Pin(2, 1);
}

void LCD_Screen_Area (uint16_t col0, uint16_t col1, uint16_t row0, uint16_t row1)
{
	LCD_In_SPI(DC_CMD, 0x2A);
	LCD_In_SPI(DC_DATA, col0>>8);
	LCD_In_SPI(DC_DATA, col0&0xFF);
	LCD_In_SPI(DC_DATA, col1>>8);
	LCD_In_SPI(DC_DATA, col1&0xFF);
	
	LCD_In_SPI(DC_CMD, 0x2B);
	LCD_In_SPI(DC_DATA, row0>>8);
	LCD_In_SPI(DC_DATA, row0&0xFF);
	LCD_In_SPI(DC_DATA, row1>>8);
	LCD_In_SPI(DC_DATA, row1&0xFF);
	
	LCD_In_SPI(DC_CMD, 0x2C);
}

void LCD_Screen_Pixel (uint8_t col, uint8_t row, uint8_t color0, uint8_t color1)
{
	LCD_Screen_Area(col, col, row ,row);
	LCD_In_SPI(DC_DATA, color0);
	LCD_In_SPI(DC_DATA, color1);
}

void LCD_Screen_Pixel_free (uint8_t color0, uint8_t color1)
{
	LCD_In_SPI(DC_DATA, color0);
	LCD_In_SPI(DC_DATA, color1);
}

void write_reg (uint8_t addr, uint8_t data)
{
	I2C1 -> STATUS = 0xFFFFFFFF;
	
	I2C_DIR     (0x00);
    I2C_DATACNT (0x02);
	I2C_CMD     (0x01);
    I2C_ADDR    (0x40);
	
	while (!(I2C1 -> STATUS & 0x8)){};
	I2C1 -> STATUS = 0x8;
	I2C_DATA(addr);
	
	//while (!(I2C1 -> STATUS & 0x1)){};
	I2C_DATA(data);
		
	while (!(I2C1 -> STATUS & 0x200)){};
    I2C1 -> STATUS = 0x200;		

	I2C1 -> STATUS = 0xFFFFFFFF;
}

void read_reg (uint8_t addr)
{
	I2C1 -> STATUS = 0xFFFFFFFF;
	I2C_DIR     (0x00);
    I2C_DATACNT (0x01);
	I2C_CMD     (0x01);
    I2C_ADDR    (0x40);

	while (!(I2C1 -> STATUS & 0x8)){};
	I2C1 -> STATUS = 0x8;
	I2C_DATA(addr);
	
	while (!(I2C1 -> STATUS & 0x200)){};
    I2C1 -> STATUS = 0x200;
		
	I2C_DIR     (0x01);
	I2C_DATACNT (0x01);
	I2C_CMD     (0x01);
    I2C_ADDR    (0x40);
	
	while (!(I2C1 -> STATUS & 0x8)){};
	I2C1 -> STATUS = 0x8;

	while (!(I2C1 -> STATUS & 0x200))
	{
		while (!(I2C1 -> STATUS & 0x100)){};
		I2C1 -> STATUS = 0x100;
		printf_led("\nRecv Data: %8X\n", I2C1->DATA);
	};
	
    I2C1 -> STATUS = 0x200;		
	
	I2C_CMD (0x05);
	I2C1 -> STATUS = 0xFFFFFFFF;
}

void camera_test (void)
{
// Set Camera
	I2C_T_SUDAT    (255);
    I2C_T_HDDAT    (255);
    I2C_T_SP       (2);
    I2C_T_SCLHI    (0x7FF);
	
    I2C_T_SCLRATIO (0);
    I2C_NOSTRETCH  (1);
    I2C_DMAEN      (0);
    I2C_MASTER     (1);
    I2C_ADDRESSING (0);
    I2C_IICEN      (1);
	
    I2C_PHASE_START (1);
    I2C_PHASE_ADDR  (1);
    I2C_PHASE_DATA  (1);
    I2C_PHASE_STOP  (1);

#ifdef SMALL
	
/////////////////////////////////////////////////////
//////////////////////   SYS   //////////////////////
/////////////////////////////////////////////////////	
	
	write_reg(0xFE, 0xA0); // Reset
	write_reg(0xFE, 0xA0);
	write_reg(0xFE, 0xA0);
	
	write_reg(0xF6, 0x00); // No TEST
//	write_reg(0xFA, 0x11); 
	write_reg(0xFC, 0x12); // Clock On
	
	write_reg(0xFE, 0x00);
	
	write_reg(0x49, 0x70); // AWB r gain
	write_reg(0x4A, 0x80); // AWB g gain
	write_reg(0x4B, 0x5D); // AWB b gain
	
	write_reg(0x03, 0x00); // CISCTL_exp[11:8]
	write_reg(0x04, 0xFA); // CISCTL_exp[7:0]
	write_reg(0x01, 0x41); // Hb
	write_reg(0x02, 0x12); // Vb
	write_reg(0x0F, 0x01); // ???
	write_reg(0x0D, 0x30); // ???
	write_reg(0x12, 0xC8); // ???
	write_reg(0x14, 0x55); // Dark CFA
	                       // ?? Spec: Updown and Mirror
	write_reg(0x15, 0x32); // 1:sdark 0:ndark
	                       // ???
	write_reg(0x16, 0x04); // ???
	write_reg(0x17, 0x19); // ???
	write_reg(0x1D, 0xB9); // ???
	write_reg(0x1F, 0x15); // 
	
	write_reg(0x7A, 0x00); // ???
	write_reg(0x7B, 0x14); // ???
	write_reg(0x7D, 0x36); // ???
	
	write_reg(0xFE, 0x10);  // CISCTL rst [4]	
	
/////////////////////////////////////////////////////
//////////////////////   ISP   //////////////////////
/////////////////////////////////////////////////////
	
	write_reg(0x20, 0x7E); // Default
	write_reg(0x22, 0xB8); // Auto except AWB 
	write_reg(0x24, 0x55); // Default
	write_reg(0x26, 0x83); // Open skin_en
						   // [5]Y_switch 
						   // [4]UV_switch 
						   // [2]skin_en	
//	write_reg(0x29, 0x10); // Disable ISP quiet mode

	write_reg(0x39, 0x00); // Crop window
	write_reg(0x3A, 0x80); 
	write_reg(0x3B, 0x00); // Width
	write_reg(0x3C, CMR_H); 
	write_reg(0x3E, CMR_W); // Height

/////////////////////////////////////////////////////
//////////////////////   BLK   //////////////////////
/////////////////////////////////////////////////////
	
	write_reg(0x2A, 0x2F); // Default
	write_reg(0x37, 0x46); // [4:0] blk_select_row
	                       // ???

/////////////////////////////////////////////////////
//////////////////////   GAIN   /////////////////////
/////////////////////////////////////////////////////
	
	write_reg(0x3F, 0x18); // Global gain

/////////////////////////////////////////////////////
//////////////////////   DNDD   /////////////////////
/////////////////////////////////////////////////////
	
	write_reg(0x50, 0x3C); // DN_b_mode
	write_reg(0x52, 0x4F); // Default
	write_reg(0x53, 0x81); // Default
	write_reg(0x54, 0x43); // Dark_Bright TH
	write_reg(0x56, 0x78); // DD_ratio
	write_reg(0x57, 0xAA); // DD_on_edge_th
	write_reg(0x58, 0xFF); // DD_is_bright_dark_th
	
/////////////////////////////////////////////////////
//////////////////////   ASDE   /////////////////////
/////////////////////////////////////////////////////
	
	write_reg(0x5B, 0x60); // DD&EE th
	write_reg(0x5C, 0x80); // 60/OT_th
	write_reg(0xAB, 0x28); 
	write_reg(0xAC, 0xB5);	
	
/////////////////////////////////////////////////////
/////////////////////   INTPEE   ////////////////////
/////////////////////////////////////////////////////
	
	write_reg(0x60, 0x45); 
	write_reg(0x62, 0x68); // ???
	write_reg(0x63, 0x13); // Edge Effect
	write_reg(0x64, 0x43); // Default

/////////////////////////////////////////////////////
//////////////////////   CC   ///////////////////////
/////////////////////////////////////////////////////
	
	write_reg(0x65, 0x13); // Y
	write_reg(0x66, 0x26);
	write_reg(0x67, 0x07);
	write_reg(0x68, 0xF5); // Cb
	write_reg(0x69, 0xEA);
	write_reg(0x6A, 0x21);
	write_reg(0x6B, 0x21); // Cr
	write_reg(0x6C, 0xE4);
	write_reg(0x6D, 0xFB);

/////////////////////////////////////////////////////
//////////////////////   YCP   //////////////////////
/////////////////////////////////////////////////////
	
	write_reg(0x81, 0x30); // Cb
	write_reg(0x82, 0x30); // Cr
	write_reg(0x83, 0x4A); // Luma contrast
	write_reg(0x85, 0x06); // Luma offset
	write_reg(0x8D, 0x78); // Edge dec sa
	write_reg(0x8E, 0x25); // Autogray

/////////////////////////////////////////////////////
//////////////////////   AEC   //////////////////////
/////////////////////////////////////////////////////
	
	write_reg(0x90, 0x38); // ??? 
	write_reg(0x92, 0x50); // Target
	write_reg(0x9D, 0x32); // STEP
	write_reg(0x9E, 0x61); // [7:4]margin  10fps
	write_reg(0x9F, 0xF4);
	write_reg(0xA3, 0x28); // pregain
	write_reg(0xA4, 0x01); 
	
/////////////////////////////////////////////////////
//////////////////////   AWB   //////////////////////
/////////////////////////////////////////////////////	
	
	write_reg(0xB1, 0x1E); // Y_to_C_diff
	write_reg(0xB3, 0x20); // C_max
	write_reg(0xBD, 0x70); // R_limit
	write_reg(0xBE, 0x58); // G_limit
	write_reg(0xBF, 0xA0); // B_limit

	write_reg(0xFE, 0x00); // Update for AWB
	
	write_reg(0x43, 0xA8); 
	write_reg(0xB0, 0xF2); 
	write_reg(0xB5, 0x40); 
	write_reg(0xB8, 0x05); 
	write_reg(0xBA, 0x60); 	

/////////////////////////////////////////////////////
//////////////////////   SPI   //////////////////////
/////////////////////////////////////////////////////

	write_reg(0xFE, 0x02);

	write_reg(0x01, 0x01); // SPI enable
	write_reg(0x02, 0x80); // LSB & Falling edge sample; DDR disable
	write_reg(0x03, 0x00); // 1-wire
	write_reg(0x04, 0x20); // [4] master_outformat
	write_reg(0x0A, 0x00); // Data ID, 0x00-YUV422, 0x01-RGB565
	write_reg(0x13, 0x10);
	write_reg(0x24, 0x00); // [1]sck_always [0]BT656
//	write_reg(0x28, 0x03); // clock_div_spi

	///////////////////////////////////////////////////
	///////////////////////output//////////////////////
	///////////////////////////////////////////////////
	
	write_reg(0xFE, 0x00);
	
	write_reg(0x22, 0xF8); 
	write_reg(0xF1, 0x03); // SCK_en, SDA_en
#endif

#ifdef BIG

	/////////////////////////////////////////////////////
	//////////////////////	 SYS   //////////////////////
	/////////////////////////////////////////////////////
	
	write_reg(0xfe, 0xa0);
	write_reg(0xfe, 0xa0);
	write_reg(0xfe, 0xa0);

	write_reg(0xf6, 0x00);
	write_reg(0xfa, 0x11);
	write_reg(0xfc, 0x12); //clock enable

	write_reg(0xFE, 0x00); //Page select
	
	write_reg(0x49, 0x70);  //AWB r gain
	write_reg(0x4a, 0x80);  //AWB g gain
	write_reg(0x4b, 0x5d);  //AWB b gain
	
	/////////////////////////////////////////////////////
	////////////////   ANALOG & CISCTL	 ////////////////
	/////////////////////////////////////////////////////
	
	write_reg(0x03, 0x00);
	write_reg(0x04, 0xFA);
	write_reg(0x01, 0x41); //hb
	write_reg(0x02, 0x12); //vb
	write_reg(0x0f, 0x01);
	write_reg(0x0d, 0x30);
	write_reg(0x12, 0xc8);
	write_reg(0x14, 0x54); //dark CFA
	
	write_reg(0x15, 0x32); //1:sdark 0:ndark
	
	write_reg(0x16, 0x04);
	write_reg(0x17, 0x19);
	write_reg(0x1d, 0xb9);
	write_reg(0x1f, 0x15); //PAD_drv
	
	write_reg(0x7a, 0x00);
	write_reg(0x7b, 0x14);
	write_reg(0x7d, 0x36);
	
	write_reg(0xfe, 0x10);  //add by 20160217 CISCTL rst [4]
	
	/////////////////////////////////////////////////////
	//////////////////////   ISP   //////////////////////
	/////////////////////////////////////////////////////
	
	write_reg(0x20, 0x7e);
	write_reg(0x22, 0xb8);
	write_reg(0x24, 0x55); //output_format
	write_reg(0x26, 0x87); //[5]Y_switch [4]UV_switch [2]skin_en
	//write_reg(0x29, 0x10);// disable isp quiet mode

	write_reg(0x39, 0x00); //crop window
	write_reg(0x3a, 0x80); 
	write_reg(0x3b, 0x00);  //width
	write_reg(0x3c, CMR_W); 
	write_reg(0x3e, CMR_H); //height
	
	/////////////////////////////////////////////////////
	//////////////////////   BLK   //////////////////////
	/////////////////////////////////////////////////////
	
	write_reg(0x2a, 0x2f);
	write_reg(0x37, 0x46); //[4:0]blk_select_row

	/////////////////////////////////////////////////////
	//////////////////////   GAIN   /////////////////////
	/////////////////////////////////////////////////////
	
	write_reg(0x3f, 0x18); //global gain 20160901

	/////////////////////////////////////////////////////
	//////////////////////   DNDD   /////////////////////
	/////////////////////////////////////////////////////
	
	write_reg(0x50, 0x3c); 
	write_reg(0x52, 0x4f); 
	write_reg(0x53, 0x81);
	write_reg(0x54, 0x43);
	write_reg(0x56, 0x78); 
	write_reg(0x57, 0xaa);//20160901 
	write_reg(0x58, 0xff);//20160901

	/////////////////////////////////////////////////////
	//////////////////////   ASDE   /////////////////////
	/////////////////////////////////////////////////////
	
	write_reg(0x5b, 0x60); //dd&ee th
	write_reg(0x5c, 0x80); //60/OT_th
	write_reg(0xab, 0x28); 
	write_reg(0xac, 0xb5);

	/////////////////////////////////////////////////////
	/////////////////////   INTPEE   ////////////////////
	/////////////////////////////////////////////////////
	
	write_reg(0x60, 0x45); 
	write_reg(0x62, 0x68); //20160901
	write_reg(0x63, 0x13); //edge effect
	write_reg(0x64, 0x43);

	/////////////////////////////////////////////////////
	//////////////////////   CC   ///////////////////////
	/////////////////////////////////////////////////////
	
	write_reg(0x65, 0x13); //Y
	write_reg(0x66, 0x26);
	write_reg(0x67, 0x07);
	write_reg(0x68, 0xf5); //Cb
	write_reg(0x69, 0xea);
	write_reg(0x6a, 0x21);
	write_reg(0x6b, 0x21); //Cr
	write_reg(0x6c, 0xe4);
	write_reg(0x6d, 0xfb);

	/////////////////////////////////////////////////////
	//////////////////////   YCP   //////////////////////
	/////////////////////////////////////////////////////

	write_reg(0x81, 0x30); //cb
	write_reg(0x82, 0x30); //cr
	write_reg(0x83, 0x4a); //luma contrast
	write_reg(0x85, 0x06); //luma offset
	write_reg(0x8d, 0x78); //edge dec sa
	write_reg(0x8e, 0x25); //autogray

	/////////////////////////////////////////////////////
	//////////////////////   AEC   //////////////////////
	/////////////////////////////////////////////////////
	
	write_reg(0x90, 0x38); //20160901
	write_reg(0x92, 0x50); //target
	write_reg(0x9d, 0x32); //STEP
	write_reg(0x9e, 0x64); //[7:4]margin  10fps
	write_reg(0x9f, 0xf4);
	write_reg(0xa3, 0x28); //pregain
	write_reg(0xa4, 0x01); 

	/////////////////////////////////////////////////////
	//////////////////////   AWB   //////////////////////
	/////////////////////////////////////////////////////

	write_reg(0xb1, 0x1e); //Y_to_C_diff
	write_reg(0xb3, 0x20); //C_max
	//write_reg(0xbb, 0x63);
	write_reg(0xbd, 0x70); //R_limit
	write_reg(0xbe, 0x58); //G_limit
	write_reg(0xbf, 0xa0); //B_limit

	write_reg(0xfe, 0x00);	//20160901 update for AWB
	
	write_reg(0x43, 0xa8); 
	write_reg(0xb0, 0xf2); 
	write_reg(0xb5, 0x40); 
	write_reg(0xb8, 0x05); 
	write_reg(0xba, 0x60); 	

	/////////////////////////////////////////////////////
	//////////////////////   SPI   //////////////////////
	/////////////////////////////////////////////////////
	
	write_reg(0xFE, 0x02); //Page select
	
	write_reg(0x01, 0x01); //spi enable
	write_reg(0x02, 0x80); //LSB & Falling edge sample; ddr disable
	write_reg(0x03, 0x00); //1-wire
	write_reg(0x04, 0x20); //[4] master_outformat
	write_reg(0x0a, 0x00); //Data ID, 0x00-YUV422, 0x01-RGB565
	write_reg(0x13, 0x10);
	write_reg(0x24, 0x00); //[1]sck_always [0]BT656
	write_reg(0x28, 0x03); //clock_div_spi

	///////////////////////////////////////////////////
	///////////////////////output//////////////////////
	///////////////////////////////////////////////////
	
	write_reg(0xFE, 0x00); //Page select
	write_reg(0x22, 0xf8); //open awb
	
	uint32_t addr;
	addr=0x20001000;
	int i;
	for (i=0 ; i<100 ; i++)
	{
		*(__IO uint32_t*)addr = 0x0000;
		addr += 4;
	}
	
	GPIOA->AFRH|=0x00020020;
	GPIOD->AFRL|=0x3;
	
	USART1->US_BRGR=0x00;
	USART1->US_CR=0x0C;
	USART1->US_CR=0x00;
	USART1->US_MR=0x00;
	
	DMA1_Channel1->CNDTR=CMR_W*CMR_H*2;
//	DMA1_Channel1->CNDTR=100;
	DMA1_Channel1->CPAR=0x40000018;
//	DMA1_Channel1->CMAR=0x20001000;
	DMA1_Channel1->CMAR=0x40001860;
	DMA1_Channel1->CCR=0x140021;
//	DMA1_Channel1->CCR=0x140081;
	
	US_BRGR1_CD  (0x03);
    US_MR1_MODE  (0x0F);
    US_MR1_USCLK (0x03);
    US_MR1_CHRL  (0x03);
    US_MR1_OVER  (0x00);
    US_MR1_MODE9 (0x00);
    US_MR1_WRDBT (0x01);
    US_MR1_CPHA  (0x01);
    US_MR1_CPOL  (0x00);
	US_MR1_CLKO  (0x01);
//	US_MR2_SYNC  (0x01);

	USART1->US_CR=0x10;
	
	GPIOD->DIRR|=0x2;
	GPIOD->BSRR&=0xFFFFFFFC;
	
	LCD_In_Pin(2,DC_DATA);
	
	write_reg(0xf1, 0x03); //output enable
/*	
	while(DMA1_Channel1->CNDTR!=0){};
	
	//print_led("DMA OK\n");

	uint32_t rx_addr = 0x20001000;
	uint8_t text = 0;
		
	for (i=0 ; i<25 ; i++)
	{
		printf_led("%X\n",*(uint32_t*)rx_addr);
		rx_addr += 4;
	}
*/
#endif
}

// ==== Main Test ==== //

int main (void)
{
	print_enable();
    print_led("\n==== LCD SCREEN TESTS ====\n");	

	int i = 0;
	
	LCD_Init_GPIO();
	LCD_Init_SPI();
	LCD_Init();

	LCD_Screen_Area(0, LCD_W-1, 0, LCD_H-1);
	for (i=0 ; i<LCD_W*LCD_H ; i++)
	{
		LCD_Screen_Pixel_free(0x00, 0x00);
	}

	LCD_Screen_Area((LCD_W/2-CMR_W/2), (LCD_W/2+CMR_W/2-1), (LCD_H/2-CMR_H/2), (LCD_H/2+CMR_H/2-1));
	for (i=0 ; i<CMR_H*CMR_W ; i++)
	{
		LCD_Screen_Pixel_free(0xF8, 0x00);
	}

	//while((GPIOB -> IDR & 0x1) == 0);
	//print_led("\nInit Camera\n");
	//GPIOA->DIRR&=0x5F;
	//GPIOA->AFRL&=0x00;		

    GPIOB -> PUPDR  |= 0x0080;
    GPIOB -> AFRL   |= 0x20000000;
    
    GPIOF -> PUPDR  |= 0x0004;
    GPIOF -> AFRL   |= 0x00000200;
	
	volatile uint32_t *reg = (volatile uint32_t *)0x40001000;
    *reg |= (1UL << 15);

	GPIOB->AFRL|=0x2;	
	
	GPIOB->DIRR|=0x2;
	GPIOB->BSRR|=0x2;
	dly(100);
	GPIOB->BRR|=0x2;
	dly(100);
	GPIOB->BSRR|=0x2;
	dly(100);
	GPIOB->BRR|=0x2;


    RCC_I2C1EN(1);
	RCC_USART1EN(1);

	//GPIOA -> ODR &= 0xFFFD;
	camera_test();

	while (1)
	{};

}






	

   
