# 外部定时器
[代码⏪](_Study\STM32\program\base.md)

```c
void Timer_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); //使能或者失能 APB1 TIM2外设时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); //使能或者失能 APB2 GPIOA外设时钟
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure); //初始化GPIOA外设
	
    //配置 TIM2 外部时钟模式 2
	TIM_ETRClockMode2Config(TIM2, TIM_ExtTRGPSC_OFF, TIM_ExtTRGPolarity_NonInverted, 0x00); 
    
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period = 10 - 1;
	TIM_TimeBaseInitStructure.TIM_Prescaler = 1 - 1;
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure); //初始化 TIM2 的时间基数单元
	
	TIM_ClearFlag(TIM2, TIM_FLAG_Update); //清除 TIM2 的待处理标志位:复位后从零开始
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE); //使能或者失能指定的 TIM2 中断
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置优先级分组，建议放在main里
	
	NVIC_InitTypeDef NVIC_InitStructure; 
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStructure); //初始化外设 NVIC 寄存器
	
	TIM_Cmd(TIM2, ENABLE); //使能或者失能 TIM2 外设
}

uint16_t Timer_GetCounter(void)
{
	return TIM_GetCounter(TIM2); //获得 TIM2 计数器的值
}
```

```c
uint16_t Num;
int main(void)
{
	OLED_Init();
	Timer_Init();
	
	OLED_ShowString(1, 1, "Num:");
	OLED_ShowString(2, 1, "CNT:");
	
	while (1)
	{
		OLED_ShowNum(1, 5, Num, 5);
		OLED_ShowNum(2, 5, Timer_GetCounter(), 5);
	}
}

void TIM2_IRQHandler(void) //TIM2 中断函数
{
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)
	{
		Num ++;
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	}
}
```

