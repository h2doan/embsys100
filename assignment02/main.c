int counter = 0x0;
/* int counter = 2; */

int main()
{
/*
  unsigned int counter = 2;
  
  counter++;
  counter++;
  counter++;
  counter++;
  counter++;
*/

  int *p_int = (int *)0x20000000;
  ++(*p_int);
  ++(*p_int);
  ++(*p_int);
  counter++;

  return 0;
}
