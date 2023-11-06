// Bitwise Operations
#define set_Bit(reg, bit)      reg |= (1<<bit);
#define clear_Bit(reg, bit)    reg &= ~(1<<bit);
#define get_Bit(reg, bit)      ((1<<bit) & reg) >> bit;
#define toggle_Bit(reg, bit)   reg ^= (1<<bit);