# STM32_Program

# GPIO
[⏩代码](_Study\STM32\program\gpio.md)

# USART
[⏩代码](_Study\STM32\program\usart.md)

# EXTI

 1. 



[⏩代码](_Study\STM32\program\exti.md)

# TIMER

## 内部时钟

[⏩代码](_Study\STM32\program\timer.md)

1. `RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIMx, ENABLE); //使能或者失能 APB1 TIMx外设时钟`
2. `TIM_InternalClockConfig(TIMx); //设置 TIMx 内部时钟开启时钟 `
3. `TIM_InternalClockConfig(TIMx); //设置 TIMx 内部时钟`
4. `TIM_TimeBaseInit(TIMx, &TIM_TimeBaseInitStructure); //初始化 TIMx 的时间基数单元`
5. `TIM_ClearFlag(TIMx, TIM_FLAG_Update); //清除 TIMx 的待处理标志位:复位后从零开始`
6. `TIM_ITConfig(TIMx, TIM_IT_Update, ENABLE); // 使能或者失能指定的 TIMx 中断`
7. `TIM_Cmd(TIMx, ENABLE); //使能或者失能 TIMx 外设`
8. `NVIC_PriorityGroupConfig(NVIC_PriorityGroup_x);   //设置优先级分组，建议放在main里`
9. `NVIC_Init(&NVIC_InitStructure); //初始化外设 NVIC 寄存器`
   - `void TIMx_IRQHandler(void); // TIMx 中断函数`

---

## 外部时钟

[⏩代码](_Study\STM32\program\timer1.md)

1. `RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIMx, ENABLE); //使能或者失能 APB1 TIMx外设时钟`
2. `RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOx, ENABLE); //使能或者失能 APB2 GPIOx外设时钟`
3. `GPIO_Init(GPIOx, &GPIO_InitStructure); //初始化GPIOx外设`
4. `TIM_ETRClockMode2Config(TIMx, TIM_ExtTRGPSC_OFF, TIM_ExtTRGPolarity_NonInverted, 0x00);                   //配置 TIMx 外部时钟模式 2`
5. `TIM_TimeBaseInit(TIMx, &TIM_TimeBaseInitStructure); //初始化 TIMx 的时间基数单元`
6. `TIM_ClearFlag(TIMx, TIM_FLAG_Update); //清除 TIMx 的待处理标志位:复位后从零开始`
7. `TIM_ITConfig(TIMx, TIM_IT_Update, ENABLE); //使能或者失能指定的 TIMx 中断`
8. `NVIC_PriorityGroupConfig(NVIC_PriorityGroup_x);//设置优先级分组，建议放在main里`
9. `NVIC_Init(&NVIC_InitStructure); //初始化外设 NVIC 寄存器`
10. `TIM_Cmd(TIMx, ENABLE); //使能或者失能 TIMx 外设`
  - `TIM_GetCounter(TIMx); //获得 TIMx 计数器的值`


---

---

# PWM

[⏩代码](_Study\STM32\program\pwm.md)

1. `RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIMx, ENABLE); //使能或者失能 APB1 TIMx外设时钟`

2. `RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOx, ENABLE); //使能或者失能 APB2 GPIOx外设时钟`

3. `GPIO_Init(GPIOx, &GPIO_InitStructure); //初始化GPIOx外设`

4. `TIM_InternalClockConfig(TIMx); //设置 TIMx 内部时钟`

5. `TIM_TimeBaseInit(TIMx, &TIM_TimeBaseInitStructure); //初始化 TIMx 的时间基数单元`

6. `TIM_OCInitTypeDef TIM_OCInitStructure; //默认初始化，以保证代码正常运行`

7. `TIM_OC1Init(TIMx, &TIM_OCInitStructure); //初始化外设 TIMx 通道`

8. `TIM_Cmd(TIMx, ENABLE); //使能或者失能 TIMx 外设`

  - `TIM_SetCompare1(TIMx, Compare); //设置 TIMx 捕获比较 1 寄存器值`

  

---

---



# ADC
[⏩代码](_Study\STM32\program\adc.md)







