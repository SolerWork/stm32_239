#include "stm32f3xx.h"
#include "port.h"
#include "adc.h"
#include "dac.h"
#include "tim.h"
#include "filter.h"
#include "clock.h"

uint16_t x;
uint16_t y;
uint16_t start;

int main(){
    
    init_clock();
    init_port();
    init_adc(); 
    init_dac();
    init_timer();
    
    while (1){
        if(!(TIM3->SR & TIM_SR_UIF)){
            
            ADC3->CR |= ADC_CR_ADSTART;         
            while(!(ADC3->ISR & ADC_ISR_EOS));
            x = ADC3->DR;
            ADC3->ISR &= ~ADC_ISR_EOS;
            ADC3->ISR &= ~ADC_ISR_EOC;

            y=filter(x);

            DAC1->DHR12R2=y;
        }  
        TIM3->SR &= ~TIM_SR_UIF;
    }                      
}
           