#include <stdio.h>
#include <stdlib.h>
#include "listedbc.h"
struct file{
	
	dbc *_DATA;
};
typedef struct file file ;

file *creat(){
	file *cree = malloc(sizeof *cree);
	cree->_DATA = lst_create_liste();
	return cree ; 
}

void push(file *list,contact *pnew){
	if(!list){
		return ; 
	}
	lst_insert_tail(list->_DATA , pnew);
}
contact *pop(file *list){
	contact *tmp = list->_DATA->tail ; 
	list->_DATA->tail = tmp->prev ;
	list->_DATA->tail->next = NULL ;
	return tmp ;  
}
void pile_delet(file *list){
	if(!list){
		return;
	}
	lst_erase(list->_DATA);
	free(list);
}
int pile_empty(file *list){
	return (list->_DATA == NULL); 
}
void diplay_pile(file *list){
	lst_display(list->_DATA);
}
int main(int argc, char const *argv[])
{
	file *lst = creat() ; 
	contact *p ;
	push(lst,lst_create_node(1, "Mirak Karim", "01 02 03 04 05"));
	push(lst, lst_create_node(2, "Monkey D.luffy", "04 00 99 71 24"));
	//pop(lst);
	push(lst, lst_create_node(3, "Roronoa Zoro", "02 05 24 75 32"));
	push(lst, lst_create_node(4, "Vinsmoke Sanji ", "04 97 30 32 06"));
	diplay_pile(lst);

	return 0;
}
