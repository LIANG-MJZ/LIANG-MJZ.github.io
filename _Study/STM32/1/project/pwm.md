# [⇦PWM流程](_Study\STM32\1\define\pwm.md)

- pwm 实现呼吸灯

```c
void Pwm_Init(void)
{
    //使能或者失能 APB1 TIM2外设时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
    //使能或者失能 APB2 GPIOA外设时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); 
    
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //复用推挽输出
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;		//GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
    
	TIM_InternalClockConfig(TIM2); //设置 TIM2 内部时钟
    
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1; //1分频 时钟分割
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up; //TIM2 向上计数模式
	TIM_TimeBaseInitStructure.TIM_Period = 100 - 1;	//ARR
	TIM_TimeBaseInitStructure.TIM_Prescaler = 720 - 1; //PSC
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure); //初始化 TIM2 的时间基数单元
    
	TIM_OCInitTypeDef TIM_OCInitStructure; //默认初始化，以保证代码正常运行
	TIM_OCStructInit(&TIM_OCInitStructure);
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //TIM2 脉冲宽度调制模式 1
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low; //TIM2 输出比较极性低
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //使能输出比较状态
	TIM_OCInitStructure.TIM_Pulse = 0;		//CCR
	TIM_OC1Init(TIM2, &TIM_OCInitStructure); //初始化外设 TIM1 通道

	TIM_Cmd(TIM2, ENABLE); //使能或者失能 TIM2 外设
}

void PWM_SetCompare1(uint16_t Compare)
{
	TIM_SetCompare1(TIM2, Compare);
}
```

```c
uint8_t i;
int main(void)
{
	OLED_Init();
	PWM_Init();
    
	while (1)
	{
		for (i = 0; i <= 100; i++)
		{
			PWM_SetCompare1(i);
			Delay_ms(10);
		}
		for (i = 0; i <= 100; i++)
		{
			PWM_SetCompare1(100 - i);
			Delay_ms(10);
		}
	}
}
```

