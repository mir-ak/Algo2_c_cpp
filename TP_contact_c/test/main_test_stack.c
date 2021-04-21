#include <stdio.h>
#include "stack.h"


int main (int argc, char* argv[]){

  stack* stk = stk_create_stack();
  contact* tmp1 = stk_create_node("Inspecteur Lestrad", "01 01 01 01 01");
  stk_push (stk,tmp1);

  contact* tmp2 = stk_create_node("Janine", "01 03 03 03 40");
  stk_push (stk,tmp2);
  
  contact* tmp3 = stk_create_node("Inspecteur GREGSON", "05 02 02 01 01");
  stk_push (stk,tmp3);

  contact* tmp = stk_pop(stk);
  stk_display_contact(tmp);

  tmp = stk_pop(stk);
  stk_display_contact(tmp);

  tmp = stk_pop(stk);
  stk_display_contact(tmp);


  tmp = stk_pop(stk);
  stk_display_contact(tmp);

}
