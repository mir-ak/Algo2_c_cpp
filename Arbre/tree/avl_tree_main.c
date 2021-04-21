
#include <stdio.h>
#include <stdlib.h>
#include "avl_tree.h"
#include "bfs.h"
#include "dfs.h"


int main (int argc, char* argv[]){
  avl* bs = avl_create();
  avl_insert(bs,NULL,  1 , NULL); 
  avl_insert(bs,NULL,  2 , NULL); 
  avl_insert(bs,NULL,  3 , NULL); 
  avl_insert(bs,NULL,  4 , NULL); 
  avl_insert(bs,NULL,  5 , NULL); 
  avl_insert(bs,NULL,  6 , NULL); 

  printf(" --  BFS -- \n");
  bfs(bs,bs->root);

  printf("\n");
  return 0;
}
