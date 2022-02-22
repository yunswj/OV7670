
#include<C8051F340.h>
#include<delay.h>

#define SDA_IN0()		{P0MDOUT= 0X00;}
#define SDA_OUT0()		{P0MDOUT= 0XFF;}


sbit I2C_SCL0=P0^2;
sbit I2C_SDA0=P0^1;
sbit SDA_STATE0=P0^1;


void InitI2C0(void)
{
	P0MDIN |= 0X06;
	P0MDOUT|= 0X06;
}

void StartI2C0(void)
{
	I2C_SDA0=1;    
    delay_us(100);

    I2C_SCL0=1;	   
    delay_us(100);
 
    I2C_SDA0=0;
    delay_us(100);

    I2C_SCL0=0;	 
    delay_us(100);


}

void StopI2C0(void)
{
	I2C_SDA0=0;
    delay_us(100);
 
    I2C_SCL0=1;
    delay_us(100);  

    I2C_SDA0=1;
    delay_us(100);
 

}


void NoAck0(void)
{
	
	I2C_SDA0=1;
	delay_us(100);
	
	I2C_SCL0=1;
	delay_us(100);
	
	I2C_SCL0=0;
	delay_us(100);
	
	I2C_SDA0=0;
	delay_us(100);

}


unsigned char I2CWrite0(unsigned char DData)
{
	unsigned char j,tem;

	for(j=0;j<8;j++) 
	{
		if((DData<<j)&0x80)
		{
			I2C_SDA0=1;
		}
		else
		{
			I2C_SDA0=0;
		}
		delay_us(100);
		I2C_SCL0=1;
		delay_us(100);
		I2C_SCL0=0;;
		delay_us(100);

	}
	delay_us(100);
	
	SDA_IN0();
	delay_us(100);
	I2C_SCL0=1;
	delay_us(1000);
	if(SDA_STATE0==1)
	{
		tem=0;  
	}
	else
	{
		tem=1;   
	}
	I2C_SCL0=0;
	delay_us(100);	
    SDA_OUT0();

	return(tem);  
}
