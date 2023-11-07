#include "tm4c123gh6pm.h"
#include "DIO.h"

// Lab 4
#define Task1_evenORodd
    
int main()
{
  // initialize controller
  DIO_Init();
  
// start with white: -
 lit_LED(10);
 
// general counter (used in some tasks)
 int i = 0; 
 
while(1){    

    // Read the 2 switches pins
    int sw1 = DIO_ReadPin(0);
    int sw2 = DIO_ReadPin(4); 
    
// Task1 Toggle:-     
#ifdef Task1
    
    if(sw1 == 0 && sw2 ==1){
    lit_LED(2); // Blue
    }
    else if (sw2 == 0 && sw1 ==1){
     lit_LED(1);  // Red
    }
    else if(sw1 == 0 && sw2 == 0){
     lit_LED(3); // Green
     
   for(int i=0; i <1000000;i++){}  // Delay
    }
#endif


// Task 2 Main
#ifdef Task2
   int  color= getcolor();
   
   // clockwise FSM: -
   if (!sw1 && sw2){
     switch (color){
     case 10:
       lit_LED(1);
       break;
       
     case 1:
       lit_LED(3);
       break;
       
       case 3:
       lit_LED(2);
       break;
       
       case 2:
       lit_LED(10);
       break;
       
     }
   }
   
   // Anti-Clockwise FSM: -
    if (!sw2 && sw1){
     switch (color){
       
     case 10:
       lit_LED(2);
       break;
       
     case 1:
       lit_LED(10);
       break;
       
       case 3:
       lit_LED(1);
       break;
       
       case 2:
         lit_LED(3);
       break;
       
     }
   }
   
   // task2 LMS: -
   // if pressed 2 switches it will return to white whatever state we are in 
   if (!sw1 && !sw2){
   lit_LED(10); // white
   }
   
    for(int i=0; i <1000000;i++){}  // (Delay for FSM)           
   
#endif    

   // Task 1 LMS: -
#ifdef Task1_evenORodd
   // where even = blue and odd = Red
   int even_odd[5]={3,6,5,7,10}; 
   
   if(!sw1 || !sw2){
     
     if (even_odd[i]%2==0)  // even
        lit_LED(2); // blue
     
     else  // odd
        lit_LED(1); // Red
     
     i++;
   }
   
   // loop again through array :)
   if (i>4)
     i=0;
   
   for(int i=0; i <1000000;i++){}  // (Delay) 
   
#endif   
   
   
   
   
} // while end


  return 0;
}
       
 