#include <assert.h>
#include "stack.h"

int main(void) {
  int result1;
  int result2;
  int testItem;
  
  caller_mult_parms();
  
  // *******************************************************************
  // Test1: Retrieve item from an empty stack
  // *******************************************************************
  // Arrange:
  result1 = 42;
  result2 = 42;
  testItem = 99;
  init_stack();
  
  // Act:
  result1 = pop_item_from_stack(&testItem);
  
  // Assert:
  assert(-1 == result1);
  assert(99 == testItem);
  
  // *******************************************************************
  // Test2: Successfully retrieve an item from the stack
  // *******************************************************************
  // Arrange:
  result1 = 42;
  result2 = 42;
  testItem = 99;
  init_stack();
  
  // Act:
  result1 = push_item_on_stack(19);
  result2 = pop_item_from_stack(&testItem);
  
  // Assert:
  assert(0 == result1);
  assert(0 == result2);
  assert(19 == testItem);
  
  // *******************************************************************
  // Test3: Fill stack, then get all items.
  // *******************************************************************
  // Arrange:
  testItem = 99;
  init_stack();
  
  // Act:
  push_item_on_stack(19);
  push_item_on_stack(20);
  push_item_on_stack(21);
  
  // Assert:
  assert(0 == pop_item_from_stack(&testItem));
  assert(21 == testItem);
  
  assert(0 == pop_item_from_stack(&testItem));
  assert(20 == testItem);
  
  assert(0 == pop_item_from_stack(&testItem));
  assert(19 == testItem);
  
  // *******************************************************************
  // Test4: Fill stack, then put one more item, should fail
  // *******************************************************************
  // Arrange:
  testItem = 99;
  init_stack();
  
  // Act:
  push_item_on_stack(10);
  push_item_on_stack(11);
  push_item_on_stack(12);
  
  // Assert:
  assert(-1 == push_item_on_stack(13));
  
  assert(0 == pop_item_from_stack(&testItem));
  assert(12 == testItem);
  
  assert(0 == pop_item_from_stack(&testItem));
  assert(11 == testItem);
  
  assert(0 == pop_item_from_stack(&testItem));
  assert(10 == testItem);

  // ***********************************************************************
  // Test5: Fill stack, retrieve one item, then add item, then retieve all
  // ***********************************************************************
  // Arrange:
  testItem = 99;
  init_stack();
  
  // Act:
  push_item_on_stack(10);
  push_item_on_stack(11);
  push_item_on_stack(12);
  
  // Assert:
  assert(0 == pop_item_from_stack(&testItem));
  assert(12 == testItem);
  
  assert(0 == push_item_on_stack(15));
  
  assert(0 == pop_item_from_stack(&testItem));
  assert(15 == testItem);
  
  assert(0 == pop_item_from_stack(&testItem));
  assert(11 == testItem);
  
  assert(0 == pop_item_from_stack(&testItem));
  assert(10 == testItem);

  // ***********************************************************************
  // Test6: Fill stack and retrieve all items twice
  // ***********************************************************************
  // Arrange:
  testItem = 99;
  init_stack();
  
  // Act:
  push_item_on_stack(10);
  push_item_on_stack(11);
  push_item_on_stack(12);
  
  // Assert:
  assert(0 == pop_item_from_stack(&testItem));
  assert(12 == testItem);
  
  assert(0 == pop_item_from_stack(&testItem));
  assert(11 == testItem);
  
  assert(0 == pop_item_from_stack(&testItem));
  assert(10 == testItem);
  
  assert(0 == push_item_on_stack(13));
  assert(0 == push_item_on_stack(14));
  assert(0 == push_item_on_stack(15));
  
  assert(-1 == push_item_on_stack(256));
  
  assert(0 == pop_item_from_stack(&testItem));
  assert(15 == testItem);
  
  assert(0 == pop_item_from_stack(&testItem));
  assert(14 == testItem);
  
  assert(0 == pop_item_from_stack(&testItem));
  assert(13 == testItem);
  
  return 0;
}