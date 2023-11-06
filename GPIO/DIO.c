#include "DIO.h"
#include "bitwise_operation.h"
#include "tm4c123gh6pm.h"
#include <stdint.h>

// Function to initialize GPIO for TIVA-C microcontroller
void DIO_Init() {
   // Enable clock to GPIO Port F
   SYSCTL_RCGCGPIO_R |= 0x00000020 ;

   // Wait until the clock is stable
   while((SYSCTL_PRGPIO_R & 0x00000020 ) == 0){};

   // Unlock the GPIO Port F for configuration
   GPIO_PORTF_LOCK_R = 0x4C4F434B;

   // Allow changes to the GPIO Port F configuration
   GPIO_PORTF_CR_R = 0x1F;

   // Set the data direction for Port F pins (0-4)
   GPIO_PORTF_DIR_R = 0x0E;  // Pins 1, 2, and 3 as outputs, Pins 0 and 4 as inputs

   // Enable pull-up resistors on Pins 0 and 4
   GPIO_PORTF_PUR_R = 0x11;

   // Enable digital functions on all Port F pins
   GPIO_PORTF_DEN_R = 0x1F;
}

// Read/Write Pins
int DIO_ReadPin(int bit){
  return get_Bit(GPIO_PORTF_DATA_R, bit);
}

void DIO_WritePin(int bit, int value){
  if(value == 1){
    set_Bit(GPIO_PORTF_DATA_R, bit);
  }
  else{
    clear_Bit(GPIO_PORTF_DATA_R, bit);
  }

}

// Read/Write Ports
int DIO_ReadPort(int mask) {
    // Apply the mask to extract the specific bits of interest
    return GPIO_PORTF_DATA_R & mask;
}

void DIO_WritePort(int mask, int value) {
    // Clear the bits specified in the mask while preserving the rest of the bits
    GPIO_PORTF_DATA_R = (GPIO_PORTF_DATA_R & ~mask);
    
    // Set the bits according to the data value and the mask
    GPIO_PORTF_DATA_R |= (value & mask);
}

  // lit LED Control: -
void lit_LED(int color){
  // lit red
  if (color==1){
  DIO_WritePin(1,1);
  DIO_WritePin(2,0);
  DIO_WritePin(3,0);
  }
  // lit blue
  else if (color ==2){
  DIO_WritePin(1,0);
  DIO_WritePin(2,1);
  DIO_WritePin(3,0);
  }
  // lit green
  else if (color ==3){
  DIO_WritePin(1,0);
  DIO_WritePin(2,0);
  DIO_WritePin(3,1);
  }
  // lit white
  else if (color == 10){
  DIO_WritePin(1,1);
  DIO_WritePin(2,1);
  DIO_WritePin(3,1);
  }
  // TURN all off
  else if (color == 0){
  DIO_WritePin(1,0);
  DIO_WritePin(2,0);
  DIO_WritePin(3,0);
  }

}

// function to determine the Current Lit LED
int getcolor(){
  int color_index=0; // normally all [off]
  
  if (DIO_ReadPin(1) && DIO_ReadPin(2) && DIO_ReadPin(3)){
  color_index=10; // white
  }
      
  else if (DIO_ReadPin(1)){
  color_index=1; // RED
  }
  
else if (DIO_ReadPin(2)){
  color_index=2; // Blue
  }
            
else if(DIO_ReadPin(3)){
color_index=3; // Green
}
  return color_index;
}



