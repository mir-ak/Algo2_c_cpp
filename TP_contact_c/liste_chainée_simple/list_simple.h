#include <stdio.h>
#include <stdlib.h>
struct contact
{
	int id ; 
	char phone_nombre[20];
	char phone_name[50];
	struct contact *next;
};
typedef struct contact contact ;
struct list
	{
		struct contact * head ;
		struct contact * tail ;
	};	
typedef struct list list ; 

list *lst_create_liste();
contact* list_create_node(int id, char* name,char* phone_nombre);
void list_insert_head(list *lst, contact *pnew);
void list_insert_tail(list * lst, contact *pnew);
void list_insert_after(list *lst,contact *pnew,contact *ptr);
contact* list_search_id(list *lst, int id_search);
void list_display_node(contact *node);
void list_display(list *lst);
void list_delete_head(list *lst);
void list_delete_tail(list *lst);
void list_delete_contact(list *lst, contact* ptr);
void list_erase(list *lst);
