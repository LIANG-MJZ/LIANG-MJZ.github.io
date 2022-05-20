# [EXTI⇨程序](_Study\STM32\1\project\exti.md)

1. `RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOx, ENABLE); //使能 GPIOx外设时钟`
2. `RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE); //使能 功能复用 IO 时钟`
3. `GPIO_Init(GPIOx, &GPIO_InitStructure); //初始化GPIOx 外设`
4. `/*❗*/GPIO_EXTILineConfig(GPIO_PortSourceGPIOx, GPIO_PinSourcex); //选择GPIOx GPIO_PinSourcex管脚用作外部中断线路`
5. `EXTI_Init(&EXTI_InitStructure); //初始化中断`
6. `NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置优先级分组，建议放在main里`
7. `NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn; //开启中断EXTIx_10_IRQn线`
   - `NVIC_Init(&NVIC_InitStructure); //初始化外设 NVIC 寄存器`


- `void EXTI15_10_IRQHandler(void);  //开启中断15线`