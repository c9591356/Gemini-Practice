#define Set_Bit(reg,n)   reg|(1<<n)
#define Clear_Bit(reg,n)   reg&~(1<<n)
#define Toggle_Bit(reg,n) reg^(1<<n)