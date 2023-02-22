#include "stm32f3xx.h"
#include "tim.h"

void init_timer(){
     RCC->APB1ENR |=RCC_APB1ENR_TIM3EN;

     TIM3->PSC=102-1;
     TIM3->ARR=4-1;

     TIM3->DIER |= TIM_DIER_UIE;

     TIM3->CR1 |= TIM_CR1_CEN;
}
