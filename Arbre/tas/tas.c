
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct contact_ {
  int  id;
  char phone_number[20];
  char name[50];
}contact;


typedef struct heap_ {
  int size;
  contact **tree;
}heap;

int heap_compaire(contact* elem1, contact* elem2){
  if (elem1->id >  elem2->id) return 1;
  if (elem1->id == elem2->id) return 0;
  return -1;
}


void heap_display_contact(contact* ptr){
  if(ptr == NULL) {
    printf(" Vide \n");
    return;
  }
  printf(" --- \n");
  printf(" ID  : %d \n", ptr->id);
  printf(" Nom : %s \n", ptr->name);
  printf(" Num : %s \n", ptr->phone_number);
}


contact* heap_create_node(int id, char* name, char*phone_number){
  contact* ptmp = (contact*) malloc (sizeof(contact));
  ptmp->id = id;
  strcpy (ptmp->name, name);
  strcpy (ptmp->phone_number , phone_number);
  return ptmp;
}


int heap_left(int pos){
  return (int)pos * 2 + 1; 
}

int heap_right(int pos){
  return (int)pos * 2 + 2; 
}

int heap_parent(int pos){
  if (pos <= 0) return 0;
  return (int)(pos - 1) / 2; 
}


heap* heap_create (){
  heap* hp = (heap*) malloc (sizeof(heap));
  hp->size = 0;
  hp->tree = NULL;
  return hp;  
}


void  heap_insert(heap* hp, contact* ct){
  contact** treetmp = (contact**)
                      realloc (hp->tree, ((hp->size + 1)  * sizeof(contact*)));
  
  hp->tree = treetmp;
  hp->tree[hp->size] = ct;


  int ipos = hp->size;
  int ppos = heap_parent(ipos);
  while (ipos > 0 && heap_compaire(hp->tree[ppos],hp->tree[ipos]) < 0){
    contact* tmp = hp->tree[ppos];
    hp->tree[ppos] = hp->tree[ipos];
    hp->tree[ipos] = tmp ;
    ipos = ppos;
    ppos = heap_parent(ipos);
  }

  hp->size = hp->size + 1 ;  
}

contact* heap_extract(heap* hp,int id){
  if (hp->size == 0)
    return NULL;

  contact* ct = hp->tree[0];
  hp->size = hp->size - 1 ;
  //...
  
}

int main(int argc, char *argv[]){
  heap* hp = heap_create();
  contact* tmp1 = heap_create_node (1,"Sherlock Holms", "01 02 03 04 05");
  heap_insert(hp, tmp1);

  contact* tmp2 = heap_create_node (4,"Morland Holms", "05 04 03 02 01");
  heap_insert(hp, tmp2);

  contact* tmp3 = heap_create_node (3,"John Watson", "02 05 01 02 01");
  heap_insert(hp, tmp3);

  contact* tmp4 = heap_create_node (15,"Athena", "00 00 00 00 00");
  heap_insert(hp, tmp4);


  for(int i=0 ; i < hp->size ; i++){
    heap_display_contact(hp->tree[i]);
  }
  
  return 0;
}

