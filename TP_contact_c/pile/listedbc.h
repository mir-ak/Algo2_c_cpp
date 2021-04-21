#include <stdio.h>
#include <stdlib.h>

struct contact
{
	int id ; 
	char phone_nombre[20];
	char phone_name[50];
	struct contact *next;
	struct contact *prev;
};
typedef struct contact contact ; 

struct dbc
	{
		struct contact * head ;
		struct contact * tail ;
	};	
typedef struct dbc dbc ; 
dbc *lst_create_liste();
contact *lst_create_node(int id, char* name,char* phone_nombre);
void lst_insert_head(dbc * lst, contact *pnew);
void lst_insert_tail(dbc * lst, contact *pnew);
void lst_insert_after(dbc *lst,contact *pnew,contact *ptr);
void lst_display_contacte(contact* ptr);
void lst_delete_head(dbc *lst);
void lst_delete_tail(dbc *lst);
void lst_delete_contact(dbc *lst, contact* ptr);
void lst_display(dbc *lst);
void lst_erase(dbc *lst);
contact* lst_search_id(dbc *lst, int id_search);
