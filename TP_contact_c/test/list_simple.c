#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_simple.h"



list_simple* lsts_create_list(){
  list_simple* lst = (list_simple*) malloc (sizeof(list_simple));
  lst->head = NULL;
  lst->tail = NULL;
  return lst;
}


contact* lsts_create_node(char* name, char*phone_number){
  contact* ptmp = (contact*) malloc (sizeof(contact));
  strcpy (ptmp->name, name);
  strcpy (ptmp->phone_number , phone_number);
  ptmp->next = NULL;
  return ptmp;
}

void lsts_insert_head(list_simple* lst, contact *pnew){
  if(lst->head == NULL){
    lst->head=pnew;
    lst->tail=pnew;
    return;
  }
  pnew->next = lst->head;
  lst->head  = pnew;
}

void lsts_insert_tail(list_simple* lst, contact *pnew){
  if(lst->head == NULL){
    lst->head=pnew;
    lst->tail=pnew;
    return;
  }
  pnew->next = NULL;
  lst->tail->next = pnew;
  lst->tail = pnew;
}

void lsts_insert_after(list_simple *lst,contact *pnew, contact *ptr){
  if(lst->head == NULL){
    lst->head=pnew;
    lst->tail=pnew;
  }
  else if (ptr == NULL){
    return;
  }
  else if (lst->tail == ptr) {
    lsts_insert_tail(lst,pnew);
  }
  else{
    pnew->next = ptr->next;
    ptr->next = pnew;
  }
}

void lsts_display_contact(contact* ptr){
  if(ptr == NULL) {
    printf(" Vide \n");
    return;
  }
  printf(" --- \n");
  printf(" Nom : %s \n", ptr->name);
  printf(" Num : %s \n", ptr->phone_number);
}

void lsts_display(list_simple *lst){
  contact *pBeg = lst->head;
  if (pBeg == NULL) return ;
  do{
    lsts_display_contact(pBeg);
    pBeg=pBeg->next;
  }while (pBeg != NULL);
}

void lsts_delete_head(list_simple *lst){
  if(lst->head == NULL){
    return ;
  }

  if(lst->head->next == NULL){
    free (lst->head);
    lst->head = NULL;
    lst->tail = NULL;
    return; 
  }
  
  contact* tmp = lst->head;
  lst->head = lst->head->next;
  free(tmp);
}

void lsts_delete_tail(list_simple *lst){
 
  if(lst->tail == NULL){
    return ;
  }
  if(lst->head->next == NULL){

    free(lst->head);
    lst->head = NULL;
    lst->tail = NULL;
    return;
  }

  contact* tmp = lst->head;
  while (tmp->next->next != NULL){
    tmp = tmp->next;
  }
  
  lst->tail = tmp;
  free(tmp->next);
  tmp->next=NULL;
}


void lsts_delete_contact(list_simple *lst, contact* ptr){
  if(ptr==NULL)
    return;
  
  contact* tmp = lst->head;

  while (tmp->next != ptr){
    tmp = tmp->next;
  }

  if(tmp == lst->tail){
    lsts_delete_tail(lst);
    return;
  }

  tmp->next = ptr->next;
  free(ptr);
}

contact* lsts_search (list_simple *lst, char* name){
  contact *pBeg = lst->head;
  while (pBeg != NULL){
    if (strcmp(pBeg->name, name)==0){
      return pBeg;
    }
    pBeg=pBeg->next;
  }
  return NULL;
}


void lsts_erase(list_simple *lst){
  if(lst->head == NULL)
    return;
  while (lst->head != lst->tail){
    contact* tmp =lst->head; 
    lst->head = lst->head->next;
    free(tmp);
  }
  free(lst->head);
  lst->head = NULL;
  lst->tail = NULL;
}

