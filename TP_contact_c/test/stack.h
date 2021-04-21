#include "list_simple.h"


#ifndef _STACK_H_
#define _STACK_H_

/**
 *
 */
typedef list_simple stack;

/**
 *
 */
stack* stk_create_stack();


/**
 *
 */
contact* stk_create_node(char* name, char *phone_number);

/**
 *
 */
void stk_push (stack* stk, contact* pnew);

/**
 *
 */
contact* stk_pop(stack* stk);

/**
 *
 */
void stk_display_contact(contact* ptr);

#endif
