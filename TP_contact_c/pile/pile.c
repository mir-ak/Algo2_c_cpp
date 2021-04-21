#include <stdio.h>
#include <stdlib.h>
#include "listedbc.h"
struct pile{
	
	dbc *_DATA;
};
typedef struct pile pile ;

pile *creat(){
	pile *cree = malloc(sizeof *cree);
	cree->_DATA = lst_create_liste();
	return cree ; 
}

void push(pile *list,contact *pnew){
	if(!list){
		return ; 
	}
	lst_insert_head(list->_DATA , pnew);
}
contact *pop(pile *list){
	contact *tmp = list->_DATA->head ; 
	list->_DATA->head = tmp->next ;
	list->_DATA->head->prev = NULL ;
	return tmp ;  
}
void pile_delet(pile *list){
	if(!list){
		return;
	}
	lst_erase(list->_DATA);
	free(list);
}
int pile_empty(pile *list){
	return (list->_DATA == NULL); 
}
void diplay_pile(pile *list){
	lst_display(list->_DATA);
}
int main(int argc, char const *argv[])
{
	pile *lst = creat() ; 
	contact *p ;
	push(lst,lst_create_node(1, "Mirak Karim", "01 02 03 04 05"));
	push(lst, lst_create_node(2, "Monkey D.luffy", "04 00 99 71 24"));
	push(lst, lst_create_node(3, "Roronoa Zoro", "02 05 24 75 32"));
	free(pop(lst));
	push(lst, lst_create_node(4, "Vinsmoke Sanji ", "04 97 30 32 06"));
	diplay_pile(lst);

	return 0;
}