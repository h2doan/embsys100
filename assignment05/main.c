int swap_pointers(int **aPtr, int **bPtr);

int swap_pointers(int **aPtr, int **bPtr){
  int *tempPtr = 0;
  int result = 0;
  
  if ((*aPtr != 0) && (*bPtr != 0) &&
      (**aPtr != 0) && (**bPtr != 0)) {
    // tempPtr is stored with the content (address which aPtr is pointing)
    // of aPtr.
    // aPtr is stored with the content (address which bPtr is pointing) of bPtr.
    // bPtr is stored with the address that aPtr is pointing.
    tempPtr = *aPtr;
    *aPtr = *bPtr;
    *bPtr = tempPtr;

    result = 1;
  }
  return result;
}

int main()
{
  int x = 1500;
  int y = 3000;
  
  int *xPtr = 0;
  int *yPtr = 0;
  
  xPtr = &x;
  yPtr = &y;
   
  swap_pointers(&xPtr, &yPtr);
  
  return 0;
}
