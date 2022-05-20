# [⇦EXTI流程](_Study\STM32\1\define\exti.md)

```c
void EXTI_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); //使能 GPIOB外设时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE); //使能 功能复用 IO 时钟
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure); //初始化GPIO 外设
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource14); //选择 GPIO 管脚用作外部中断线路
	
	EXTI_InitTypeDef EXTI_InitStructure;
	EXTI_InitStructure.EXTI_Line = EXTI_Line14; //外部中断线 14
	EXTI_InitStructure.EXTI_LineCmd = ENABLE; //使能选中路线
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt; //设置 EXTI 线路为中断请求
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling; //设置输入线路下降沿为中断请求
	EXTI_Init(&EXTI_InitStructure); //初始化中断
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn; //开启中断15线
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStructure);
}

uint16_t CountSensor_Count;
uint16_t CountSensor_Get(void)
{
	return CountSensor_Count;
}

void EXTI15_10_IRQHandler(void)
{
	if (EXTI_GetITStatus(EXTI_Line14) == SET)
	{
		/*如果出现数据乱跳的现象，可解除以下注释，再次判断引脚电平，以避免抖动*/
//		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14) == 0)
//		{
			CountSensor_Count ++;
//		}
		EXTI_ClearITPendingBit(EXTI_Line14);
	}
}
```

```C
int main(void)
{
	OLED_Init();
	CountSensor_Init();
	
	OLED_ShowString(1, 1, "Count:");
	
	while (1)
	{
		OLED_ShowNum(1, 7, CountSensor_Get(), 5);
	}
}
```

