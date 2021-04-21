#include "list.h"


#ifndef _QUEUE_H_
#define _QUEUE_H_

/**
 * une queue 
 */
typedef list queue;

/**
 * creation de la file 
 */
queue* queue_create_queue();


/**
 * création un noeud 
 */
lnode* queue_create_lnode(void*);

/**
 * insert un element dans la file
 */
void queue_push (queue*, void*);

/**
 * retir le diernier element 
 */
void queue_pull(queue*);

/**
 * renvoie le dernier element sans le supprimer  
 */
void* queue_peek(queue*);

/**
 * renvoie 0 si la file est vide
 */
int queue_empty(queue*);


#endif
