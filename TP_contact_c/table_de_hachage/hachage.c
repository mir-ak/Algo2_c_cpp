#include <stdio.h>
#include <stdlib.h>
#include"listedbc.h"

int hashtable_get_hash(HashTable *htab, int key){
   return key % htab->size ;
}

dbc **hashtable_create_tab(int size){
    int i;
    dbc **tab = malloc(size * sizeof(dbc *));

    for (i = 0; i < size; ++i)
    {
        tab[i] = lst_create_liste();
    }
    return tab;
}

HashTable *hashtable_create(int size)
{
    HashTable *htab = malloc(sizeof(HashTable));
    if (!htab)
        return NULL;
    htab->size = size;
    htab->tab = hashtable_create_tab(size);
    return htab;
}
void hashtable_insert_elem(HashTable *htab, int id, const char *name, const char *num)
{
    if (!htab || !htab->tab)
        return;
    int cle = hashtable_get_hash(htab, id);
    lst_insert_tail(htab->tab[cle], lst_create_node(id, name, num));
}


void hashtable_print(HashTable *htab)
{
    if (!htab || !htab->tab)
        return;
    int i;
    for (i = 0; i < htab->size; ++i)
    {
        printf("######### %d ############\n", i + 1);
        lst_display(htab->tab[i]);
        printf("*************************\n");
    }
}

    void hashtable_delete_tab(dbc **lst, int size)
{
    if (!lst)
        return;
    int i;
    for (i = 0; i < size; ++i)
    {
        lst_erase(lst[i]);
        lst[i] = NULL;
    }
    free(lst);
    lst = NULL;
}

void hashtable_delete(HashTable *htab)
{
    if (!htab)
        return;
    if (htab->tab)
        hashtable_delete_tab(htab->tab, htab->size);
    htab->tab = NULL;
    free(htab);
    htab = NULL;
}
contact *hashtable_search_id(HashTable *htab, int id_search)
{
    if (!htab || !htab->tab)
        return NULL;
    int cle = hashtable_get_hash(htab, id_search);
    return lst_search_id(htab->tab[cle], id_search);
}
/*
int main()
{
    HashTable *htab = hashtable_create(4);
    hashtable_insert_elem(htab, 2, "Jane Doe", "01 02 03 04 05");
    hashtable_insert_elem(htab, 1, "Gerhold Ciara", "04 00 99 71 24");
    hashtable_insert_elem(htab, 5, "Dibbert Julianne", "02 05 24 75 32");
    hashtable_insert_elem(htab, 6, "Durgan Frederik", "04 97 30 32 06");
    hashtable_insert_elem(htab, 3, "Romaguera Vince", "01 22 22 69 40");
    hashtable_insert_elem(htab, 4, "Christiansen Amely", "07 25 16 91 55");
    hashtable_print(htab);
    printf("\n");
    lst_display_contacte(hashtable_search_id(htab, 5));
    hashtable_delete(htab);
    return 0;
}*/