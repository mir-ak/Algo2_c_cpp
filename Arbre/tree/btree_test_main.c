#include <stdlib.h>
#include "bin_tree.h"


int main(int argc, char* argv[]){
  btree *btr = btree_create();

  node* n1 = btree_insert_left(btr,NULL,10,NULL);
  node* n2 = btree_insert_left(btr,n1,3,NULL);
  node* n3 = btree_insert_right(btr,n1,8,NULL);
  node* n4 = btree_insert_left(btr,n2,2,NULL);
  node* n5 = btree_insert_right(btr,n2,7,NULL);


  return 0;
}

