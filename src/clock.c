#include "stm32f3xx.h"
#include "clock.h"


void init_clock(){ 
 
    RCC->CR |= RCC_CR_HSION;

    while(!(RCC->CR |= RCC_CR_HSIRDY));
    RCC->CFGR &= ~RCC_CFGR_SW;
    RCC->CR &= ~RCC_CR_PLLON;
    RCC->CFGR &= ~RCC_CFGR_PLLSRC;
    RCC->CFGR &= ~RCC_CFGR_PLLMUL;
    RCC->CFGR |= RCC_CFGR_PLLMUL10;

    RCC->CFGR |= RCC_CFGR_PPRE1_DIV8;
    RCC->CFGR |= RCC_CFGR_PPRE2_DIV1;
    RCC->CFGR |= RCC_CFGR_HPRE_DIV1;

    RCC->CR |= RCC_CR_PLLON;
    while(!(RCC->CR |= RCC_CR_PLLRDY));
    RCC->CFGR |= RCC_CFGR_SW_1;    
      
}