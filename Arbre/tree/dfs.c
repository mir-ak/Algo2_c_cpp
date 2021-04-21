#include <stdio.h>
#include "dfs.h"


void dfs(btree* bitre, bnode* top){
  if (top == NULL)
    return;

  printf(" %d - ", top->key);
  dfs(bitre,top->left);
  dfs(bitre,top->right);
}

