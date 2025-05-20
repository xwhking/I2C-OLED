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
		// ����I2C �ӻ���ַ
		OLED_I2C_SendByte(0x78);
		// ��OLED������������0x00��ʾ���������������
		OLED_I2C_SendByte(0x00);
		// ����ҳ��ַ
		OLED_I2C_SendByte(0xB0 | i);
		// ������Ϊ��0��
		OLED_I2C_SendByte(0x00);
		OLED_I2C_SendByte(0x10);
		OLED_I2C_Stop();
		OLED_I2C_Start();
		// ����I2C �ӻ���ַ
		OLED_I2C_SendByte(0x78);
		// ��OLED��������
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