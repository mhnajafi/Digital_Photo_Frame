/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "fatfs.h"

SD_HandleTypeDef hsd;

UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;


int cnth=0,cntv=0;
char receive=0,number=0;


/* Private function prototypes ----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_SDIO_SD_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_USART2_UART_Init(void);
static void SRAM_Precharge(void);
static void SRAM_AutoRefresh(void);
static void SRAM_RowBankActive(unsigned int ad);
static void SRAM_Write(unsigned int ad,unsigned int data,char mode);
//static unsigned int SRAM_Read(unsigned int ad,char mode);
static void SRAM_RegisterSet();
static void SRAM_BurstStop(void);
static void SRAM_Init(void);
static void LCD_Hsync(char de,int bank);
static void LCD_Show(char sector);
static void Slide_Show(char a,char b);
static void LCD_Display(char state);
static void LCD_Init();
static void PicToRam(char sector,const TCHAR* path);



int main(void)
{
	/* USER CODE BEGIN 1 */
	char path[8],index=1,state=0;
	FATFS mynewdiskFatFs;
	HAL_Init();

	/* Configure the system clock */
	SystemClock_Config();

	/* Initialize all configured peripherals */
	MX_GPIO_Init();

	MX_SDIO_SD_Init();
	MX_USART1_UART_Init();
	MX_USART2_UART_Init();
	MX_FATFS_Init();
	LCD_Init();
	SRAM_Init();

	if(f_mount(&mynewdiskFatFs, SDPath, 1)==FR_OK)
	{
		for(char i=1; i<101 ; i++)
		{
			sprintf(path,"/%d.rgb",i);
			PicToRam(i, path);
		}

	}

	LCD_Display(1);
	__HAL_UART_ENABLE_IT(&huart2, UART_IT_RXNE);

	while (1)
	{

		if(state==0)				//normal state
		{
			LCD_Show(index);
			if(receive!=0)
			{
				if(receive=='U' && index<number)
				{
					Slide_Show(index, index+1);
					index++;

				}
				else if(receive=='D' && index>1)
				{
					Slide_Show(index, index-1);
					index--;
				}
				else if(receive=='G') state=1;
				else if(receive=='P')
				{
					LCD_Display(0);
					state=2;
				}
				receive=0;
			}
		}
		else if(state==1)				//slider state
		{

			if(index<number)
			{
				Slide_Show(index, index+1);
				index++;
			}
			else
			{
				Slide_Show(index,1);
				index=1;
			}

			if(receive!=0)
			{
				if(receive=='R') state=0;
				else if(receive=='P')
				{
					LCD_Display(0);
					state=2;
				}
				receive=0;
			}
			for(int n=0;n<300;n++)
			{
				LCD_Show(index);
				if(receive!=0)
				{
					if(receive=='R') state=0;
					else if(receive=='P')
					{
						LCD_Display(0);
						state=2;
					}
					receive=0;
				}
			}

		}
		else if(state==2)				//Sleep state
		{

			SRAM_Precharge();
			SRAM_AutoRefresh();
			if(receive=='P')
			{
				LCD_Display(1);
				state=0;
				receive=0;
			}

		}




	}



}



static void SRAM_Precharge(void)
{
	GPIOC->BSRR=0xC0052002;
	GPIOC->BSRR=0xC0052002;
	GPIOC->BSRR=0xC0052002;
	GPIOB->BSRR=0x400;
	GPIOB->BSRR=0x400;
	GPIOB->BSRR=0x400;
	GPIOC->BSRR=0x4000;
	GPIOC->BSRR=0x4000;
	GPIOC->BSRR=0x4000;
	GPIOC->BSRR=0x40008000;
	GPIOC->BSRR=0x40008000;
	GPIOC->BSRR=0x40008000;
	GPIOC->BSRR=0x4000;
	GPIOC->BSRR=0x4000;
	GPIOC->BSRR=0x4000;
	GPIOC->BSRR=0x40000000;
	GPIOC->BSRR=0x40000000;
	GPIOC->BSRR=0x40000000;
	GPIOC->BSRR=0x4000;
	GPIOC->BSRR=0x4000;
	GPIOC->BSRR=0x4000;
	GPIOC->BSRR=0x40000000;
	GPIOC->BSRR=0x40000000;
	GPIOC->BSRR=0x40000000;
}

