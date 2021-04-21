#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include"listedbc.h"



dbc * lst_create_liste(){
	dbc * cree = malloc(sizeof * cree);
	cree->head = NULL;
	cree->tail = NULL ;
	return cree ;
}

contact *lst_create_node(int id, const char *name, const char *phone_nombre){
	contact *node = malloc(sizeof *node);
	
		node->id = id ; 
		node->next = NULL ; 
		node->prev = NULL ;
		strcpy(node->phone_name,name);
		strcpy(node->phone_nombre,phone_nombre);
	return node ; 
}
void lst_insert_head(dbc * lst, contact *pnew){
	if (lst->head && lst->tail){
		lst->head->prev = pnew; 
		pnew->next = lst->head ;
		lst->head = pnew ;
	}
	else{
	lst->head = pnew ;
	lst->tail = pnew ; 
	}
}
void lst_insert_tail(dbc * lst, contact *pnew){
	if (lst->head && lst->tail){
		lst->tail->next = pnew; 
		pnew->prev = lst->tail ;
		lst->tail = pnew  ;
	}
	else{
	lst->tail = pnew ; 
	lst->head = pnew ;
	}
}
void lst_insert_after(dbc *lst,contact *pnew,contact *ptr){
	if (!lst || !pnew || !ptr)
        return;
	contact *tmp = ptr->next ;		
	if(lst->tail == ptr)
		lst->tail = pnew; 
	ptr->next = pnew ;
	pnew->prev = ptr ; 	
	pnew->next = tmp ;
}

void lst_display_contacte(contact* ptr){
	if(!ptr){
		return ;

	}
		printf("--\n");
		printf(" id : %d \n Nom: %s\n Numero: %s\n",ptr->id ,ptr->phone_name,ptr->phone_nombre) ;

	printf("\n");
}
void lst_display(dbc *lst){
	if(!lst->head){
		printf("elle est bien vide\n");
	}
	contact *elm = lst->head ;
 
	while(elm){
		lst_display_contacte(elm) ;
		elm = elm->next ;
	}
}
void lst_delete_head(dbc *lst){
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
void lst_delete_tail(dbc *lst){
	if(!lst){
		printf("liste et deja vide !!!\n");
	}
	/*if (lst->head == lst->tail)
	{
		free(lst);
	}*/
	contact *tmp = lst->tail->prev ; 
	free(lst->tail);
	lst->tail = tmp;
	lst->tail->next = NULL ;
}
void lst_delete_contact(dbc *lst, contact* ptr){
	if (!lst || !ptr)
        return;
	contact *tmpN = ptr->next ; 
	contact *tmpP = ptr->prev ;

	free(ptr); 
	if (tmpP)
		tmpP->next = tmpN ; 
	if (tmpN)
		tmpN->prev = tmpP;
}
void lst_erase(dbc *lst){
	while(lst->head){
		lst_delete_head(lst);

	}
	lst = NULL ;
}
contact* lst_search_id(dbc *lst, int id_search){
	contact *tmp = lst->head ; 
	while(tmp){
		if(tmp->id == id_search){
			return tmp  ;
		}
		tmp = tmp->next;
	}
	return NULL ; 
}