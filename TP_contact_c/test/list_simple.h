#ifndef _LIST_SIMPLE_H_
#define _LIST_SIMPLE_H_

/**
 * Élément contact
 */
typedef struct contact_ {
  char phone_number[20];
  char name[50];
  struct contact_ *next;
}contact;



/** 
 * Une liste simplement chaînée
 */
typedef struct list_simple_{
  contact* head;
  contact* tail;
}list_simple;


/**
 *
 */
list_simple* lsts_create_list();


/**
 *
 */
contact* lsts_create_node(char* name, char*phone_number);

/**
 *
 */

void lsts_insert_head(list_simple* lst, contact *pnew);

/**
 *
 */
void lsts_insert_tail(list_simple* lst, contact *pnew);

/**
 *
 */
void lsts_insert_after(list_simple *lst,contact *pnew, contact *ptr);

/**
 *
 */
void lsts_display_contact(contact* ptr);

/**
 *
 */
void lsts_display(list_simple *lst);


/**
 *
 */
void lsts_delete_head(list_simple *lst);

/**
 *
 */
void lsts_delete_tail(list_simple *lst);

/**
 *
 */
void lsts_delete_contact(list_simple *lst, contact* ptr);

/**
 *
 */
contact* lsts_search (list_simple *lst, char* name);

/**
 *
 */
void lsts_erase(list_simple *lst);

#endif
