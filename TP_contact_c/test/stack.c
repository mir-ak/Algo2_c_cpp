#include <stdio.h>
#include "list_simple.h"
#include "stack.h"

stack* stk_create_stack(){
  stack* stk = (stack*) lsts_create_list();
  return stk;  
}

contact* stk_create_node(char* name, char *phone_number){
  return lsts_create_node(name, phone_number);
}

void stk_push (stack* stk, contact* pnew){
  lsts_insert_head(stk,pnew);
}

contact* stk_pop(stack* stk){
  if(stk->head==NULL){
    return NULL;
  }
  
  contact* tmp = stk_create_node(stk->head->name,stk->head->phone_number);
  lsts_delete_head(stk);
  return tmp;
}

void stk_display_contact(contact* ptr){
  lsts_display_contact(ptr);
}
