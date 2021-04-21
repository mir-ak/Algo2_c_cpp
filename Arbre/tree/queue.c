#include <stdio.h>
#include "list.h"
#include "queue.h"


queue* queue_create_queue(){
  queue* fifo = (queue*) lst_create_list();
  return fifo;  
}

lnode* queue_create_lnode(void* dat){
  return lst_create_lnode(dat);
}

void queue_push (queue* fifo, void* dat){
  lnode* pnew = queue_create_lnode(dat);
  lst_insert_head(fifo,pnew);
}

void queue_pull(queue* fifo){
  if(fifo->tail==NULL){
    return;
  }
  lst_delete_tail(fifo);
}


void* queue_peek(queue* fifo){
  if(fifo->tail==NULL){
    return NULL;
  }
  return (fifo->tail->data);
}


int queue_empty(queue* fifo){
  if (fifo->tail == NULL)
    return 1;
  return 0;
}
