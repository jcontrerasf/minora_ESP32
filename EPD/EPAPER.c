#include "EPAPER.h"

const struct device* spi_dev = DEVICE_DT_GET(DT_NODELABEL(spi2));

const struct spi_config spi_cfg = {
  .frequency = 4000000U,
  .operation = SPI_WORD_SET(8) | SPI_TRANSFER_MSB | SPI_OP_MODE_MASTER
};

char vcom=0x26;		
/////////////////////////////////////LUT//////////////////////////////////////////////
const unsigned char LUT_DATA[]= {
0x80,0x60,0x40,0x00,0x00,0x00,0x00,             //LUT0: BB:     VS 0 ~7
0x10,0x60,0x20,0x00,0x00,0x00,0x00,             //LUT1: BW:     VS 0 ~7
0x80,0x60,0x40,0x00,0x00,0x00,0x00,             //LUT2: WB:     VS 0 ~7
0x10,0x60,0x20,0x00,0x00,0x00,0x00,             //LUT3: WW:     VS 0 ~7
0x00,0x00,0x00,0x00,0x00,0x00,0x00,             //LUT4: VCOM:   VS 0 ~7

0x03,0x03,0x00,0x00,0x02,                       // TP0 A~D RP0
0x09,0x09,0x00,0x00,0x02,                       // TP1 A~D RP1
0x03,0x03,0x00,0x00,0x02,                       // TP2 A~D RP2
0x00,0x00,0x00,0x00,0x00,                       // TP3 A~D RP3
0x00,0x00,0x00,0x00,0x00,                       // TP4 A~D RP4
0x00,0x00,0x00,0x00,0x00,                       // TP5 A~D RP5
0x00,0x00,0x00,0x00,0x00,                       // TP6 A~D RP6

0x15,0x41,0xA8,0x32,0x30,0x0A,
};	

//////////////////////////////////waveform1
const unsigned char LUT_DATA_part[]={  //20 bytes


0x00,0x00,0x00,0x00,0x00,0x00,0x00,             //LUT0: BB:     VS 0 ~7
0x80,0x00,0x00,0x00,0x00,0x00,0x00,             //LUT1: BW:     VS 0 ~7
0x40,0x00,0x00,0x00,0x00,0x00,0x00,             //LUT2: WB:     VS 0 ~7
0x00,0x00,0x00,0x00,0x00,0x00,0x00,             //LUT3: WW:     VS 0 ~7
0x00,0x00,0x00,0x00,0x00,0x00,0x00,             //LUT4: VCOM:   VS 0 ~7

0x0A,0x00,0x00,0x00,0x00,                       // TP0 A~D RP0
0x00,0x00,0x00,0x00,0x00,                       // TP1 A~D RP1
0x00,0x00,0x00,0x00,0x00,                       // TP2 A~D RP2
0x00,0x00,0x00,0x00,0x00,                       // TP3 A~D RP3
0x00,0x00,0x00,0x00,0x00,                       // TP4 A~D RP4
0x00,0x00,0x00,0x00,0x00,                       // TP5 A~D RP5
0x00,0x00,0x00,0x00,0x00,                       // TP6 A~D RP6

0x15,0x41,0xA8,0x32,0x30,0x0A,
};


/*
 * º¯ÊýÃû£ºSPI1_WriteByte
 * ÃèÊö  £ºSPIx ¶ÁÐ´Ò»¸ö×Ö½Ú
 * ÊäÈë  £ºTxData:ÒªÐ´ÈëµÄ×Ö½Ú
 * Êä³ö  £º·µ»ØÖµ:¶ÁÈ¡µ½µÄ×Ö½Ú
 */
void Epaper_Spi_WriteByte(uint8_t TxData)
{				   			 
	struct spi_buf bufs[] = {
		{
			.buf = &TxData,
			.len = 1
		},
	};

	struct spi_buf_set tx = {
		.buffers = bufs,
		.count = 1
	};

	spi_write(spi_dev, &spi_cfg, &tx);

}
/*
 * º¯ÊýÃû£ºEPD_READBUSY
 * ÃèÊö  £ºµÈ´ýµç×ÓÖ½busyÐÅºÅÓÉ¸ß±äµÍ 
 * ÊäÈë  £ºÎÞ
 * Êä³ö  £ºÎÞ
 */	
