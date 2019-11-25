#include "stack.h"
#define STACK_SIZE 3

int StackStore[STACK_SIZE];
int *topPtr;
int *basePtr;

// Initialize the stack internals
void init_stack(void) {
  
  topPtr = 0;
  basePtr = 0;
  
  for (int i = 0; i < STACK_SIZE; i++) {
    StackStore[i] = 0;
  }
}

// Push an element onto the stack.
// Return 0 if successful, -1 if failed.
int push_item_on_stack(int item) {
  int result = -1;
  
  // If stack is empty, store the item to the first element of the array.
  if (is_stack_empty() == 1) {
     topPtr = &StackStore[0];
     basePtr = topPtr;
     *topPtr = item;
     result = 0;
  } else {
     // If stack isn't full, store the item to the next element of the array.
     if (is_stack_full() != 1) {
        *(++topPtr) = item;
        result = 0;
     }
  }
  
  return result;
}

// Pop an element off of the stack.
// Return status of 0 if successful and the element at the top of the
// stack is stored in the parameter item. If failed, the status is -1.
int pop_item_from_stack(int *item) {
  int result = -1;
  
  if (is_stack_empty() != 1) {
     *item = *topPtr;
     
     if (topPtr != basePtr) {
        topPtr--;
     } else {
        // Reach the bottom of the stack. Last item has been popped off
        // the stack. Initialize the array and set topPtr and basePtr to zero
        // so items can be stored starting at the first element of the array.
        init_stack();
     }
     result = 0;
  }
  
  return result;
}

// Return 1 if the stack is empty; otherwise,
// -1 is returned.
int is_stack_empty(void) {
  int result = -1;
  
  if ((topPtr == 0) && (basePtr == 0)) {
     result = 1;
  }
  
  return result;
}

// Return 1 is the stack is full; otherwise,
// -1 is returned.
int is_stack_full(void) {
  int result = -1;
  
  if (topPtr == &StackStore[STACK_SIZE - 1]) {
     result = 1;
  }
  
  return result;
}

int no_parms(void) {
   int lVar1, lVar2, lSum;
   lVar1 = 3;
   lVar2 = 4;
   
   lSum = lVar1 + lVar2;
   return lSum;
}

int multiple_parms(int arg1, int arg2, int arg3, int arg4, int arg5) {
  int locVar1 = arg1;
  int locVar2 = arg2;
  int locVar3 = arg3;
  int locVar4 = arg4;
  int locVar5 = arg5;
  
  int sum = locVar1 + locVar2 + locVar3 + locVar4 + locVar5;
  return sum;
}

void caller_mult_parms(void) {
  int parm1, parm2, parm3, parm4, parm5, testSum;
  
  parm1 = 0;
  parm2 = 1;
  parm3 = 2;
  parm4 = 3;
  parm5 = 4;
  
  testSum = multiple_parms(parm1, parm2, parm3, parm4, parm5);
  //testSum = no_parms();
}