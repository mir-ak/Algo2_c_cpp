#include <stdio.h>
#include "file.h"



int main (int argc, char* argv[]){

  file* fifo = file_create_file();

  contact* tmp1 = file_create_node(1, "Inspecteur Lestrad", "01 01 01 01 01");


  file_put (fifo,tmp1);



  contact* tmp2 = file_create_node(2, "Janine", "01 03 03 03 40");
  file_put (fifo,tmp2);
  
  contact* tmp3 = file_create_node(3,"Inspecteur GREGSON", "05 02 02 01 01");
  file_put (fifo,tmp3);


  
  contact* tmp = file_get(fifo);

  file_display_contact(tmp);

  tmp = file_get(fifo);
  file_display_contact(tmp);

  tmp = file_get(fifo);
  file_display_contact(tmp);


  tmp = file_get(fifo);
  file_display_contact(tmp);

}
