#include "stm32f3xx.h"
#include "adc.h"
#include "port.h"

void init_adc(){
   
    RCC->AHBENR |= RCC_AHBENR_ADC34EN;
    RCC->CFGR2  |= RCC_CFGR2_ADCPRE34_DIV16; 
    ADC34_COMMON->CCR |= ADC34_CCR_CKMODE_0;
    

    ADC3->CR &= ~ADC_CR_ADVREGEN;
    ADC3->CR |= ADC_CR_ADVREGEN_0; 

    for(volatile uint16_t d = 0; d<50000; ++d);
    

    
    ADC3->CFGR &= ~ADC_CFGR_RES; 
    ADC3->CFGR &= ~ADC_CFGR_ALIGN; 

    ADC3->SQR1 &= ~ADC_SQR1_SQ1;
    ADC3->SQR1 |= ADC_SQR1_SQ1_2 | ADC_SQR1_SQ1_0;
    ADC3->SQR1 &= ~ADC_SQR1_L;
 
    ADC3->SMPR1 |= (ADC_SMPR1_SMP5_1 | ADC_SMPR1_SMP5_0); 

    ADC3->CR |= ADC_CR_ADEN;


    
    while(!(ADC3->ISR & ADC_ISR_ADRDY));
    
    
}