void Epaper_READBUSY(void)
{ 
  while(1)
  {	 //=1 BUSY
     if(isEPD_W21_BUSY==0) break;
  }  
}

/*
 * º¯ÊýÃû£ºEpaper_Write_Command
 * ÃèÊö  £ºÐ´ÃüÁî
 * ÊäÈë  £ºcmd
 * Êä³ö  £ºÎÞ
 */	
void Epaper_Write_Command(uint8_t cmd)
{
	EPD_W21_CS_1;
	EPD_W21_CS_0;
	EPD_W21_DC_0;  // D/C#   0:command  1:data

	Epaper_Spi_WriteByte(cmd);
	EPD_W21_CS_1;
}


/*
 * º¯ÊýÃû£ºEpaper_Write_Command
 * ÃèÊö  £ºÐ´Êý¾Ý
 * ÊäÈë  £ºcmd
 * Êä³ö  £ºÎÞ
 */	
void Epaper_Write_Data(uint8_t data)
{
	EPD_W21_CS_1;
	EPD_W21_CS_0;
	EPD_W21_DC_1;  // D/C#   0:command  1:data

	Epaper_Spi_WriteByte(data);
	EPD_W21_CS_1;
}
/*
 * º¯ÊýÃû£ºEpaper_select_LUT
 * ÃèÊö  £ºÐ´Êý¾Ý
 * ÊäÈë  £ºcmd
 * Êä³ö  £ºÎÞ
 */	

void EPD_select_LUT(unsigned char * wave_data)
{        
     unsigned char count;
     Epaper_Write_Command(0x32);
	 for(count=0;count<70;count++)Epaper_Write_Data(wave_data[count]);

}	

/*
 * º¯ÊýÃû£ºEpaper_Init
 * ÃèÊö  £ºµç×ÓÖ½³õÊ¼»¯³ÌÐò£¬¸øµç×ÓÖ½·¢ËÍÃüÁî¼°Êý¾Ý
 * ÊäÈë  £ºwave_data
 * Êä³ö  £ºÎÞ
 */
/////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

/**************************************************************************************************
 * @fn      EPD_HW_Init
 *
 * @brief   Initilize HW LCD Driver.
 *
 * @param   None
 *
 * @return  None
 **************************************************************************************************/
void EPD_HW_Init(void)
{
	EPD_W21_RST_0    
	k_msleep(1); 
	EPD_W21_RST_1 //hard reset  
	k_msleep(1); 

	Epaper_READBUSY();
	Epaper_Write_Command(0x12); // soft reset
	Epaper_READBUSY();

	Epaper_Write_Command(0x74); //set analog block control       
	Epaper_Write_Data(0x54);
	Epaper_Write_Command(0x7E); //set digital block control          
	Epaper_Write_Data(0x3B);

	Epaper_Write_Command(0x01); //Driver output control      
	Epaper_Write_Data(0x27);
	Epaper_Write_Data(0x01);
	Epaper_Write_Data(0x00);

	Epaper_Write_Command(0x11); //data entry mode       
	Epaper_Write_Data(0x01);

	Epaper_Write_Command(0x44); //set Ram-X address start/end position   
	Epaper_Write_Data(0x00);
	Epaper_Write_Data(0x0F);    //0x0C-->(15+1)*8=128

	Epaper_Write_Command(0x45); //set Ram-Y address start/end position          
	Epaper_Write_Data(0x27);   //0x0127-->(295+1)=296
	Epaper_Write_Data(0x01);
	Epaper_Write_Data(0x00);
	Epaper_Write_Data(0x00); 

	Epaper_Write_Command(0x3C); //BorderWavefrom
	Epaper_Write_Data(0x03);	


	Epaper_Write_Command(0x2C);     //VCOM Voltage
	Epaper_Write_Data(vcom);    //

	Epaper_Write_Command(0x03); //      
	Epaper_Write_Data(LUT_DATA[70]);

	Epaper_Write_Command(0x04); //      
	Epaper_Write_Data(LUT_DATA[71]);    
	Epaper_Write_Data(LUT_DATA[72]);    
	Epaper_Write_Data(LUT_DATA[73]);    


	Epaper_Write_Command(0x3A);     //Dummy Line 	 
	Epaper_Write_Data(LUT_DATA[74]);    
	Epaper_Write_Command(0x3B);     //Gate time 
	Epaper_Write_Data(LUT_DATA[75]);   

	EPD_select_LUT((unsigned char *)LUT_DATA); //LUT

	Epaper_Write_Command(0x4E);   // set RAM x address count to 0;
	Epaper_Write_Data(0x00);
	Epaper_Write_Command(0x4F);   // set RAM y address count to 0X127;    
	Epaper_Write_Data(0x27);
	Epaper_Write_Data(0x01);
	Epaper_READBUSY();

}
//////////////////////////////All screen update////////////////////////////////////////////
void EPD_WhiteScreen_ALL(const unsigned char *datas)
{
   unsigned int i;
    Epaper_Write_Command(0x24);   //write RAM for black(0)/white (1)
   for(i=0;i<ALLSCREEN_GRAGHBYTES;i++)
   {               
     Epaper_Write_Data(*datas);
			datas++;
   }
   EPD_Update();	 
}

