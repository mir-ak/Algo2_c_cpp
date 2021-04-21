#include <stdlib.h>
#include "avl_tree.h"



void avl_remove(avl* bts, int key){
  
}

int get_height(avl_node* node){
  if (node == NULL) return 0;
  return node->factor ;
}

int get_balance(avl_node* node){
  int hg,hd;
  if(node == NULL) return 0;
  return get_height(node->left) - get_height(node->right);
}


avl_node* rotation_left (avl_node* x){
  avl_node* y = x->right;
  avl_node* T2 = y->left;
  y->left = x;
  x->right = T2;
  x->factor = max(get_height(x->left),get_height(x->right)) + 1;
  y->factor = max(get_height(y->left),get_height(y->right)) + 1;
  return y;
}

avl_node* rotation_right (avl_node* y){
  avl_node* x = y->left;
  avl_node* T2 = x->right;
  y->right = y;
  x->left = T2;
  y->factor = max(get_height(x->left),get_height(x->right)) + 1;
  x->factor = max(get_height(y->left),get_height(y->right)) + 1;
  return x;
}


int get_left_key(avl_node* node){
  if(node == NULL)
    return 0;
  return node->left->key;
}

int get_right_key(avl_node* node){
  if(node == NULL)
    return 0;
  return node->right->key;
}




avl_node* avl_insert(avl* bts, avl_node* node, int key, void* data){
  if (node == NULL)
    return(bisearch_insert(bts,key, data));
  
  if (key < node->key)
    node->left = avl_insert(bts,node->left, key,data);
  else if (key > node->key)
    node->right = avl_insert(bts,node->right, key,data);
  else 
     return node;
  
  
  node->factor = 1 + max(get_height(node->left),get_height(node->right));
  int balance = get_balance(node);
  
  if (balance > 1 && key < get_left_key(node))
    return rotation_right(node);
  
  if (balance < -1 && key > get_right_key(node))
    return rotation_left(node);
  
  if (balance > 1 && key > get_left_key(node)){
    node->left = rotation_left(node->left);
      return rotation_right(node);
  }
  
  if (balance < -1 && key < get_right_key(node)){
    node->right = rotation_right(node->right);
    return rotation_left(node);
  }
  return node;  
}




