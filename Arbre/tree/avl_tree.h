#include "bin_search_tree.h"

#ifndef _AVL_TREE_H_
#define _AVL_TREE_H_

#define max(a,b) (a>=b?a:b)

typedef bisearch avl;
typedef bisearch_node avl_node;

#define avl_create() (btree_create());

#define avl_distroy(btree) (bisearch_distroy(btree));

#define avl_search(btree, key) (bisearch_search(btree,key));

void avl_remove(avl*, int);

avl_node* avl_insert(avl*,avl_node*, int, void*);

avl_node* rotation_left (avl_node*);

avl_node* rotation_right (avl_node*);

int get_balance(avl_node*);

int get_height(avl_node*);

#endif
