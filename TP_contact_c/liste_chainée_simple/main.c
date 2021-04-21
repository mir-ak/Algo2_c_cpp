#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_simple.h"

int main(int argc, char const *argv[])
{
	contact *pos;
    list *lst = lst_create_liste();
	
    printf("\n");
	list_insert_head(lst, list_create_node(1, "Jane Doe", "01 02 03 04 05"));
	//list_delete_contact(lst,pos)
	list_insert_tail(lst, list_create_node(3, "m", "01 02 03 04 05"));
	pos = list_search_id(lst,3);
	list_insert_after(lst, list_create_node(2, "mir", "01 02 03 04 05"),pos);
	list_insert_tail(lst, list_create_node(4, "mor", "01 02 03 04 05"));
	//pos = list_search_id(lst,2);
	
	list_display(lst);
	list_delete_head(lst);
	printf("---------\n");
	list_display(lst);
	free(lst);
	return 0;
}