static void SRAM_AutoRefresh(void)
{
	GPIOC->BSRR=0xC0032004;
	GPIOC->BSRR=0xC0032004;
	GPIOC->BSRR=0xC0032004;
	GPIOC->BSRR=0x4000;
	GPIOC->BSRR=0x4000;
	GPIOC->BSRR=0x4000;
	GPIOC->BSRR=0x40008000;
	GPIOC->BSRR=0x40008000;
	GPIOC->BSRR=0x40008000;
	GPIOC->BSRR=0x4000;
	GPIOC->BSRR=0x4000;
	GPIOC->BSRR=0x4000;
	GPIOC->BSRR=0x40000000;
	GPIOC->BSRR=0x40000000;
	GPIOC->BSRR=0x40000000;
	GPIOC->BSRR=0x4000;
	GPIOC->BSRR=0x4000;
	GPIOC->BSRR=0x4000;
	GPIOC->BSRR=0x40000000;
	GPIOC->BSRR=0x40000000;
	GPIOC->BSRR=0x40000000;
}

static void SRAM_RowBankActive(unsigned int ad)
{
	GPIOC->BSRR=0xC0012006;
	GPIOC->BSRR=0xC0012006;
	GPIOC->BSRR=0xC0012006;

	GPIOA->BSRR=0xFF0000;
	GPIOB->BSRR=0xFF000000;
	GPIOA->BSRR=(ad & 0xFF);
	GPIOA->BSRR=(ad & 0xFF);
	GPIOB->BSRR=(ad & 0xFF00);
	GPIOB->BSRR=(ad & 0xFF00);

	GPIOC->BSRR=0x4000;
	GPIOC->BSRR=0x4000;
	GPIOC->BSRR=0x4000;

	GPIOC->BSRR=0x40008000;
	GPIOC->BSRR=0x40008000;
	GPIOC->BSRR=0x40008000;

	GPIOC->BSRR=0x4000;
	GPIOC->BSRR=0x4000;
	GPIOC->BSRR=0x4000;

	GPIOC->BSRR=0x40000000;
	GPIOC->BSRR=0x40000000;
	GPIOC->BSRR=0x40000000;

	GPIOC->BSRR=0x4000;
	GPIOC->BSRR=0x4000;
	GPIOC->BSRR=0x4000;

	GPIOC->BSRR=0x40000000;
	GPIOC->BSRR=0x40000000;
	GPIOC->BSRR=0x40000000;
}
static void SRAM_Write(unsigned int ad,unsigned int data,char mode)
{
	if(mode==0)
	{
		HAL_GPIO_WritePin(GPIOC, RAM_CLK_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOC, RAM_CS_Pin|RAM_CAS_Pin|RAM_WE_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOC, RAM_RAS_Pin, GPIO_PIN_SET);
		GPIOA->BSRR=0xFF0000;
		GPIOB->BSRR=0xFF000000;
		GPIOA->BSRR=(ad & 0xFF);
		GPIOB->BSRR=(ad & 0xFF00)|(1<<10);
		GPIOE->MODER=0x55555555;
		GPIOE->ODR=data;
		HAL_GPIO_WritePin(GPIOC, RAM_CLK_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOC, RAM_CLK_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOC, RAM_CS_Pin , GPIO_PIN_SET);
	}
	else
	{
		HAL_GPIO_WritePin(GPIOC, RAM_CLK_Pin, GPIO_PIN_RESET);
		GPIOE->ODR=data;
		HAL_GPIO_WritePin(GPIOC, RAM_CLK_Pin, GPIO_PIN_SET);
	}

}
/*
static unsigned int SRAM_Read(unsigned int ad,char mode)
{
	unsigned int data=0;
	if(mode==0)
	{
		//HAL_GPIO_WritePin(GPIOF, RAM_CLK_Pin, GPIO_PIN_RESET);
		//HAL_GPIO_WritePin(GPIOF, RAM_CS_Pin|RAM_CAS_Pin, GPIO_PIN_RESET);
		//HAL_GPIO_WritePin(GPIOF, RAM_RAS_Pin|RAM_WE_Pin, GPIO_PIN_SET);
		GPIOF->BSRR=0xB0014;
		GPIOE->ODR=ad|(1<<10);
		GPIOG->MODER=0;
		//HAL_GPIO_WritePin(GPIOF, RAM_CLK_Pin, GPIO_PIN_SET);
		GPIOF->BSRR=1;
		//HAL_GPIO_WritePin(GPIOF, RAM_CLK_Pin, GPIO_PIN_RESET);
		//HAL_GPIO_WritePin(GPIOF, RAM_CS_Pin , GPIO_PIN_SET);
		GPIOF->BSRR=0x10002;
		//HAL_GPIO_WritePin(GPIOF, RAM_CLK_Pin, GPIO_PIN_SET);
		GPIOF->BSRR=1;
		//HAL_GPIO_WritePin(GPIOF, RAM_CLK_Pin, GPIO_PIN_RESET);
		GPIOF->BSRR=(1<<16);
		//HAL_GPIO_WritePin(GPIOF, RAM_CLK_Pin, GPIO_PIN_SET);
		GPIOF->BSRR=1;
		data=GPIOG->IDR;
		//HAL_GPIO_WritePin(GPIOF, RAM_CLK_Pin, GPIO_PIN_RESET);
		GPIOF->BSRR=(1<<16);
	}
	else
	{
		//HAL_GPIO_WritePin(GPIOF, RAM_CLK_Pin, GPIO_PIN_RESET);
		GPIOF->BSRR=1;
		data=GPIOG->IDR;
		//HAL_GPIO_WritePin(GPIOF, RAM_CLK_Pin, GPIO_PIN_SET);
		GPIOF->BSRR=(1<<16);
	}
	return data;
}

*/
static void SRAM_RegisterSet()
{
	HAL_GPIO_WritePin(GPIOC, RAM_CLK_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, RAM_CS_Pin|RAM_RAS_Pin|RAM_WE_Pin|RAM_CAS_Pin, GPIO_PIN_RESET);
	GPIOA->BSRR=0xFF0000;
	GPIOB->BSRR=0xFF000000;
	GPIOA->BSRR=0x27;
	HAL_GPIO_WritePin(GPIOC, RAM_CLK_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, RAM_CLK_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, RAM_CS_Pin|RAM_RAS_Pin , GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, RAM_CLK_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, RAM_CLK_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, RAM_CLK_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, RAM_CLK_Pin, GPIO_PIN_RESET);
}
static void SRAM_BurstStop(void)
{
	GPIOC->BSRR=0xC0042003;
	GPIOC->BSRR=0xC0042003;
	GPIOC->BSRR=0xC0042003;
	GPIOC->BSRR=0x4000;
	GPIOC->BSRR=0x4000;
	GPIOC->BSRR=0x4000;
	GPIOC->BSRR=0x40008000;
	GPIOC->BSRR=0x40008000;
	GPIOC->BSRR=0x40008000;
	GPIOC->BSRR=0x4000;
	GPIOC->BSRR=0x4000;
	GPIOC->BSRR=0x4000;
	GPIOC->BSRR=0x40000000;
	GPIOC->BSRR=0x40000000;
	GPIOC->BSRR=0x40000000;
	GPIOC->BSRR=0x4000;
	GPIOC->BSRR=0x4000;
	GPIOC->BSRR=0x4000;
	GPIOC->BSRR=0x40000000;
	GPIOC->BSRR=0x40000000;
	GPIOC->BSRR=0x40000000;
}
static void SRAM_Init(void)
{
	HAL_GPIO_WritePin(GPIOC, RAM_CKE_Pin, GPIO_PIN_SET);
	SRAM_Precharge();
	SRAM_AutoRefresh();
	SRAM_RegisterSet();
}

