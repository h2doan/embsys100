#include <stdio.h>

union Overlay {
  int numberInt;
  char lowByte1;
  char lowByte2;
  char highByte1;
  char highByte2;
} number;

int big_or_little_endian(void);

// Determine if the computer is little endian or big endian.
// Return 0 for little endian, 1 for big endian.
// Return -1 for all other cases.
int big_or_little_endian(void) {
  int result = -1;
  
  int lowAddrVar1 = 0;
  int lowAddrVar2 = 0;
  int hiAddrVar1 = 0;
  int hiAddrVar2 = 0;
  
  number.numberInt = 0xB7C;
  int *ptrVar = &number.numberInt;
  
  // Type casting the pointer ptrVar to points to char data
  // so it will move one byte address at a time.
  char *ptrVar2 = (char *) ptrVar;
  
  lowAddrVar1 = *ptrVar2;
  lowAddrVar2 = *(++ptrVar2);
  hiAddrVar1 = *(++ptrVar2);
  hiAddrVar2 = *(++ptrVar2);
  
  if ((hiAddrVar1) && (hiAddrVar2) && (!lowAddrVar1) && (!lowAddrVar2))
    result = 1;
  
  if ((!hiAddrVar1) && (!hiAddrVar2) && (lowAddrVar1) && (lowAddrVar2))
    result = 0;
  
  return result;
}

int main()
{
  int big_or_little = big_or_little_endian();
  int bigEndian = 0;
  int littleEndian = 0;
  
  if (big_or_little >= 0)
  {
    if (big_or_little)
      bigEndian = 1;
    else
      littleEndian = 1;
  }
  
  return 0;
}