/////////////////////////////////////////////////////////////////////////////////////////
void EPD_Update(void)
{   
  Epaper_Write_Command(0x22); 
  Epaper_Write_Data(0xC7);   
  Epaper_Write_Command(0x20); 
  Epaper_READBUSY();  

}

void EPD_DeepSleep(void)
{  
	Epaper_Write_Command(0x22); //POWER OFF
	Epaper_Write_Data(0xC3);   
	Epaper_Write_Command(0x20);  
	
  Epaper_Write_Command(0x10); //enter deep sleep
  Epaper_Write_Data(0x01); 
  k_msleep(100);
}
///////////////////////////Part update//////////////////////////////////////////////
void EPD_SetRAMValue_BaseMap(const unsigned char * datas)
{
	unsigned int i;   
	const unsigned char  *datas_flag;   
	datas_flag=datas;
  Epaper_Write_Command(0x24);   //Write Black and White image to RAM
   for(i=0;i<ALLSCREEN_GRAGHBYTES;i++)
   {               
     Epaper_Write_Data(*datas);
			datas++;
   }
	 datas=datas_flag;
  Epaper_Write_Command(0x26);   //Write Black and White image to RAM
   for(i=0;i<ALLSCREEN_GRAGHBYTES;i++)
   {               
     Epaper_Write_Data(*datas);
			datas++;
   }
   EPD_Update();	 
}

void EPD_Part_Init(void)
{
  Epaper_READBUSY();  
  EPD_select_LUT(( unsigned char *)LUT_DATA_part);
  Epaper_Write_Command(0x37); 
  Epaper_Write_Data(0x00);  
  Epaper_Write_Data(0x00);  
  Epaper_Write_Data(0x00);  
  Epaper_Write_Data(0x00);  
  Epaper_Write_Data(0x40);  
  Epaper_Write_Data(0x00);  
  Epaper_Write_Data(0x00);   

  Epaper_Write_Command(0x22); 
  Epaper_Write_Data(0xC0);   
  Epaper_Write_Command(0x20); 
  Epaper_READBUSY();  
	
  Epaper_Write_Command(0x3C); //BorderWavefrom
	Epaper_Write_Data(0x01);

}
void EPD_Dis_Part(unsigned int x_start,unsigned int y_start, const unsigned char * datas,unsigned int PART_COLUMN,unsigned int PART_LINE)
{
	unsigned int i;  
	unsigned int x_end,y_start1,y_start2,y_end1,y_end2;
	x_start=x_start/8;//×ª»»Îª×Ö½Ú
	x_end=x_start+PART_LINE/8-1; 
	
	y_start1=0;
	y_start2=y_start;
	if(y_start>=256)
	{
		y_start1=y_start2/256;
		y_start2=y_start2%256;
	}
	y_end1=0;
	y_end2=y_start+PART_COLUMN-1;
	if(y_end2>=256)
	{
		y_end1=y_end2/256;
		y_end2=y_end2%256;		
	}		
	
	Epaper_Write_Command(0x44);       // set RAM x address start/end, in page 35
	Epaper_Write_Data(x_start);    // RAM x address start at 00h;
	Epaper_Write_Data(x_end);    // RAM x address end at 0fh(15+1)*8->128 
	Epaper_Write_Command(0x45);       // set RAM y address start/end, in page 35
	Epaper_Write_Data(y_start2);    // RAM y address start at 0127h;
	Epaper_Write_Data(y_start1);    // RAM y address start at 0127h;
	Epaper_Write_Data(y_end2);    // RAM y address end at 00h;
	Epaper_Write_Data(y_end1);    // ????=0	


	Epaper_Write_Command(0x4E);   // set RAM x address count to 0;
	Epaper_Write_Data(x_start); 
	Epaper_Write_Command(0x4F);   // set RAM y address count to 0X127;    
	Epaper_Write_Data(y_start2);
	Epaper_Write_Data(y_start1);
	
	
	 Epaper_Write_Command(0x24);   //Write Black and White image to RAM
   for(i=0;i<PART_COLUMN*PART_LINE/8;i++)
   {                         
     Epaper_Write_Data(*datas);
			datas++;
   } 
	 EPD_Part_Update();

}

