

#ifndef _BIN_TREE_H_
#define _BIN_TREE_H_
typedef struct bnode_ {
  struct bnode_ *left   ;
  struct bnode_ *right  ;
  signed   int   factor ;
  unsigned int   key    ;	  
  void          *data   ;
}bnode;


typedef struct bin_tree_ {
  int size;
  bnode *root; 
}btree;

/**
 * createtion de l'arbre
 */
btree* btree_create();

/**
 * Suppression de l'arbre 
 */
void btree_distroy(btree*);

/**
 * Création d'un bnode 
 * p1 : clé 
 * p2 : les les données
 */
bnode* create_bnode(int, void*);

/**
 * insert à gauche de bnode
 */
bnode* btree_insert_left(btree*, bnode*, int, void*);

/**
 * insert à droite de bnode
 */
bnode* btree_insert_right(btree*, bnode*, int, void*);

/**
 * supprimer à gauche de bnode
 */
void btree_remove_left(btree*, bnode*);

/**
 * Supprimer à droite de bnode
 */
void btree_remove_right(btree*, bnode*);



#endif
