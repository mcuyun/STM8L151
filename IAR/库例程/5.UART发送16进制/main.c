/*******************************************************************************
*******************************蓝旗嵌入式系统***********************************
*************************http://lenchimcu.taobao.com****************************
********************************************************************************
****例程简介:STM8L151K4 USART发送16进制数据库函数例程
*******************************************************************************/
#include "stm8l15x.h"
//定义LED与按键接口
#define LED_GPIO_PORT  GPIOA
#define LED_GPIO_PINS  GPIO_Pin_6
#define KEY_GPIO_PORT  GPIOB
#define KEY_GPIO_PINS  GPIO_Pin_4

/*******************************************************************************
****入口参数：无
****出口参数：无
****函数备注：开发板上RXD-UT TXD-UR跳线帽短接，通过USB线连接计算机与开发板，打开
              计算机的串口调试助手软件，设置参数，可以接收到开发板发送的HEX格式的
              数据。使用前计算机需先安装CH340驱动。
****版权信息：蓝旗嵌入式系统
*******************************************************************************/
int main( void )
{
    uint8_t i;
    CLK_PeripheralClockConfig (CLK_Peripheral_USART1,ENABLE);//所有外设时钟，初始默认关闭，使用外设前需开启对应外设时钟
    USART_Init(USART1,9600,USART_WordLength_8b,USART_StopBits_1,USART_Parity_No,USART_Mode_Tx);//设置USART参数9600，8N1
    USART_Cmd (USART1,ENABLE);//使能USART
    while(1)
    {
        USART_SendData8(USART1,i);//发送16进制
        while(!USART_GetFlagStatus (USART1,USART_FLAG_TXE));//等待发送结束
        i++;
    }
    
}

/*******************************************************************************
*******************************蓝旗嵌入式系统***********************************
*************************http://lenchimcu.taobao.com****************************
*******************************************************************************/
