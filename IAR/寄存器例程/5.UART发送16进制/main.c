/*******************************************************************************
*******************************蓝旗嵌入式系统***********************************
*************************http://lenchimcu.taobao.com****************************
*******************************************************************************/

#include"iostm8l151k4.h"
/*******************************************************************************
****入口参数：无
****出口参数：无
****函数备注：USART初始化函数
****版权信息：蓝旗嵌入式系统
*******************************************************************************/
void Init_USART1(void)
{
      CLK_PCKENR1 |= (1<<5);//开串口时钟
      PC_DDR |= (1<<3);     //TX引脚为输出
      PC_CR1 |= (1<<3);
      PC_CR2 |= (1<<3);
      //配置USART参数
      USART1_CR1=0x00;
      USART1_CR2=0x00;
      USART1_CR3=0x00;
      // 设置波特率，必须注意以下几点：
      // (1) 必须先写BRR2
      // (2) BRR1存放的是分频系数的第11位到第4位，
      // (3) BRR2存放的是分频系数的第15位到第12位，和第3位
      // 到第0位
      // 例如对于波特率位9600时，分频系数=2000000/9600=208
      // 对应的十六进制数为00D0，BBR1=0D,BBR2=00

      USART1_BRR2=0x00;
      USART1_BRR1=0x0d;

      USART1_CR2=0x2c;//允许接收，发送，开接收中断
}
/*******************************************************************************
****入口参数：需要发送的数据
****出口参数：无
****函数备注：USART发送函数
****版权信息：蓝旗嵌入式系统
*******************************************************************************/
void USART1_sendchar(unsigned char c)
{
      while((USART1_SR & 0x80)==0x00);
      USART1_DR=c;
}
/*******************************************************************************
****入口参数：无
****出口参数：无
****函数备注：计算机通过串口调试助手可以接收开发板UART发送的十六进制数据，跳线RXD-UT TXD-UR
****版权信息：蓝旗嵌入式系统
*******************************************************************************/
int main( void )
{
        unsigned char i=0;
	Init_USART1();
	while (1)
	{
		USART1_sendchar(i);
		i++; 
	}
}
/*******************************************************************************
*******************************蓝旗嵌入式系统***********************************
*************************http://lenchimcu.taobao.com****************************
*******************************************************************************/