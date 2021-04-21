#include <stdio.h>
#include <stdlib.h>
#define __PHONE_NUMBER_LEN__ 20
#define __PHONE_NAME_LEN__ 50


struct contact
{
	int id ; 
	char phone_nombre[__PHONE_NUMBER_LEN__];
	char phone_name[__PHONE_NAME_LEN__];
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

struct hashtable
{
    int size;
    dbc **tab;
};
typedef struct hashtable HashTable;

dbc *lst_create_liste();
contact *lst_create_node(int id,const char* name,const char* phone_nombre);
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


int hashtable_get_hash(HashTable *htab, int key);
dbc **hashtable_create_tab(int size);
HashTable *hashtable_create(int size);
void hashtable_insert_elem(HashTable *htab, int id, const char *name, const char *num);
void hashtable_print(HashTable *htab);
void hashtable_delete_tab(dbc **lst, int size);
void hashtable_delete(HashTable *htab);
contact *hashtable_search_id(HashTable *htab, int id_search);
