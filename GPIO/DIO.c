#include "DIO.h"
#include "bitwise_operation.h"
#include "tm4c123gh6pm.h"
#include <stdint.h>
void DIO_Init(){
   SYSCTL_RCGCGPIO_R |= 0x00000020;
  while((SYSCTL_PRGPIO_R&0x00000020) == 0){};
  GPIO_PORTF_LOCK_R = 0x4C4F434B;
  GPIO_PORTF_CR_R = 0x1F;
  GPIO_PORTF_DIR_R = 0x0E;
  GPIO_PORTF_PUR_R = 0x11;
  GPIO_PORTF_DEN_R = 0x1F;
}


void DIO_WritePin(int bit, int value){
  if(value == 1){
    set_Bit(GPIO_PORTF_DATA_R, bit);
  }else if(value == 0){
    clear_Bit(GPIO_PORTF_DATA_R, bit);
  }

}

void DIO_WritePort(int bit, int value){
  
}

int DIO_ReadPin(int bit){
  return get_Bit(GPIO_PORTF_DATA_R, bit);
}


