# [⇦USART流程](_Study\STM32\1\define\usart.md)

```c
void usart_init()
{
	GPIO_InitTypeDef GPIO_InitStruct;
	USART_InitTypeDef USART_InitStruct;
	NVIC_InitTypeDef NVIC_InitStruct;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA , ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 , ENABLE);
	
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_10;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	USART_InitStruct.USART_BaudRate = 9600;
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_InitStruct.USART_Parity = USART_Parity_No;
	USART_InitStruct.USART_StopBits = USART_StopBits_1;
	USART_InitStruct.USART_WordLength = USART_WordLength_8b;
	USART_Init(USART1, &USART_InitStruct);
	
	USART_ITConfig( USART1,USART_IT_RXNE, ENABLE); //开启中断
	USART_Cmd(USART1 , ENABLE);
	
	NVIC_InitStruct.NVIC_IRQChannel = USART1_IRQn; //USART1 全局中断
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 2;
	NVIC_Init(&NVIC_InitStruct);
}
```

```c
void USART_SendString(USART_TypeDef* USARTx, char *str)
{
	while(*str != '\0')
	{
		USART_SendByte(USARTx, *str++);
	}
	while(USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);
}
```

```c
void USART_SendByte(USART_TypeDef* USARTx, uint8_t Data)
{
	assert_param(IS_USART_ALL_PERIPH(USARTx));
	assert_param(IS_USART_DATA(Data)); 
	USARTx->DR = (Data & (uint16_t)0x01FF);
	while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
}
```

```c
uint8_t USART_ReceiveByte(USART_TypeDef* USARTx)
{
	while(!USART_GetFlagStatus(USART1,USART_FLAG_RXNE));
	
	return (uint8_t)USART_ReceiveData(USART1);
}
```

```c
struct __FILE
{
	int handle;
};

FILE __stdout;
_sys_exit(int x)
{
	x = x;
}

int fputc(int ch , FILE *f)
{
	USART_SendData(USART1, (uint8_t) ch);
	while(!USART_GetFlagStatus(USART1,USART_FLAG_TXE));
	return (ch);
}

int fgetc(FILE *f)
{
	while(!USART_GetFlagStatus(USART1,USART_FLAG_RXNE));
	return (int)USART_ReceiveData(USART1);
}
```

