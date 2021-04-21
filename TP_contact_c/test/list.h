
#ifndef LIST_H
#define LIST_H


/**
 * Élément contact
 */
typedef struct contact_ {
  int  id;
  char phone_number[20];
  char name[50];
  struct contact_ *prev;
  struct contact_ *next;
}contact;


/**
 * Une liste 
 */
typedef struct list_{
  contact* head;
  contact* tail;
}list;


/**
 * crée la liste et retourne un pointeur sur cette dernière
 */
list* lst_create_list();


/**
 * Crée un élément contact et retourne un poiteur sur l'élément créé 
 */
contact* lst_create_node(int id, char* name, char*phone_number) ;


/**
 * Insère pnew au début de la liste lst
 */
void lst_insert_head(list* lst, contact *pnew);


/**
 * Insère pnew à la fin de la liste lst
 */
void lst_insert_tail(list* lst, contact *pnew);

/**
 * Insère l'élément pnew juste après ptr dans la liste lst
 */
void lst_insert_after(list *lst,contact *pnew, contact *ptr);

/**
 * Affiche le contacte pointé par ptr
 */
void lst_display_contact(contact* ptr);


/**
 * Affiche tous les éléments de la liste 
 */
void lst_display(list *lst);


/**
 * Supprime le premier élément de la liste 
 */
void lst_delete_head(list *lst);


/**
 * Supprime le dernier élément de la liste 
 */
void lst_delete_tail(list *lst);


/**
 * Supprime le contact pointé par ptr
 */
void lst_delete_contact(list *lst, contact* ptr);


/**
 * Recherche lans la liste l'élément dans id = id_search
 * et retourne un pointeur sur l'élément trouvé 
 * NULL sinon
 */
contact* lst_search_id(list *lst, int id_search);


/**
 * Supprime tous les éléments de la liste lst
 */
void lst_erase(list *lst);

#endif

