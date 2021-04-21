#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_simple.h"

list *lst_create_liste(){
    list *tmp = (list *)malloc(sizeof * tmp);
    tmp->head = NULL;
    tmp->tail = NULL;
    return tmp;
}

contact* list_create_node(int id, char* name,char* phone_nombre){
	contact *node = malloc(sizeof *node);
	node->id = id ; 
	strcpy(node->phone_name,name);
	strcpy(node->phone_nombre,phone_nombre);
	node->next = NULL ; 
	return node ; 
}

void list_insert_head(list *lst, contact *pnew)
{
    if (lst->head && lst->tail)
    {
        
		pnew->next = lst->head ;
		lst->head = pnew ;
   }
    else
    {
        lst->head = pnew;
        lst->tail = pnew;
    }
}
void list_insert_tail(list * lst, contact *pnew){
	if (lst->tail && lst->tail){
		lst->tail->next = pnew; 
		//pnew->next = lst->tail ;
		lst->tail = pnew  ;
	}
	else{
	lst->tail = pnew ; 
	lst->head = pnew ;
	}
}
void list_insert_after(list *lst,contact *pnew,contact *ptr){
	if (!lst || !pnew || !ptr)
        return;
	contact *tmp = ptr->next ;		
	if(lst->tail == ptr)
		lst->tail = pnew; 
	ptr->next = pnew ; 	
	pnew->next = tmp ;
}
contact* list_search_id(list *lst, int id_search){
	contact *tmp = lst->head ; 
	while(tmp){
		if(tmp->id == id_search){
			return tmp  ;
		}
		tmp = tmp->next;
	}
	return NULL ; 
}
void list_display_node(contact *node)
{
    if (!node)
        return;
    printf("--\nID : %d\n", node->id);
    printf("Nom : %s\n", node->phone_name);
    printf("Num : %s\n", node->phone_nombre);
}
void list_display(list *lst)
{
    if (!lst)
        return;
    contact *ptr = lst->head;
    while (ptr)
    {
        list_display_node(ptr);
        ptr = ptr->next;
    }
}
void list_delete_head(list *lst){
	if(!lst){
		printf("liste et deja vide !!!\n");
	}
	/*if (lst->head == lst->tail)
	{
		free(lst);
	}*/
	contact *tmp = lst->head; 
	lst->head = lst->head->next;
	free(tmp);
}
void list_delete_tail(list *lst){
	if(!lst){
		printf("liste et deja vide !!!\n");
	}
	contact *tmp = lst->tail->next ; 
	free(lst->tail);
	lst->tail = tmp;
}
void list_delete_contact(list *lst, contact* ptr){
	if (!lst || !ptr){
        return;
	}
	else{
	contact *prev = lst->head;
	contact *act = ptr ;
	while(prev && prev->next != ptr){
		//if(prev->next == ptr && act->next == ptr){
		prev = prev->next ;
		
	} 
	if(lst->tail == ptr ){
		lst->tail = prev ; 
	}

	if (lst->head == ptr ){
		lst->head = ptr->next;
	}

	if (prev){
	prev->next = act->next ;
	}
	free(ptr);
}
	
	
}
void list_erase(list *lst){
	while(lst->head){
		list_delete_contact(lst,lst->head);

	}
	lst = NULL ;
}/*
int main(int argc, char const *argv[])
{
	contact *pos;
    list *lst = lst_create_liste();
	
    printf("\n");
	list_insert_head(lst, list_create_node(1, "Jane Doe", "01 02 03 04 05"));
	//list_delete_contact(lst,pos)
	list_insert_tail(lst, list_create_node(3, "m", "01 02 03 04 05"));
	pos = list_search_id(lst,3);
	list_insert_after(lst, list_create_node(2, "mir", "01 02 03 04 05"),pos);
	list_insert_tail(lst, list_create_node(4, "mor", "01 02 03 04 05"));
	//pos = list_search_id(lst,2);
	
	list_display(lst);
	list_delete_head(lst);
	printf("---------\n");
	list_display(lst);
	free(lst);
	return 0;
}*/