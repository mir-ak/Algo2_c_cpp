#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


/*
Écrire une fonction qui permet de demander à l’utilisateur de saisir une valeur
entière et retourne cette valeur. La fonction doit redemander à l’utilisateur de
ressaisir le nombre si la saisie n’est pas correcte.
*/

int input_int(){
  char str[10];
  int i;
  
  while (1){
    printf("Entrez un entier :");
    scanf("%s",str);
    for(i=0; i < strlen(str) ; i++){
      if (str[i] < '0' || str[i] > '9' || i >= 10 ){
	printf("Erreur saisie réessayer. ");
	break;
      }
    }

    if(i == strlen(str)){
      return atoi(str);
    }
  }
}
/*
Écrire une fonction qui prend en argument la taille du tableau, et créé dynamiquement le tableau, la fonction retourne un pointeur.
*/

int* create_tab (int t){
  int *tab;
  tab = (int*) malloc (t * sizeof(int));
  return tab;
}



/*
Écrire une fonction qui prend en argument un pointeur sur un tableau alloué dynamiquement et libère la mémoire allouée. 
*/

void free_tab(int *t){
  if (t == NULL)
    return;
  free(t);
}

/*
Écrire une fonction qui prend en paramètre un tableau et sa taille n, cette  fonction doit remplir le tableau avec des entiers de 1 à n
*/

void fill_tab (int* tab, int t){
  int i;
  for(i=0; i < t ; i++){
    tab[i]=i+1;
  }
}


/*
Écrire une fonction qui prend en argument un tableau et la taille du tableau, et affiche le contenu du tableau
*/

void display_tab (int* tab, int t){
  int i;
  for(i=0; i < t ; i++){
    printf (" %d ",tab[i]);
  }
  printf("\n");
}





/*
Écrire une fonction qui prend en argument un tableau et la taille du tableau, et remplie correctement le tableau avec des entiers saisie au clavier .
*/

void fill_tab_keyboard(int* tab, int t){
  int i;
  for(i=0; i < t ; i++){
    tab[i]=input_int();
  }
}

/*
Écrire une fonction qui prend en argument deux tableau t1 et t2 de même
taille, et la taille des tableaux, cette fonction doit copier les éléments de t2
dans t1.
*/

void copy_tabs(int* tab1, int* tab2, int t){
  int i;
  for(i=0; i < t ; i++){
    tab1[i]=tab2[i];
  }
}


/*
Écrire une fonction qui implémente la navette de knuth, cette méthode permet de mélanger un tableau d'entier d'une façon uniforme.
*/

void knuth (int *tab, int t){
  int i, r, tmp;
  srand(time(NULL));
  for(i=t-1; i > 0 ; i--){
    r = rand() % (i);
    tmp = tab[i];
    tab[i] = tab[r];
    tab[r] = tmp;
  }
}




/*
Tri par sélection 
*/
int sort_select (int *tab, int t){

}

/*
Tri par insertion
*/
int sort_insert (int *tab, int t){

}

/*
Tri par bull
*/
int sort_bull (int *tab, int t){

}

/*
Tri par fusion
*/
int sort_fusion (int *tab, int t){

}


/*
Tri rapide
*/
int quick_sort (int *tab, int t){
  if (t == 0){ return 0; }
  int pivot = tab[t-1];
  int sel = 0,pos = 0, tmp = 0;
  while (pos < t){
    if (tab[pos] <= pivot){
      tmp = tab[sel];
      tab[sel] = tab[pos];
      tab[pos] = tmp;
      sel++;
    }
    pos++;
  }
  quick_sort(tab, sel-1);
  quick_sort(tab+sel, t - sel);
}



int main(int argc, char* argv[]){
  int *tab1;
  int size = 10;

  printf("Cretae Tab size %d \n",size);

  tab1 = create_tab(size);
  fill_tab(tab1, size);
  display_tab(tab1, size);
  
  // fill_tab_keyboard(tab1, size);
  // display_tab(tab1, size);
  
  int * tab2 = create_tab(size);
  copy_tabs(tab2, tab1, size);
  
  printf("Knuth : \n");
  knuth(tab2, size);
  display_tab(tab2, size);


  printf("Tri par sélection : \n");
  int *tab3 = create_tab(size);
  copy_tabs(tab3, tab2, size);
  quick_sort(tab3, size);
  display_tab(tab2, size);
  display_tab(tab3, size);


  printf("Tri à insertion  : \n");
  int *tab4 = create_tab(size);
  copy_tabs(tab4, tab2, size);
  quick_sort(tab4, size);
  display_tab(tab2, size);
  display_tab(tab4, size);


  
  printf("Tri à bulles : \n");
  int *tab5 = create_tab(size);
  copy_tabs(tab5, tab2, size);
  quick_sort(tab5, size);
  display_tab(tab2, size);
  display_tab(tab3, size);


  printf("Tri par fusion : \n");
  int *tab6 = create_tab(size);
  copy_tabs(tab6, tab2, size);
  quick_sort(tab6, size);
  display_tab(tab2, size);
  display_tab(tab6, size);

  printf("Tri par peigne : \n");
  int *tab7 = create_tab(size);
  copy_tabs(tab7, tab2, size);
  quick_sort(tab7, size);
  display_tab(tab2, size);
  display_tab(tab7, size);


  printf("Tri par rapide : \n");
  int *tab8 = create_tab(size);
  copy_tabs(tab8, tab2, size);
  quick_sort(tab8, size);
  display_tab(tab2, size);
  display_tab(tab4, size);



  
  
  free_tab(tab1);
  free_tab(tab2);
  free_tab(tab3); 
  free_tab(tab4);
  free_tab(tab5);
  free_tab(tab6);
  free_tab(tab7); 
  free_tab(tab8);


}
    
    
