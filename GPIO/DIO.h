// DIO Operations: -
  
// Controller Initializer
  void DIO_Init();

// Write/Read Pins
  void DIO_WritePin(int bit,int value);
  
  int DIO_ReadPin(int bit);

// Write/Read Ports
  void DIO_WritePort(int mask, int value);
  
  int DIO_ReadPort(int mask);
  
  // lit LED [ON]: -
  void lit_LED(int color);
  
  // Get Current Lit LED:-
  int getcolor(); // 10: white, 1: Red, 2: Blue, 3: Red, 0: No_lit_LED
  