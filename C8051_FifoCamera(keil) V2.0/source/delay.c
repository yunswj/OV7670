
void delay_us(unsigned int time)
 {     
   while (time--);
 }		  

/*	    ���뼶��ʱ����	*/	 
void delay_ms(unsigned int time)
	 {
	  while(time--) delay_us(100);  		 
	 }
	 
void delay( unsigned long cnt)
{
	 unsigned int i = 0;

	while(cnt--)
	{
		for (i = 0; i < 2; i++)
		{
		//__nop();
		}
	}
}