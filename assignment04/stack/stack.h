#ifndef __STACK_H__
#define __STACK_H__

void init_stack(void);
int push_item_on_stack(int item);
int pop_item_from_stack(int* item);
int is_stack_empty(void);
int is_stack_full(void);

int no_parms(void);
int multiple_parms(int arg1, int arg2, int arg3, int arg4, int arg5);
void caller_mult_parms(void);

#endif
