
/*
	www.makerstudio.cc
*/

#ifndef TM1650_h
#define TM1650_h
#include <inttypes.h>
#include <Arduino.h>
//************definitions for TM1650*********************
#define READ_KEY_CMD	0x49
#define MODE_CMD 		0x48

/**************definitions for brightness***********************/
#define  BRIGHT_MOST 0x01
#define  BRIGHT_TYPICAL 0x21
#define  BRIGHT_OFF 0x00


class TM1650
{
  public:
    uint8_t Cmd_SetData;
    uint8_t Cmd_SetAddr;
    uint8_t Cmd_DispCtrl;
    boolean _PointFlag;     //_PointFlag=1:the clock point on
    TM1650(uint8_t, uint8_t);
    void begin(void);        //To initial the TM1650

	uint8_t readKey();//read and output key value 
    
    void display(uint8_t DispData[]);
    void display(uint8_t BitAddr,uint8_t DispData);
	void setPoint(uint8_t PointPosition,boolean PointFlag);//whether to light the point in different places
	
    void clearDisplay(void);//turn off all the leds
	void clearDisplay(uint8_t BitAddr);//turn off specific LED 
    

  private:
    uint8_t Clkpin;
    uint8_t Datapin;
	uint8_t storeDat[4];
	
	void start(void);//send start bits
    void stop(void); //send stop bits
	
	void writeByte(uint8_t wr_data);//write 8bit data to TM1650
	uint8_t readByte();//read 8bit from to TM1650
	
};
#endif
