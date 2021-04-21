#include <stdio.h>
#include "bfs.h"


void bfs(btree* bitre, bnode* top){
  bnode* pos = top;
  queue* fifo = queue_create_queue();
  queue_push(fifo,pos);

  while( queue_empty(fifo) == 0 ){
    pos = queue_peek(fifo);
    queue_pull(fifo);
    printf(" %d - ", pos->key);
       
    if(pos->left != NULL){
      queue_push(fifo,pos->left);
    }
    if(pos->right != NULL){
      queue_push(fifo,pos->right);
    }
    
  }
  printf("\n");
}