static void PicToRam(char sector,const TCHAR* path)
{

	UINT wbytes=0;
	BYTE buffer[960];
	WORD color=0;
	FIL MyFile;
	int ad,bank;
	ad=sector*272;
	bank=ad & 0x6000;

	if(f_open(&MyFile,path, FA_READ)==FR_OK)
	{
		number++;
		f_lseek(&MyFile,10);
		/* Load Picture ------------------------------------------ */
		for(int j=0;j<272;j++)
		{
			f_read(&MyFile,buffer,960,&wbytes);
			color=( (buffer[0] << 8) | buffer[1] );
			SRAM_RowBankActive(j+ad);
			SRAM_Write(bank,color,0);
			for(int c=1;c<480;c++)
			{
				color=( (buffer[c*2] << 8) | buffer[c*2+1] );
				SRAM_Write(bank,color,1);
			}

			SRAM_BurstStop();
			SRAM_Precharge();
		}


		f_close(&MyFile);
	}

}

static void LCD_Display(char state)
{
	HAL_GPIO_WritePin(GPIOA,LCD_DIS_Pin,state);
	HAL_GPIO_WritePin(GPIOA,LCD_BLK_Pin, state);

}
static void LCD_Init()
{
	HAL_GPIO_WritePin(GPIOA,LCD_HSY_Pin|LCD_CLK_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC,LCD_VSY_Pin|LCD_DE_Pin, GPIO_PIN_RESET);
}
static void LCD_Hsync(char de,int bank)
{

	GPIOA->BSRR=(1<<24);
	GPIOA->BSRR=(1<<26);
	GPIOA->BSRR=(1<<10);
	GPIOA->BSRR=(1<<8);
	cnth=0;
	while(cnth<45)
	{
		GPIOA->BSRR=(1<<26);
		GPIOA->BSRR=(1<<10);
		cnth++;
	}

	if(de==1)
	{
		// SRAM_Read##############
		GPIOC->BSRR=0xC0022005;
		GPIOC->BSRR=0xC0022005;
		GPIOC->BSRR=0xC0022005;
		GPIOA->BSRR=0xFF0000;
		GPIOB->BSRR=0xFF000000;
		GPIOB->BSRR=bank;
		GPIOE->MODER=0;
		GPIOC->BSRR=0x4000;
		GPIOC->BSRR=0x4000;
		GPIOC->BSRR=0x4000;
		GPIOC->BSRR=0x40008000;
		GPIOC->BSRR=0x40008000;
		GPIOC->BSRR=0x40008000;
		GPIOC->BSRR=(1<<6);

		while(cnth<525)
		{
			GPIOA->BSRR=(1<<10);
			GPIOC->BSRR=0x4000;
			GPIOA->BSRR=(1<<10);
			GPIOC->BSRR=0x4000;
			GPIOA->BSRR=(1<<10);
			GPIOC->BSRR=0x4000;
			GPIOA->BSRR=(1<<26);
			GPIOC->BSRR=0x40000000;
			GPIOA->BSRR=(1<<26);
			GPIOC->BSRR=0x40000000;
			GPIOA->BSRR=(1<<26);
			GPIOC->BSRR=0x40000000;
			cnth++;
		}

		GPIOC->BSRR=(1<<22);

	}
	else
	{
		while(cnth<525)
		{
			GPIOA->BSRR=(1<<26);
			GPIOA->BSRR=(1<<10);
			cnth++;
		}
		SRAM_Precharge();
		SRAM_AutoRefresh();
	}

}
static void LCD_Show(char sector)
{
	int row;
	int bank;
	row=sector*272;
	bank=row & 0x6000;
	GPIOC->BSRR=(1<<23);
	LCD_Hsync(0,bank);
	GPIOC->BSRR=(1<<7);
	cntv=0;
	while(cntv<16)
	{
		LCD_Hsync(0,bank);
		cntv++;
	}

	cntv=0;
	while(cntv<272)
	{
		SRAM_RowBankActive(cntv+row);
		LCD_Hsync(1,bank);
		cntv++;
		SRAM_BurstStop();
		SRAM_Precharge();
		SRAM_AutoRefresh();
	}

}

