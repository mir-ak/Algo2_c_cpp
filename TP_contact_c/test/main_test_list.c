#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

int main(int argc, char *argv[]){

  list *lst = lst_create_list();

  contact *tmp1, *tmp2, *tmp3, *tmp4, *tmp5, *tmp6;
  
  tmp1 = lst_create_node(1, "John Doe", "01 03 04 01 01");
  lst_insert_after(lst, tmp1, NULL);

  tmp2 = lst_create_node(2, "Sherlock Holms", "01 02 03 04 05");
  lst_insert_after(lst, tmp2, tmp1);

  tmp3 = lst_create_node(3, "Detective Die", "01 02 03 04 05");
  lst_insert_after(lst, tmp3, tmp1);
    
  tmp4 = lst_create_node(4, "Dr Watson", "01 02 03 04 05");
  lst_insert_after(lst, tmp4, tmp2);

  tmp5 = lst_create_node(5, "Morland Holms", "01 02 03 04 05");
  lst_insert_head(lst, tmp5);

  tmp6 = lst_create_node(6, "Pr Moriarty", "01 02 03 04 05");
  lst_insert_tail(lst, tmp6);
  
  printf(" --\n\n"); 
  
  lst_display(lst);
  printf(" --\n\n"); 
  
  tmp1 = lst_search_id (lst,6);
  lst_display_contact(tmp1);
  printf(" --\n\n"); 
  lst_delete_contact(lst, tmp1);

  lst_display(lst);
  printf(" --\n\n"); 
  
}
