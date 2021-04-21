#include <stdio.h>
#include "list.h"
#include "file.h"

file* file_create_file(){
  file* fifo = (file*) lst_create_list();
  return fifo;  
}

contact* file_create_node(int id, char* name, char *phone_number){
  return lst_create_node(id, name, phone_number);
}

void file_put (file* fifo, contact* pnew){
  lst_insert_head(fifo,pnew);
}

contact* file_get(file* fifo){
  if(fifo->tail==NULL){
    return NULL;
  }
  
  contact* tmp = file_create_node(fifo->tail->id,fifo->tail->name,fifo->tail->phone_number);
  lst_delete_tail(fifo);
  return tmp;
}

void file_display_contact(contact* ptr){
  lst_display_contact(ptr);
}
