#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"listedbc.h"
int main()
{
    HashTable *htab = hashtable_create(5);
    hashtable_insert_elem(htab, 1, "Mirak Karim", "01 02 03 04 05");
    hashtable_insert_elem(htab, 2, "Monkey D.luffy", "04 00 99 71 24");
    hashtable_insert_elem(htab, 3, "Roronoa Zoro", "02 05 24 75 32");
    hashtable_insert_elem(htab, 4, "Vinsmoke Sanji ", "04 97 30 32 06");
    hashtable_insert_elem(htab, 5, "Nico Robin", "01 22 22 69 40");
    hashtable_insert_elem(htab, 6, "Tony Chopper","07 25 16 91 55");
    hashtable_insert_elem(htab,7, "Nami", "01 12 32 69 41");
    hashtable_insert_elem(htab,8, "Brook", "01 22 22 69 48");
    hashtable_insert_elem(htab,9, "Franky", "07 97 30 32 16");
    hashtable_insert_elem(htab,10, "Usopp", "06 97 45 32 16");	

    hashtable_print(htab);
    //lst_display_contacte(hashtable_search_id(htab, 1));
    hashtable_delete(htab);
    return 0;
}