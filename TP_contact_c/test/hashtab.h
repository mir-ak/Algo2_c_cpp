#include "list.h"
#ifndef HASHTAB_H
#define HASHTAB_H


typedef struct hashtab_{
  int size;
  list** tab;
}hashtab;



/**
 * Calcul d'un hash
 */
int hashtab_get_hash (hashtab* htab, int id);

/**
 * Création tableau de liste chaênée	
 */
list** hashtab_create_tab(int size);

/**
 * Création de la table de hashage
 */
hashtab* hashtab_creat(int size);

/**
 * Affichage de la liste
 */
void hashtab_print(hashtab* htb);

/**
 * Insérer un élément dans la table de hashage 
 */
void hashtab_insert_elem (hashtab* htab, int id, char* name, char* num);

#endif