static void Slide_Show(char a,char b)
{
	int a_row,a_bank,b_row,b_bank;

	a_row=a*272;
	a_bank=a_row & 0x6000;

	b_row=b*272;
	b_bank=b_row & 0x6000;

	for(int i=0;i<34;i++)
	{
		GPIOC->BSRR=(1<<23);
		LCD_Hsync(0,0);
		GPIOC->BSRR=(1<<7);
		cntv=0;
		while(cntv<16)
		{
			LCD_Hsync(0,0);
			cntv++;
		}

		if(a>b)
		{
			for(int m=i*8;m<272;m++)
			{

				SRAM_RowBankActive(m+a_row);
				LCD_Hsync(1,a_bank);
				SRAM_BurstStop();
				SRAM_Precharge();
				SRAM_AutoRefresh();
			}
			for(int n=0;n<i*8;n++)
			{

				SRAM_RowBankActive(n+b_row);
				LCD_Hsync(1,b_bank);
				SRAM_BurstStop();
				SRAM_Precharge();
				SRAM_AutoRefresh();
			}
		}
		else
		{
			for(int m=272-i*8;m<272;m++)
			{

				SRAM_RowBankActive(m+b_row);
				LCD_Hsync(1,b_bank);
				SRAM_BurstStop();
				SRAM_Precharge();
				SRAM_AutoRefresh();
			}
			for(int n=0;n<272-i*8;n++)
			{

				SRAM_RowBankActive(n+a_row);
				LCD_Hsync(1,a_bank);
				SRAM_BurstStop();
				SRAM_Precharge();
				SRAM_AutoRefresh();
			}
		}
	}

}



void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage 
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}


static void MX_SDIO_SD_Init(void)
{

  hsd.Instance = SDIO;
  hsd.Init.ClockEdge = SDIO_CLOCK_EDGE_RISING;
  hsd.Init.ClockBypass = SDIO_CLOCK_BYPASS_DISABLE;
  hsd.Init.ClockPowerSave = SDIO_CLOCK_POWER_SAVE_DISABLE;
  hsd.Init.BusWide = SDIO_BUS_WIDE_1B;
  hsd.Init.HardwareFlowControl = SDIO_HARDWARE_FLOW_CONTROL_DISABLE;
  hsd.Init.ClockDiv = 0;
  /* USER CODE BEGIN SDIO_Init 2 */

  /* USER CODE END SDIO_Init 2 */

}


