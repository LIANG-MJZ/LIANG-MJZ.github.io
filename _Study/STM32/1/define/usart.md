# [USART⇨程序](_Study\STM32\1\project\usart.md)


1. `RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA , ENABLE); //使能 GPIOx外设时钟`

2. `RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 , ENABLE); //使能 GPIOx外设时钟`

3. `GPIO_Init(GPIOA, &GPIO_InitStruct); //初始化GPIOx 外设`

4. `USART_Init(USART1, &USART_InitStruct); //初始化USARTx 外设`

5. `USART_ITConfig( USART1,USART_IT_RXNE, ENABLE); //开启中断`

6. `USART_Cmd(USART1 , ENABLE); //开启USARTx`

7. `NVIC_InitStruct.NVIC_IRQChannel = USART1_IRQn; //使能或者失能指定的 IRQ 通道`

   - `NVIC_Init(&NVIC_InitStruct);`

     