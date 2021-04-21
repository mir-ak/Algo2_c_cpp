#include <stdlib.h>

#include "bin_tree.h"



btree* btree_create (){
  btree* bt = (btree*) malloc (sizeof(btree));
  bt->root = NULL;
  bt->size = 0;
  return bt;
}

/**
 * Suppression de l'arbre 
 */
void btree_distroy(btree* btr){

}

bnode* create_bnode(int key, void* data){
  bnode* nod  = (bnode*) malloc (sizeof(bnode));
  nod->left   = NULL;
  nod->right  = NULL;
  nod->key    = key ;
  nod->data   = data;
  nod->factor = 0;
  return nod;
}

/**
 * insert à gauche de bnode
 */
bnode* btree_insert_left(btree* btr, bnode* nod, int key, void* dat){
  bnode **pos;
  if(nod == NULL){
    if(btr->size > 0 ) { return NULL;} // insertion à la racine si arbre vide
    pos=&btr->root;
  }
  else{
    if(nod->left != NULL) { return NULL;} // Vérifier si vide 
    pos=&nod->left;
  }
  *pos = create_bnode(key,dat);
  btr->size++;
  return *pos;
}

/**
 * insert à gauche de droite
 */
bnode* btree_insert_right(btree* btr, bnode* nod, int key,void* dat){
  bnode **pos;
  if(nod == NULL){
    if(btr->size > 0 ) { return NULL;} // insertion à la racine si arbre vide
    pos=&btr->root;
  }
  else{
    if(nod->right != NULL) { return NULL;} // Vérifier si vide 
    pos=&nod->right;
  }
  *pos = create_bnode(key,dat);
  btr->size++;
  return *pos;
}

void btree_remove_left(btree* btr, bnode* nod){
  bnode **pos;
  if (nod == NULL){
    return;
  }
  pos = &nod->left;
  if(*pos != NULL){
    btree_remove_left (btr,*pos);
    btree_remove_right(btr,*pos);
  }
  free(*pos);
  btr->size--;
  return;
}

void btree_remove_right(btree* btr, bnode* nod){
  bnode **pos;
  if (nod == NULL){
    return;
  }
  pos = &nod->right;
  if(*pos != NULL){
    btree_remove_left (btr,*pos);
    btree_remove_right(btr,*pos);
  }
  free(*pos);
  btr->size--;
  return;
}


