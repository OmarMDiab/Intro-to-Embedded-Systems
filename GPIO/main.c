#include "tm4c123gh6pm.h"
#include "DIO.h"

#define Task2

int getcolor(){
  int color_index=0;
  
  if (DIO_ReadPin(1) && DIO_ReadPin(2) && DIO_ReadPin(3)){
  color_index=10;
  }
      
  else if (DIO_ReadPin(1)){
  color_index=1;
  }
else if (DIO_ReadPin(2)){
  color_index=2;
  }
            
else if(DIO_ReadPin(3)){
color_index=3;
}
  return color_index;
}
       
       
       
int main()
{
  DIO_Init();
      // start with white: -
 DIO_WritePin(1,1);
 DIO_WritePin(2,1);
 DIO_WritePin(3,1);
  
  while(1){    

    
    int sw1 = DIO_ReadPin(0);
    int sw2 = DIO_ReadPin(4); 
    
#ifdef Task1
    
    if(sw1 == 0 && sw2 ==1){
    DIO_WritePin(1,0);
   DIO_WritePin(2,0);
   DIO_WritePin(3,0);
   DIO_WritePin(2,1);
    }else if (sw2 == 0 && sw1 ==1){
      
      DIO_WritePin(1,0);
   DIO_WritePin(2,0);
   DIO_WritePin(3,0);
   DIO_WritePin(1,1);
      
    }else if(sw1 == 0 && sw2 == 0){
   DIO_WritePin(1,0);
   DIO_WritePin(2,0);
   DIO_WritePin(3,0);
   DIO_WritePin(3,1);
   for(int i=0; i <1000000;i++){}
   
    }
#endif



#ifdef Task2
   int  color= getcolor();
   if (!sw1){
     switch (color){
     case 10:
       DIO_WritePin(2,0);
       DIO_WritePin(3,0);
       DIO_WritePin(1,1);
       break;
       
     case 1:
       DIO_WritePin(1,0);
       DIO_WritePin(2,0);
       DIO_WritePin(3,1);
       break;
       
       case 3:
       DIO_WritePin(1,0);
       DIO_WritePin(2,1);
       DIO_WritePin(3,0);
       break;
       
       case 2:
       DIO_WritePin(1,1);
       DIO_WritePin(2,1);
       DIO_WritePin(3,1);
       break;
       
     }
   }
    if (!sw2){
     switch (color){
       
     case 10:
       DIO_WritePin(1,0);
       DIO_WritePin(3,0);
       DIO_WritePin(2,1);
       break;
       
     case 1:
       DIO_WritePin(1,1);
       DIO_WritePin(2,1);
       DIO_WritePin(3,1);
       break;
       
       case 3:
       DIO_WritePin(1,1);
       DIO_WritePin(2,0);
       DIO_WritePin(3,0);
       break;
       
       case 2:
       DIO_WritePin(1,0);
       DIO_WritePin(2,0);
       DIO_WritePin(3,1);
       break;
       
     }
   }
 

    for(int i=0; i <1000000;i++){}
   
         
      
#endif    
     
    
    
  
  
}
  return 0;
}
       
 