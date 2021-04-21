#include "bin_tree.h"

#ifndef _BIN_SEARCH_TREE_H_
#define _BIN_SEARCH_TREE_H_


typedef btree bisearch;
typedef bnode bisearch_node;

#define bisearch_create() (btree_create());

#define bisearch_distroy(btree) (btree_distroy(btree));

bisearch_node* bisearch_search(bisearch*, int);

void bisearch_remove(bisearch*, int);

bisearch_node* bisearch_insert(bisearch*, int, void*);

#endif
