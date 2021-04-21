
#ifndef LIST_H
#define LIST_H


/**
 * Élément lnode
 */
typedef struct lnode_ {
  void * data; 
  struct lnode_ *prev;
  struct lnode_ *next;
}lnode;


/**
 * Une liste 
 */
typedef struct list_{
  lnode* head;
  lnode* tail;
}list;


/**
 * création d'un noeud 
 */
lnode* lst_create_lnode(void* dat) ;

/**
 * crée la liste et retourne un pointeur sur cette dernière
 */
list* lst_create_list();



/**
 * Insère pnew au début de la liste lst
 */
void lst_insert_head(list* lst, lnode *pnew);


/**
 * Insère pnew à la fin de la liste lst
 */
void lst_insert_tail(list* lst, lnode *pnew);

/**
 * Insère l'élément pnew juste après ptr dans la liste lst
 */
void lst_insert_after(list *lst,lnode *pnew, lnode *ptr);

/**
 * Supprime le premier élément de la liste 
 */
void lst_delete_head(list *lst);


/**
 * Supprime le dernier élément de la liste 
 */
void lst_delete_tail(list *lst);


/**
 * Supprime le lnode pointé par ptr
 */
void lst_delete_lnode(list *lst, lnode* ptr);


/**
 * Supprime tous les éléments de la liste lst
 */
void lst_erase(list *lst);

#endif

