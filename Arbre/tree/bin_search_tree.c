#include <stdlib.h>

#include "bin_search_tree.h"



bisearch_node* bisearch_search(bisearch* bts, int key){
  return NULL;
}

void bisearch_remove(bisearch* bts, int key){
  
}

bisearch_node* bisearch_insert(bisearch* bts, int key, void* data){
  bisearch_node* pos = bts->root;
  if(pos == NULL)
    return btree_insert_left(bts,NULL,key,data);

  while(pos != NULL){
    if (key == pos->key)
      return NULL;
    else if(key < pos->key){
      if(pos->left == NULL)
	return btree_insert_left(bts,pos,key,data);
      else
	pos=pos->left;      
    }
    else if(key > pos->key){
      if(pos->right == NULL)
	return btree_insert_right(bts,pos,key,data);
      else
	pos=pos->right;      
    }
  }
  return NULL;
}

