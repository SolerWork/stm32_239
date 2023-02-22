#include "stm32f3xx.h"
#include "dac.h"
#include "port.h"

void init_dac(){ 
 
    
    RCC->APB1ENR |= RCC_APB1ENR_DAC1EN;
    
    DAC->CR |= DAC_CR_EN2;  
     
    GPIOE->ODR |=  GPIO_ODR_9;
    delay(speed);
    GPIOE->ODR &= ~GPIO_ODR_9;
    delay(speed);    
      
}