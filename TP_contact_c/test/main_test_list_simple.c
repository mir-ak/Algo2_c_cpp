#include <stdio.h>
#include "list_simple.h"

 
int main(int argc, char* argv[]){

  list_simple *lst = lsts_create_list();
  contact *tmp1 = lsts_create_node("Irene Adler", "01 02 03 04 05");
  lsts_insert_head(lst, tmp1);

  contact *tmp2 = lsts_create_node("Mycroft Holmes", "05 01 02 03 04");
  lsts_insert_head(lst, tmp2);

  contact *tmp3 = lsts_create_node("Mme Hudson", "05 01 02 03 04");
  lsts_insert_after(lst, tmp3, tmp2);

  lsts_display(lst);

  printf("Résultat Recherche : \n");
  
  contact* tmp = lsts_search(lst, "Irene Adler");  
  lsts_display_contact(tmp);
  
  lsts_erase(lst);
  
  return 0;
}