void EPD_Part_Update(void)
{
	Epaper_Write_Command(0x22); 
	Epaper_Write_Data(0x0C);   
	Epaper_Write_Command(0x20); 
	Epaper_READBUSY(); 		
}
void EPD_Part_off(void)
{ 	
	Epaper_Write_Command(0x22); 
	Epaper_Write_Data(0x03);   
	Epaper_Write_Command(0x20); 

  Epaper_Write_Command(0x10); //enter deep sleep
  Epaper_Write_Data(0x01); 
  k_msleep(500);
}







/////////////////////////////////Single display////////////////////////////////////////////////
void EPD_WhiteScreen_BW(void)

{
  unsigned int i,k;
    Epaper_Write_Command(0x24);   //write RAM for black(0)/white (1)
	for(k=0;k<125;k++)
  {
		for(i=0;i<16;i++)
		{
			Epaper_Write_Data(0x00);
			}
  }


	for(k=0;k<125;k++)
  {
		for(i=0;i<16;i++)
		{
			Epaper_Write_Data(0xff);
			}
  }
	   EPD_Update();	
}
void EPD_WhiteScreen_Black(void)

{
   unsigned int i,k;
    Epaper_Write_Command(0x24);   //write RAM for black(0)/white (1)
	for(k=0;k<296;k++)
  {
		for(i=0;i<16;i++)
		{
			Epaper_Write_Data(0x00);
			}
  }
		EPD_Update();
}

void EPD_WhiteScreen_White(void)

{
   unsigned int i,k;
    Epaper_Write_Command(0x24);   //write RAM for black(0)/white (1)
	for(k=0;k<296;k++)
  {
		for(i=0;i<16;i++)
		{
			Epaper_Write_Data(0xff);
			}
  }
	EPD_Update();
}

