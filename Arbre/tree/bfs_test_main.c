#include <stdlib.h>
#include "bfs.h"


int main (){

  btree *btr = btree_create();
  
  bnode* n1 = btree_insert_left(btr,NULL,10,NULL);
  bnode* n2 = btree_insert_left(btr,n1,3,NULL);
  bnode* n3 = btree_insert_right(btr,n1,8,NULL);
  bnode* n4 = btree_insert_left(btr,n2,2,NULL);
  bnode* n5 = btree_insert_right(btr,n2,7,NULL);
  
  bfs(btr,n1);

  
}
