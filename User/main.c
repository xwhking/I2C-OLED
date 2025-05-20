#include "stm32f10x.h"                  // Device header
#include "delay.h"
#include "OLED.h"
#include "Serial.h"
uint8_t OLED_DisplayBuf[8][128];
void update_OLED()
{
	int i,j;
	for(i = 0 ; i< 8;i++){
		OLED_I2C_Start();
		// 传送I2C 从机地址
		OLED_I2C_SendByte(0x78);
		// 向OLED传送命令数据0x00表示后面的数据是命令
		OLED_I2C_SendByte(0x00);
		// 设置页地址
		OLED_I2C_SendByte(0xB0 | i);
		// 设置列为第0列
		OLED_I2C_SendByte(0x00);
		OLED_I2C_SendByte(0x10);
		OLED_I2C_Stop();
		OLED_I2C_Start();
		// 传送I2C 从机地址
		OLED_I2C_SendByte(0x78);
		// 向OLED传送数据
		OLED_I2C_SendByte(0x40);
		for(int j = 0;j<128;j++){
			OLED_I2C_SendByte( OLED_DisplayBuf[i][j]);
		}
		OLED_I2C_Stop();
	}
}

int main(void)
{
	OLED_Init();
	Serial_Init();
	while(1){
		update_OLED();
	}
}