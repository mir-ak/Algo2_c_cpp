#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

list* lst_create_list(){
  list* lst = (list*) malloc (sizeof(list));
  lst->head = NULL;
  lst->tail = NULL;
  return lst;
}


contact* lst_create_node(int id, char* name, char*phone_number){
  contact* ptmp = (contact*) malloc (sizeof(contact));
  ptmp->id = id;
  strcpy (ptmp->name, name);
  strcpy (ptmp->phone_number , phone_number);
  ptmp->next = NULL;
  ptmp->prev = NULL;
  return ptmp;
}

void lst_insert_head(list* lst, contact *pnew){
  if(lst->head == NULL){
    lst->head=pnew;
    lst->tail=pnew;
    return;
  }
  pnew->next = lst->head;
  pnew->prev = NULL;
  lst->head  = pnew;
  pnew->next->prev = pnew;
}

void lst_insert_tail(list* lst, contact *pnew){
  if(lst->head == NULL){
    lst->head=pnew;
    lst->tail=pnew;
    return;
  }
  pnew->next = NULL;
  pnew->prev = lst->tail;
  lst->tail = pnew;
  pnew->prev->next = pnew;  
}

void lst_insert_after(list *lst,contact *pnew, contact *ptr){
  if(lst->head == NULL){
    lst->head=pnew;
    lst->tail=pnew;
  }
  else if (ptr == NULL){
    return;
  }
  else if (lst->tail == ptr) {
    lst_insert_tail(lst,pnew);
  }
  else{
    pnew->next = ptr->next;
    pnew->prev = ptr;
    pnew->next->prev = pnew;
    pnew->prev->next = pnew;  
  }
}

void lst_display_contact(contact* ptr){
  if(ptr == NULL) {
    printf(" Vide \n");
    return;
  }
  printf(" --- \n");
  printf(" ID  : %d \n", ptr->id);
  printf(" Nom : %s \n", ptr->name);
  printf(" Num : %s \n", ptr->phone_number);
}

void lst_display(list *lst){
  contact *pBeg = lst->head;
  if (pBeg == NULL) return ;
  do{
    lst_display_contact(pBeg);
    pBeg=pBeg->next;
  }while (pBeg != NULL);
}

void lst_delete_head(list *lst){
   if(lst->head->next == NULL){
    free (lst->head);
    lst->head = NULL;
    lst->tail = NULL;
    return; 
  }
  lst->head = lst->head->next;
  free(lst->head->prev);
  lst->head->prev = NULL;  
}

void lst_delete_tail(list *lst){
   if(lst->tail->prev == NULL){
    free (lst->tail);
    lst->head = NULL;
    lst->tail = NULL;
    return; 
  }
  lst->tail = lst->tail->prev;
  free(lst->tail->next);
  lst->tail->next = NULL;  
}


void lst_delete_contact(list *lst, contact* ptr){
  if(ptr==NULL)
    return;
  if(ptr == lst->head){
    lst_delete_head(lst);
    return;
  }
  if(ptr == lst->tail){
    lst_delete_tail(lst);
    return;
  }
  ptr->next->prev = ptr->prev;
  ptr->prev->next = ptr->next;
  free (ptr);
}

contact* lst_search_id(list *lst, int id_search){
  contact *pBeg = lst->head;
  while (pBeg != NULL){
    if (pBeg->id == id_search){
      return pBeg;
    }
    pBeg=pBeg->next;
  }
  return NULL;
}


void lst_erase(list *lst){
  if(lst->head == NULL)
    return;
  while (lst->head != lst->tail){
    lst->head = lst->head->next;
    free(lst->head->prev);
  }
  free(lst->head);
  lst->head = NULL;
  lst->tail = NULL;
}