static void MX_USART1_UART_Init(void)
{

  huart1.Instance = USART1;
  huart1.Init.BaudRate = 9600;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }


}



static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5 
                          |GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9 
                          |GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13 
                          |GPIO_PIN_14|GPIO_PIN_15|GPIO_PIN_0|GPIO_PIN_1, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, RAM_CKE_Pin|RAM_CLK_Pin|RAM_CS_Pin|RAM_RAS_Pin 
                          |RAM_CAS_Pin|RAM_WE_Pin|LCD_DE_Pin|LCD_VSY_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, RAM_A0_Pin|RAM_A1_Pin|RAM_A2_Pin|RAM_A3_Pin 
                          |RAM_A4_Pin|RAM_A5_Pin|RAM_A6_Pin|RAM_A7_Pin 
                          |LCD_HSY_Pin|LCD_DIS_Pin|LCD_CLK_Pin|LCD_BLK_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, RAM_A10_Pin|RAM_A11_Pin|RAM_A12_Pin|RAM_A13_Pin 
                          |RAM_A14_Pin|RAM_A15_Pin|RAM_A8_Pin|RAM_A9_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : PE2 PE3 PE4 PE5 
                           PE6 PE7 PE8 PE9 
                           PE10 PE11 PE12 PE13 
                           PE14 PE15 PE0 PE1 */
  GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5 
                          |GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9 
                          |GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13 
                          |GPIO_PIN_14|GPIO_PIN_15|GPIO_PIN_0|GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : RAM_CKE_Pin RAM_CLK_Pin RAM_CS_Pin */
  GPIO_InitStruct.Pin = RAM_CKE_Pin|RAM_CLK_Pin|RAM_CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : RAM_RAS_Pin RAM_CAS_Pin RAM_WE_Pin LCD_DE_Pin 
                           LCD_VSY_Pin */
  GPIO_InitStruct.Pin = RAM_RAS_Pin|RAM_CAS_Pin|RAM_WE_Pin|LCD_DE_Pin 
                          |LCD_VSY_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : IN_TR_Pin IN_PH_Pin IN_UP_Pin */
  GPIO_InitStruct.Pin = IN_TR_Pin|IN_PH_Pin|IN_UP_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : RAM_A0_Pin RAM_A1_Pin RAM_A2_Pin RAM_A3_Pin 
                           RAM_A4_Pin RAM_A5_Pin RAM_A6_Pin RAM_A7_Pin 
                           LCD_HSY_Pin LCD_DIS_Pin LCD_CLK_Pin */
  GPIO_InitStruct.Pin = RAM_A0_Pin|RAM_A1_Pin|RAM_A2_Pin|RAM_A3_Pin 
                          |RAM_A4_Pin|RAM_A5_Pin|RAM_A6_Pin|RAM_A7_Pin 
                          |LCD_HSY_Pin|LCD_DIS_Pin|LCD_CLK_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : IN_DN_Pin IN_OVL_Pin IN_DO_Pin */
  GPIO_InitStruct.Pin = IN_DN_Pin|IN_OVL_Pin|IN_DO_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : RAM_A10_Pin RAM_A11_Pin RAM_A12_Pin RAM_A13_Pin 
                           RAM_A14_Pin RAM_A15_Pin RAM_A8_Pin RAM_A9_Pin */
  GPIO_InitStruct.Pin = RAM_A10_Pin|RAM_A11_Pin|RAM_A12_Pin|RAM_A13_Pin 
                          |RAM_A14_Pin|RAM_A15_Pin|RAM_A8_Pin|RAM_A9_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : IN_A_Pin IN_B_Pin IN_C_Pin IN_D_Pin 
                           IN_E_Pin IN_F_Pin IN_G_Pin SW1_Pin 
                           SW2_Pin IN_10_Pin */
  GPIO_InitStruct.Pin = IN_A_Pin|IN_B_Pin|IN_C_Pin|IN_D_Pin 
                          |IN_E_Pin|IN_F_Pin|IN_G_Pin|SW1_Pin 
                          |SW2_Pin|IN_10_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pin : IN___Pin */
  GPIO_InitStruct.Pin = IN___Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(IN___GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : LCD_BLK_Pin */
  GPIO_InitStruct.Pin = LCD_BLK_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LCD_BLK_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
