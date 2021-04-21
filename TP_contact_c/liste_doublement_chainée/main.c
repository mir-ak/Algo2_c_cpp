#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include"listedbc.h"

int main(int argc, char const *argv[])
{
	contact *pos;
    dbc *lst = lst_create_liste();

    //contact *contact1;/* = lst_create_node(1, "Jane Doe", "01 02 03 04 05");*/
    //lst_display_contacte(contact1);
    //lst_delete_contact(lst,contact1);
    lst_insert_head(lst, lst_create_node(2, "Mirak Karim", "01 02 03 04 05"));
    lst_insert_head(lst, lst_create_node(1, "Monkey D.luffy", "04 00 99 71 24"));
    lst_insert_tail(lst, lst_create_node(4, "Roronoa Zoro", "02 05 24 75 32"));
    lst_insert_tail(lst, lst_create_node(3, "Vinsmoke Sanji ", "04 97 30 32 06"));
    pos = lst_search_id(lst, 4);/*
    lst_insert_after(lst, lst_create_node(3, "Nico Robin", "01 22 22 69 40"), pos);
    pos = lst_search_id(lst, 3);
    lst_insert_after(lst, lst_create_node(4, "Tony Chopper","07 25 16 91 55"), pos);
    lst_insert_tail(lst, lst_create_node(7, "Nami", "01 12 32 69 41"));
    pos = lst_search_id(lst, 7);
    lst_insert_after(lst, lst_create_node(8, "Brook", "01 22 22 69 48"), pos); 
    lst_insert_tail(lst, lst_create_node(9, "Franky", "07 97 30 32 16"));
    lst_insert_tail(lst, lst_create_node(10, "Usopp", "06 97 45 32 16"));*/
    lst_display(lst);

    /*lst_delete_head(lst);
    lst_delete_tail(lst);*/
    lst_delete_contact(lst, pos);
    printf("\n");
    lst_display(lst);
   	/*lst_erase(lst);
   
   	lst_display(lst);
   */
    return 0;
	
}
