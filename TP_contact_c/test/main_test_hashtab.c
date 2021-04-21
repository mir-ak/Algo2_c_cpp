#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "hashtab.h"


int main(int argc, char* argv[]){
  hashtab* htb = hashtab_creat(10);
  hashtab_insert_elem(htb,20,"test","0202");
  hashtab_insert_elem(htb,2,"test","0202");
  hashtab_insert_elem(htb,10,"test","0202");
  hashtab_print(htb);
}
