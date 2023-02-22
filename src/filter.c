#include "stm32f3xx.h"
#include "filter.h"

uint16_t filter(uint16_t x){
     z4=z3;
     z3=z2;
     z2=z1;
     z1=z;
     z = x - ((-3.798195)*z1 + 5.466153*z2 + (-3.532104)*z3 + 0.864959*z4);
     j =2047+ z*0.002451 + z1*0 + z2*(-0.004902) + z3*0 + z4*0.002451;
     return(j);
}