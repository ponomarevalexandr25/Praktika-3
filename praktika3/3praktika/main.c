#include <8051.h>

void s1out(short position, short maxPosition)
{	
	unsigned int i=0;
	short current = 0;
unsigned char length = 4;
short str[4] ={178,160,185,160};

	P0 = 0x80;
	P2 = 0x1;
	P2 = 0x0;
if(position+length>maxPosition)
{
	for(i=5-(position+length-maxPosition);i<4;i++)
	{
		if(current == maxPosition) break;
		current++;
		P0 = str[i];
		P2 = 0x3;
		P2 = 0x2;
	}
	i = (position+length-maxPosition)-1;
}


	for(;i<position;i++)
	{
		if(current == maxPosition) break;
		current++;
		P0 = 6;
		P2 = 0x3;
		P2 = 0x2;
		
	}

	for(i=0;i<4;i++)
	{
		if(current == maxPosition) break;
		current++;
		P0 = str[i];
		P2 = 0x3;
		P2 = 0x2;
	}
}

void s2out()
{
	unsigned int i;
	unsigned char *str2="111";
	P0 = 0xC0;
	P2 = 0x1;
	P2 = 0x0;
	for(i=0;i<8;i++) //????? ?? LCD ?????? ??????
	{
		P0 = str2[i];
		P2 = 0x3;
		P2 = 0x2;
	}
}

void main()
{	
	short position = 0;
	short maxPosition = 16;
	P0 = 0x38;
	P2 = 0x1;
	P2 = 0x0;
	
	
	while(1){
		s1out(position,maxPosition);
		if(position < maxPosition) { position++;}
		else {position = 0;}
		//s2out();
	}
}