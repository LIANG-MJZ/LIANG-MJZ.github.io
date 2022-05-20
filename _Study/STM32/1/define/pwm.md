# [PWM⇨程序](_Study\STM32\1\project\pwm.md)

1. `RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIMx, ENABLE); //使能或者失能 APB1 TIMx外设时钟`

2. `/*❗*/RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOx, ENABLE); //使能或者失能 APB2 GPIOx外设时钟`

3. `GPIO_Init(GPIOx, &GPIO_InitStructure); //初始化GPIOx外设`

4. `TIM_InternalClockConfig(TIMx); //设置 TIMx 内部时钟`

5. `TIM_TimeBaseInit(TIMx, &TIM_TimeBaseInitStructure); //初始化 TIMx 的时间基数单元`

6. `/*❗*/TIM_OCStructInit(&TIM_OCInitStructure); //默认初始化，以保证代码正常运行`

7. `TIM_OC1Init(TIMx, &TIM_OCInitStructure); //初始化外设 TIMx 通道`

8. `TIM_Cmd(TIMx, ENABLE); //使能或者失能 TIMx 外设`

  - `TIM_SetCompare1(TIMx, Compare); //设置 TIMx 捕获比较 1 寄存器值`