/////////////////////////////////////TIME///////////////////////////////////////////////////
void EPD_Dis_Part_myself(unsigned int x_startA,unsigned int y_startA, const unsigned char * datasA,
	                       unsigned int x_startB,unsigned int y_startB, const unsigned char * datasB,
												 unsigned int x_startC,unsigned int y_startC, const unsigned char * datasC,
												 unsigned int x_startD,unsigned int y_startD, const unsigned char * datasD,
											   unsigned int x_startE,unsigned int y_startE, const unsigned char * datasE,
												 unsigned int PART_COLUMN,unsigned int PART_LINE
	                      )
{
	unsigned int i;  
	unsigned int x_end,y_start1,y_start2,y_end1,y_end2;
	
	//AÊý¾Ý////////////////////////////
	x_startA=x_startA/8;//×ª»»Îª×Ö½Ú
	x_end=x_startA+PART_LINE/8-1; 
	
	y_start1=0;
	y_start2=y_startA;
	if(y_startA>=256)
	{
		y_start1=y_start2/256;
		y_start2=y_start2%256;
	}
	y_end1=0;
	y_end2=y_startA+PART_COLUMN-1;
	if(y_end2>=256)
	{
		y_end1=y_end2/256;
		y_end2=y_end2%256;		
	}		
	
	Epaper_Write_Command(0x44);       // set RAM x address start/end, in page 35
	Epaper_Write_Data(x_startA);    // RAM x address start at 00h;
	Epaper_Write_Data(x_end);    // RAM x address end at 0fh(15+1)*8->128 
	Epaper_Write_Command(0x45);       // set RAM y address start/end, in page 35
	Epaper_Write_Data(y_start2);    // RAM y address start at 0127h;
	Epaper_Write_Data(y_start1);    // RAM y address start at 0127h;
	Epaper_Write_Data(y_end2);    // RAM y address end at 00h;
	Epaper_Write_Data(y_end1);    // ????=0	


	Epaper_Write_Command(0x4E);   // set RAM x address count to 0;
	Epaper_Write_Data(x_startA); 
	Epaper_Write_Command(0x4F);   // set RAM y address count to 0X127;    
	Epaper_Write_Data(y_start2);
	Epaper_Write_Data(y_start1);
	
	
	 Epaper_Write_Command(0x24);   //Write Black and White image to RAM
   for(i=0;i<PART_COLUMN*PART_LINE/8;i++)
   {                         
     Epaper_Write_Data(*datasA);
			datasA++;
   } 
	//BÊý¾Ý//////////////////////////////////////
	x_startB=x_startB/8;//×ª»»Îª×Ö½Ú
	x_end=x_startB+PART_LINE/8-1; 
	
	y_start1=0;
	y_start2=y_startB;
	if(y_startB>=256)
	{
		y_start1=y_start2/256;
		y_start2=y_start2%256;
	}
	y_end1=0;
	y_end2=y_startB+PART_COLUMN-1;
	if(y_end2>=256)
	{
		y_end1=y_end2/256;
		y_end2=y_end2%256;		
	}		
	
	Epaper_Write_Command(0x44);       // set RAM x address start/end, in page 35
	Epaper_Write_Data(x_startB);    // RAM x address start at 00h;
	Epaper_Write_Data(x_end);    // RAM x address end at 0fh(15+1)*8->128 
	Epaper_Write_Command(0x45);       // set RAM y address start/end, in page 35
	Epaper_Write_Data(y_start2);    // RAM y address start at 0127h;
	Epaper_Write_Data(y_start1);    // RAM y address start at 0127h;
	Epaper_Write_Data(y_end2);    // RAM y address end at 00h;
	Epaper_Write_Data(y_end1);    // ????=0	


	Epaper_Write_Command(0x4E);   // set RAM x address count to 0;
	Epaper_Write_Data(x_startB); 
	Epaper_Write_Command(0x4F);   // set RAM y address count to 0X127;    
	Epaper_Write_Data(y_start2);
	Epaper_Write_Data(y_start1);
	
	
	 Epaper_Write_Command(0x24);   //Write Black and White image to RAM
   for(i=0;i<PART_COLUMN*PART_LINE/8;i++)
   {                         
     Epaper_Write_Data(*datasB);
			datasB++;
   } 	 
	 
	//CÊý¾Ý//////////////////////////////////////
	x_startC=x_startC/8;//×ª»»Îª×Ö½Ú
	x_end=x_startC+PART_LINE/8-1; 
	
	y_start1=0;
	y_start2=y_startC;
	if(y_startC>=256)
	{
		y_start1=y_start2/256;
		y_start2=y_start2%256;
	}
	y_end1=0;
	y_end2=y_startC+PART_COLUMN-1;
	if(y_end2>=256)
	{
		y_end1=y_end2/256;
		y_end2=y_end2%256;		
	}		
	
	Epaper_Write_Command(0x44);       // set RAM x address start/end, in page 35
	Epaper_Write_Data(x_startC);    // RAM x address start at 00h;
	Epaper_Write_Data(x_end);    // RAM x address end at 0fh(15+1)*8->128 
	Epaper_Write_Command(0x45);       // set RAM y address start/end, in page 35
	Epaper_Write_Data(y_start2);    // RAM y address start at 0127h;
	Epaper_Write_Data(y_start1);    // RAM y address start at 0127h;
	Epaper_Write_Data(y_end2);    // RAM y address end at 00h;
	Epaper_Write_Data(y_end1);    // ????=0	


	Epaper_Write_Command(0x4E);   // set RAM x address count to 0;
	Epaper_Write_Data(x_startC); 
	Epaper_Write_Command(0x4F);   // set RAM y address count to 0X127;    
	Epaper_Write_Data(y_start2);
	Epaper_Write_Data(y_start1);
	
	
	 Epaper_Write_Command(0x24);   //Write Black and White image to RAM
   for(i=0;i<PART_COLUMN*PART_LINE/8;i++)
   {                         
     Epaper_Write_Data(*datasC);
			datasC++;
   } 	 	 
 	 
	//DÊý¾Ý//////////////////////////////////////
	x_startD=x_startD/8;//×ª»»Îª×Ö½Ú
	x_end=x_startD+PART_LINE/8-1; 
	
	y_start1=0;
	y_start2=y_startD;
	if(y_startD>=256)
	{
		y_start1=y_start2/256;
		y_start2=y_start2%256;
	}
	y_end1=0;
	y_end2=y_startD+PART_COLUMN-1;
	if(y_end2>=256)
	{
		y_end1=y_end2/256;
		y_end2=y_end2%256;		
	}		
	
	Epaper_Write_Command(0x44);       // set RAM x address start/end, in page 35
	Epaper_Write_Data(x_startD);    // RAM x address start at 00h;
	Epaper_Write_Data(x_end);    // RAM x address end at 0fh(15+1)*8->128 
	Epaper_Write_Command(0x45);       // set RAM y address start/end, in page 35
	Epaper_Write_Data(y_start2);    // RAM y address start at 0127h;
	Epaper_Write_Data(y_start1);    // RAM y address start at 0127h;
	Epaper_Write_Data(y_end2);    // RAM y address end at 00h;
	Epaper_Write_Data(y_end1);    // ????=0	


	Epaper_Write_Command(0x4E);   // set RAM x address count to 0;
	Epaper_Write_Data(x_startD); 
	Epaper_Write_Command(0x4F);   // set RAM y address count to 0X127;    
	Epaper_Write_Data(y_start2);
	Epaper_Write_Data(y_start1);
	
	
	 Epaper_Write_Command(0x24);   //Write Black and White image to RAM
   for(i=0;i<PART_COLUMN*PART_LINE/8;i++)
   {                         
     Epaper_Write_Data(*datasD);
			datasD++;
   } 
	//EÊý¾Ý//////////////////////////////////////
	x_startE=x_startE/8;//×ª»»Îª×Ö½Ú
	x_end=x_startE+PART_LINE/8-1; 
	
	y_start1=0;
	y_start2=y_startE;
	if(y_startE>=256)
	{
		y_start1=y_start2/256;
		y_start2=y_start2%256;
	}
	y_end1=0;
	y_end2=y_startE+PART_COLUMN-1;
	if(y_end2>=256)
	{
		y_end1=y_end2/256;
		y_end2=y_end2%256;		
	}		
	
	Epaper_Write_Command(0x44);       // set RAM x address start/end, in page 35
	Epaper_Write_Data(x_startE);    // RAM x address start at 00h;
	Epaper_Write_Data(x_end);    // RAM x address end at 0fh(15+1)*8->128 
	Epaper_Write_Command(0x45);       // set RAM y address start/end, in page 35
	Epaper_Write_Data(y_start2);    // RAM y address start at 0127h;
	Epaper_Write_Data(y_start1);    // RAM y address start at 0127h;
	Epaper_Write_Data(y_end2);    // RAM y address end at 00h;
	Epaper_Write_Data(y_end1);    // ????=0	


	Epaper_Write_Command(0x4E);   // set RAM x address count to 0;
	Epaper_Write_Data(x_startE); 
	Epaper_Write_Command(0x4F);   // set RAM y address count to 0X127;    
	Epaper_Write_Data(y_start2);
	Epaper_Write_Data(y_start1);
	
	
	 Epaper_Write_Command(0x24);   //Write Black and White image to RAM
   for(i=0;i<PART_COLUMN*PART_LINE/8;i++)
   {                         
     Epaper_Write_Data(*datasE);
			datasE++;
   } 	 	 
	 EPD_Part_Update();

}