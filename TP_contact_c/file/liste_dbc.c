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

contact* lst_create_node(int id, char* name,char* phone_nombre){
	contact *node = malloc(sizeof *node);
	
		node->id = id ; 
		strcpy(node->phone_name,name);
		strcpy(node->phone_nombre,phone_nombre);
		node->next = NULL ; 
		node->prev = NULL ;
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
	if (lst->tail && lst->tail){
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
/*
int main(int argc, char const *argv[])
{
	contact *pos;
    dbc *lst = lst_create_liste();

 
    lst_insert_head(lst, lst_create_node(2, "Mirak Karim", "01 02 03 04 05"));
    lst_insert_head(lst, lst_create_node(1, "Monkey D.luffy", "04 00 99 71 24"));
    lst_insert_tail(lst, lst_create_node(4, "Roronoa Zoro", "02 05 24 75 32"));
    lst_insert_tail(lst, lst_create_node(3, "Vinsmoke Sanji ", "04 97 30 32 06"));
    pos = lst_search_id(lst, 4);
    lst_insert_after(lst, lst_create_node(3, "Nico Robin", "01 22 22 69 40"), pos);
    pos = lst_search_id(lst, 3);
    lst_insert_after(lst, lst_create_node(4, "Tony Chopper","07 25 16 91 55"), pos);
    lst_insert_tail(lst, lst_create_node(7, "Nami", "01 12 32 69 41"));
    pos = lst_search_id(lst, 7);
    lst_insert_after(lst, lst_create_node(8, "Brook", "01 22 22 69 48"), pos); 
    lst_insert_tail(lst, lst_create_node(9, "Franky", "07 97 30 32 16"));
    lst_insert_tail(lst, lst_create_node(10, "Usopp", "06 97 45 32 16"));
    lst_display(lst);

    /*lst_delete_head(lst);
    lst_delete_tail(lst);
    lst_delete_contact(lst, pos);
    printf("\n");
    lst_display(lst);
   	/*lst_erase(lst);
   
   	lst_display(lst);
   
    return 0;
	
}*/
