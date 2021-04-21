
#include <stdio.h>
#include <stdlib.h>
#include "bin_search_tree.h"
#include "bfs.h"
#include "dfs.h"


int main (int argc, char* argv[]){
  bisearch* bs = bisearch_create();
  bisearch_insert(bs, 5 , NULL);
  bisearch_insert(bs, 4 , NULL);
  bisearch_insert(bs, 8 , NULL);
  bisearch_insert(bs, 14, NULL);
  bisearch_insert(bs, 3 , NULL);
  bisearch_insert(bs, 6 , NULL);

  printf(" --  BFS -- \n");
  bfs(bs,bs->root);

  printf(" --  DFS -- \n");
  dfs(bs,bs->root);

  printf("\n");
  return 0;
}
