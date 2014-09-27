/*
	www.makerstudio.cc
*/
#include "TM1650.h"
#include <Arduino.h>

static int8_t Cmd_Addr[] = {0x68,0x6A,0x6C,0x6E};//LED address

TM1650::TM1650(uint8_t Data, uint8_t Clk)
{
  Clkpin = Clk;
  Datapin = Data;
}

void TM1650::begin(void)
{
  pinMode(Clkpin,OUTPUT);
  pinMode(Datapin,OUTPUT);
  clearDisplay();
}

//read and output key value 
uint8_t TM1650::readKey()
{
	uint8_t keyCode = 0;
	
	start();
	writeByte(READ_KEY_CMD);
	keyCode = readByte();
	stop();
	return keyCode;
	
}

//display function.Write to full-screen.
void TM1650::display(uint8_t DispData[])
{ 
  start();          //start signal sent to TM1650 from MCU
  writeByte(MODE_CMD);//write command for display
  writeByte(BRIGHT_TYPICAL);//set light grade and open display
  for(int i=0;i < 4;i ++){
    storeDat[i] = DispData[i];
	stop();           //
	start();          //
	writeByte(Cmd_Addr[i]);//
    writeByte(storeDat[i]);        //
	stop();           //
	start();          //
  }
}
//******************************************
void TM1650::display(uint8_t BitAddr,uint8_t DispData)
{
  if(BitAddr >=0 && BitAddr <= 3 ){
		storeDat[BitAddr] = DispData;
  }
	
  start();          //start signal sent to TM1650 from MCU
  writeByte(MODE_CMD);//write command for display
  writeByte(BRIGHT_TYPICAL);//set light grade and open display
	
	stop();           //
	start();          //
	writeByte(Cmd_Addr[BitAddr]);//
    writeByte(storeDat[BitAddr]); //
	stop();           //
	start();          //
	
}

//whether to light the point in different places
void TM1650::setPoint(uint8_t PointPosition,boolean PointFlag)
{
    if(PointPosition >=0 && PointPosition <= 3 ){
		if(PointFlag == 1){
			storeDat[PointPosition] |= 0x80;
		}else if(PointFlag == 0){
			storeDat[PointPosition] &= 0x7F;
		}
	display(PointPosition,storeDat[PointPosition]);
  }
  
}

void TM1650::clearDisplay(void)
{
    start();          //start signal sent to TM1650 from MCU
  writeByte(MODE_CMD);//write command for display
  writeByte(BRIGHT_OFF);//set light grade and open display
  for(int i=0;i < 4;i ++){
	storeDat[i] = 0x00;
	stop();           //
	start();          //
	writeByte(Cmd_Addr[i]);//
    writeByte(storeDat[i]);        //
	stop();           //
	start(); 
}
}

void TM1650::clearDisplay(uint8_t BitAddr)
{
  if(BitAddr >=0 && BitAddr <= 3){
		storeDat[BitAddr] &= 0x80;
  }
  start();          //start signal sent to TM1650 from MCU
  writeByte(MODE_CMD);//write command for display
  writeByte(BRIGHT_OFF);//set light grade and open display
	
	stop();           //
	start();          //
	writeByte(Cmd_Addr[BitAddr]);//
    writeByte(storeDat[BitAddr]); //
	stop();           //
	start();          //
}

void TM1650::writeByte(uint8_t wr_data)
{
  uint8_t i,count1;   
  for(i=0;i<8;i++)        //sent 8bit data
  {
    digitalWrite(Clkpin,LOW);      
    if(wr_data & 0x80)digitalWrite(Datapin,HIGH);//MSB first
    else digitalWrite(Datapin,LOW);
    wr_data <<= 1;      
    digitalWrite(Clkpin,HIGH);
  }  
  digitalWrite(Clkpin,LOW); 
  pinMode(Datapin,INPUT);
  
  while(digitalRead(Datapin)); //wait for the ACK    
  
  digitalWrite(Clkpin,HIGH);
  
  pinMode(Datapin,OUTPUT);
  
  
}

uint8_t TM1650::readByte()//read 8bit from to TM1650
{
  uint8_t rd_data=0;
  
  uint8_t i,count1;   
  uint8_t temp = 0x80;
  
  pinMode(Datapin,INPUT);
  digitalWrite(Clkpin,LOW);
  
  for(i=0;i<8;i++)        //read 8bit data
  {
    digitalWrite(Clkpin,HIGH);
	
    if(digitalRead(Datapin))//MSB first
	{
		rd_data |= temp;      
    }
    temp >>=1;
    digitalWrite(Clkpin,LOW);
	
  }  
  
  digitalWrite(Clkpin,LOW); //wait for the ACK
  pinMode(Datapin,INPUT);
  
  digitalWrite(Clkpin,HIGH);
  
  return rd_data;
}

//send start signal to TM1650
void TM1650::start(void)
{
  pinMode(Datapin,OUTPUT);
  digitalWrite(Clkpin,HIGH);//send start signal to TM1650
  
  digitalWrite(Datapin,HIGH); 
  
  digitalWrite(Datapin,LOW); 
  
  digitalWrite(Clkpin,LOW); 
  
} 

//End of transmission
void TM1650::stop(void)
{
  pinMode(Datapin,OUTPUT);
  digitalWrite(Clkpin,LOW);
  digitalWrite(Datapin,LOW);
  digitalWrite(Clkpin,HIGH);
  
  digitalWrite(Datapin,HIGH); 
  
}




