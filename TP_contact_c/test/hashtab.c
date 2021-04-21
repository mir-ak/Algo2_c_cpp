#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "hashtab.h"




int hashtab_get_hash (hashtab* htab, int id){
  return id % htab->size;
}


list** hashtab_create_tab(int size){
  int i;
  list** lst = (list**) malloc (size * sizeof(list*));
  for (i=0;i<size;i++){
    lst[i] = lst_create_list();
  }
  return lst;
}


hashtab* hashtab_creat(int size){
  hashtab* htab = (hashtab*) malloc (sizeof(hashtab));
  htab->size = size;
  htab->tab = hashtab_create_tab(size);
  return htab;
}

void hashtab_print(hashtab* htb){
  int i;
  for (i=0 ; i < htb->size ; i++){
    lst_display(htb->tab[i]);
  }
}


void hashtab_insert_elem(hashtab* htab, int id, char* name, char* num){
  int key = hashtab_get_hash(htab,id);
  contact *tmp = lst_create_node(id, name, num);
  lst_insert_tail(htab->tab[key],tmp);
}


