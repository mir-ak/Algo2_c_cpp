#include<iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <list>
#include <time.h>
#include <ctime>
#include <cstdio>
#include <unistd.h>
#include "Contacte.h"

using namespace std;
/*=================================================================================================================================================
                                     Gestion des contacts de 14 jusqu'au 252 lignes
===================================================================================================================================================*/
void Contacte::ajouter_numero(std::string nums){
    string o ; 
    do{
        std::cout << "Saisissez le numero : ";
        std::cin >> nums;
        std::cout <<"Souhaitez-Vous Ajoute Un Autre Numero A Ce Contacte Tape o sinon Tape n : ";
        std::cin >> o ; 
        std::cout <<"\n";
        num.push_back(nums);
    }while(o !="n");
}
Contacte::Contacte(std::string Nom,std::string Prenom, std::string Numero)
{
    int nb ;
    std::cout << "Saisissez le nom : " ;
    std::cin >> Nom ;
    std::cout << "Saisissez le prenom : " ;
    std::cin >> Prenom ;
    nom = Nom;
    prenom = Prenom ;
    
    ajouter_numero(Numero);        
}
void Contacte::c_get (){
    int i ;
    list<std::string>::iterator it ;
    
    std :: cout << "nom => : "<< nom << std::endl; 
    std :: cout << "prenom => : "<< prenom << std::endl;
    for (i = 1 ,it =num.begin(); it !=num.end(); ++it,i++)
     {
         std :: cout << "Numero_"<<i<<" => : "<< *it << std::endl;   
     }
}
void ajoute_contacts(std::list<Contacte> *contacts){
    string i_buffer1, i_buffer2, i_buffer3 , mot ; 
    char deja ; 
    int nb_contacte ;
    
    std::cout << "Combien De Contacte souhaitez-Vous Ajoute : " ;
    std::cin >> nb_contacte ;
    std::cout<<std::endl;
    list<Contacte>::iterator it;
    for (int i = 0; i < nb_contacte; ++i){
        Contacte tmp = Contacte(i_buffer1, i_buffer2,i_buffer3);
        if (nb_contacte > i+1){
            std::cout << "on passe en "<<i+2<<"éme contacte"<<std::endl ;      
            std::cout << "\n" ;
            }
        if (contacts->empty()){        
                contacts->push_back(tmp);
        }   
        else{
            for (it =contacts->begin(); it !=contacts->end(); ++it){   
                Contacte tmp2 = *it ;
                if (tmp.nom == tmp2.nom  && tmp.prenom == tmp2.prenom ){
                    std::cout <<"************************* ERREUR ***************************"<<std::endl ;
                    std::cout << "le contacte "<< tmp.nom<<" " << tmp.prenom <<" existe deja "<<std::endl ; 
                    std::cout <<"************************************************************"<<std::endl ;
                    deja = true; 
                            }
            }      
            if(deja != true){ 
                contacts->push_back(tmp);
            }  
        } 
    }     
}
void affiche_les_contacts(list<Contacte> *contacts){
    int menu ;
    int i;
    list<Contacte>::iterator it ; 
    std::cout<<"1. affiche tout les contacts  "<<endl;
    std::cout<<"2. affiche les contacts un par un "<<endl;
    std::cout<<"0. pour quitter "<<endl;
    std::cout<<std::endl;
    std::cout<<"Choix : ";
    std::cin>> menu ;
    int champ ; 
    switch(menu){
    case 1 :
        if (contacts->empty())
            {
             std :: cout <<" Vous-Avez Aucun Contacte Souhaitez-Vous Ajoute des contacts Tape 1 dans le Menu "<<std::endl; 
             std :: cout<<std::endl;
            }
        else{
            std :: cout <<" Voici votre liste des Contacts "<<std::endl; 
            std :: cout<<std::endl;
            for (i=1,it =contacts->begin(); it !=contacts->end(); ++it,i++){
        	   std :: cout << "===Contacte "<< i << "======"<< std::endl;
               it->c_get();
               std :: cout << "==================="<< std::endl;
            }
        }
            break;
    case 2 :
        if (contacts->empty()){
            std :: cout <<" Vous-Avez Aucun Contacte Souhaitez-Vous Ajoute des contacts Tape 1 dans le Menu "<<std::endl; 
            std :: cout<<std::endl;
        }
        
        std :: cout <<" Voici votre liste des Contacts "<<std::endl; 
        std :: cout<<std::endl;
        for (i=1,it =contacts->begin(); it !=contacts->end(); ++it,i++){
            std::cout << "Voyez Saisissez Un Numero : ";
            std::cin >> champ ;
            std :: cout << "======Contact "<< i << "========="<< std::endl;
            it->c_get();
            std :: cout << "========================="<< std::endl;
        }
        break;
    
    case 0 :
        break ; 
    }
}


void affiche_les_contacts_un_par_un(list<Contacte> *contacts){
   if (contacts->empty())
        {
         std :: cout <<" Vous-Avez Aucun Contacte Souhaitez-Vous Ajoute des contacts Tape 1 dans le Menu "<<std::endl; 
         std :: cout<<std::endl;
        }
    int champ ; 
    list<Contacte>::iterator it ; 
    int i;
    for (i=1,it =contacts->begin(); it !=contacts->end(); ++it,i++){
       std::cout << "Voyez Saisissez Un Numero : ";
       std::cin >> champ ;
       std :: cout << "======Contact "<< i << "========="<< std::endl;
       it->c_get();
       std :: cout << "========================="<< std::endl;
    }
}

void fonctionQuiCherche(list<Contacte> *contacts , std::string motQueJeCherche ){
    if (contacts->empty())
        {
         std :: cout <<" Vous-Avez Aucun Contacte Souhaitez-Vous Ajoute des contacts Tape 1 dans le Menu "<<std::endl; 
         std :: cout<<std::endl;
            return;
        }
    std :: cout <<"Tape votre mots de recherche : "; 
    std::cin >> motQueJeCherche;
    list<Contacte>::iterator it ;
    int i ;
    for (it =contacts->begin(); it !=contacts->end(); ++it){       
            Contacte tmp = *it ;
        for (i = 0; i != motQueJeCherche.size() ; ++i){
            if(tmp.prenom[i] == motQueJeCherche[i]  || tmp.nom[i] == motQueJeCherche[i] ){
               // std :: cout <<  <<" contacte a été trouve "<< std::endl;
                std :: cout << "==================="<< std::endl;
                tmp.c_get();
                std :: cout << "==================="<< std::endl;
                break ;
            }    
        }        
    }
    
}

Contacte *fonctionQuiCherche1(list<Contacte> *contacts , std::string motQueJeCherche ){

    std :: cout <<"Tape votre mot de recherche : "; 
    std::cin >> motQueJeCherche;
    list<Contacte>::iterator it ;
    int i ;
    for (it =contacts->begin(); it !=contacts->end(); ++it){       
        Contacte *tmp = &(*it) ;
        if(tmp->prenom == motQueJeCherche  || tmp->nom == motQueJeCherche ){
            return tmp;
        }
    }
}
Contacte *modifier_contacte(list<Contacte> *contacts , std::string motQueJeCherche){
    std::string n , p ;
    std::string nb ; 
    int mod,i=0,nb_num;
    list<Contacte>::iterator it ;
    if (contacts->empty())
        {
         std :: cout <<" Vous-Avez Aucun Contacte Souhaitez-Vous Ajoute des contacts Tape 1 dans le Menu "<<std::endl; 
        }
        else{
        
            std::cout<<"===================================!===================================="<< std::endl;
            std :: cout <<"Pour modifier un contact il faut Tape sont nom complet ou prenom merci :D : "<<std::endl;
            std:: cout<<"========================================================================"<<std::endl;
            std::cout<<std::endl;
            Contacte *tmp = fonctionQuiCherche1(contacts,motQueJeCherche);
            std::cout<<std::endl;
            list<string>::iterator pt= tmp->num.begin();
            
            std::cout<<"1. modifier le contacte "<<endl;
            std::cout<<"2. supprimer le contacts "<<endl;
            std::cout<<"0. pour quitter "<<endl;
            std::cout<<std::endl;
            std::cout<<"Choix : ";
            std::cin>> mod ;
            switch(mod)
            {
                case 0 : 
                    break ; 
                case 1 :
                    std::cout <<"Voulez Saisissez Les Modification Que Vous-souhaitez " << std::endl;
                    std::cout << "Saisissez le nom : " ;
                    std::cin >> n ;
                    (*tmp).nom = n;
                    std::cout << "Saisissez le prenom : " ;
                    std::cin >> p ;
                    (*tmp).prenom = p ;
                    std::cout << "Saisissez Combien des Numero souhaitez-Vous Modifier : " ;
                    std::cin >> nb_num ;
                    do{
                        if (nb_num > pt->size())
                         {
                        std::cout <<"************************* ERREUR ***************************"<<std::endl ;
                        std::cout <<"        Ce Contact Il As Pas "<< nb_num <<" Numero "<<std::endl ; 
                        std::cout <<"************************************************************"<<std::endl ;
                            break;
                        }
                        std::cout << "Saisissez le Numero : ";
                        std::cin >> nb ;
                        *pt = nb ;
                        ++i;
                        std::cout<<"<< i =>"<< i << std::endl ;  
                        ++pt;
                    }while(i < nb_num );
                break;
                case 2 :
                for (it =contacts->begin(); it !=contacts->end(); ++it){            
                    if (it->nom == tmp->nom || it->prenom == tmp->prenom ){
                        it = contacts->erase(it);
                        std::cout << "le contacts il est bien supprimer "<< std::endl;
                    break;
                    }
                }
            } 
        }
}
/******************************************************************************************************************************************************
                                             les appels en absences de 256 jusqu'au 350 lignes
******************************************************************************************************************************************************/
void appel::ajouter_num_appel_abs(){
    std::string numero;
    string o ; 
    int i , j , k;
        std::cout << "Saisissez le numero : ";
        std::cin >> numero;
        time(&temps_act);
        //ctime(&temps_act);
        for(i=0 ; i<5 ;i++){
            for (j = 0; j<i ; ++j)
                std::cout<<" ";
            for (k = 0; k < i; k++)
                std::cout<<"->> bip ";
            std::cout<<"\n";
        }
        std :: cout <<std::endl;
        std::cout<<"le numero demande n'est pas disponible acteullement veuillez réessayer ultérieurement merci"<<std::endl;
        num_apb.push_front(numero);
        std::cout<<std::endl;
}

appel::appel(list<Contacte> *cont){
    lst = cont ; 
}


Contacte* appel::recherche_appel_abs(std::string num_ch){
    if (num_apb.empty())
        {
         std :: cout <<" Vous-Avez Aucun Contacte Souhaitez-Vous Ajoute des contacts Tape 1 dans le Menu "<<std::endl; 
         return 0;
        }

    list<Contacte>::iterator it ;
    list<string>::iterator i ; 
    for (it =lst->begin(); it !=lst->end(); ++it){   
        Contacte *tmp = &(*it) ;
        for (i = tmp->num.begin() ; i !=tmp->num.end(); ++i)
        {
        if(*i == num_ch){
            return tmp ;
        }
        }   
    }
    return NULL;
}

void appel::c_get_num_appel_abs(){
    int i ;
    list<std::string>::iterator it ;

         std :: cout << "Vous-Avez " <<num_apb.size()<<" appel en absence "<<std::endl;
         std :: cout <<std::endl;
} 

void appel::affiche_appel_abs(){
   if (num_apb.empty()) {
        std :: cout <<" Vous-Avez Aucun Appelle en absence Souhaitez-Vous Ajoute des Appelle Tape 1 dans le Menu des appel en absence "<<std::endl; 
        std :: cout <<std::endl;
        return ;
    }
    std::cout<<"voici votre liste des appels en absence"<<std::endl;
    std :: cout<<"____________________________________________" <<std::endl;
    std :: cout <<std::endl;
    list<string>::iterator it;
    int i ;
    for (it =num_apb.begin(); it !=num_apb.end(); ++it){
        Contacte *tmp = recherche_appel_abs(*it);
        if (tmp != NULL){
            tmp->c_get();
            cout<<"recu le "<< ctime(&temps_act) <<std::endl;
            it = num_apb.erase(it);
        }
        else{
            std::cout<< "numero => : "<<*it<<" recu le "<< ctime(&temps_act)<<std::endl;
            it = num_apb.erase(it);

        }
    }
}   
void appel::supprimer_appel(){
    if (num_apb.empty()) {
        std :: cout <<"liste des Appels elle est vide ou Vous-Avez deja consulte la liste sera automatiquement supprimer"<<std::endl;
        std :: cout <<std::endl; 
        return ;
    }
    else{
        list<string>::iterator it;
        for (it =num_apb.begin(); it !=num_apb.end(); ++it){
             it = num_apb.erase(it);
            std :: cout <<"liste des Appels elle est bien suprime "<<std::endl;
        }
        std :: cout <<std::endl;
    }
}        
/*====================================================================================================================================================
                                Gestion des appels entrant/sortant de 354 jusqu'au 458 lignes
=======================================================================================================================================================*/
void appel::ajouter_num_appel(){
    std::string num_mots;
    int nb;
    int i , j , k;
    cout<<"1. souhaitez-Vous composer un numero : "<<endl;
    cout<<"2. souhaitez-Vous contacter un contact : "<<endl;
    cout<<"0. quitter "<<endl;
    std::cout<<std::endl;
    cout<<"Choix : ";
    cin>>nb;
    cout<<endl;
    switch(nb){
        case 0:
        break;
        case 1: 
            std::cout << "Saisissez le numero  : ";
            std::cin >> num_mots;
            time(&temps_act);
            for(i=0 ; i<5 ;i++){
                for (j = 0; j<i ; ++j)
                    std::cout<<" ";
                for (k = 0; k < i; k++)
                    std::cout<<"->> bip ";
                std::cout<<"\n";
                }
                std :: cout <<std::endl;
            std::cout<<"le numero demande n'est pas disponible acteullement veuillez réessayer ultérieurement merci"<<std::endl;
            std :: cout <<std::endl;
            num_apb.push_front(num_mots);
        break;
        case 2 : 
            if (lst->empty())
            {
                std :: cout <<" Vous-Avez Aucun Contacte Souhaitez-Vous Ajoute des contacts Tape 1 dans le Menu Principal "<<std::endl; 
                std :: cout <<std::endl;
                return ; 
            }
            else{
            std::cout << "Saisissez le nom ou prenom complet d'un contacts existe  : ";
            std::cin >> num_mots;
            time(&temps_act);
            for(i=0 ; i<5 ;i++){
                for (j = 0; j<i ; ++j)
                    std::cout<<" ";
                for (k = 0; k < i; k++)
                    std::cout<<"->> bip ";
                std::cout<<"\n";
                }
            std::cout<<"le numero demande n'est pas disponible acteullement veuillez réessayer ultérieurement merci"<<std::endl;
            std :: cout <<std::endl;
            num_apb.push_front(num_mots);
        }
        break;
    }
}   
Contacte* appel::recherche_appel(std::string mots){
    if (num_apb.empty())
        {
         std :: cout <<" Vous-Avez Aucun Contacte Souhaitez-Vous Ajoute des contacts Tape 1 dans le Menu "<<std::endl; 
         return 0;
        }

    list<Contacte>::iterator it ;
    list<string>::iterator i ; 
    for (it =lst->begin(); it !=lst->end(); ++it){   
        Contacte *tmp = &(*it) ;
        if(tmp->nom == mots || tmp->prenom == mots){
            return tmp ;
        }
    }   
    
    return NULL;
}
void appel::c_get_num_appel(){
    int i ;
    list<std::string>::iterator it ;

         std :: cout << "Vous-Avez fait " <<num_apb.size()<<" appels "<<std::endl;
         std :: cout <<std::endl;
} 
void appel::affiche_appel(){
   if (num_apb.empty()) {
        std :: cout <<" Vous-Avez Aucun Appelle en absence Souhaitez-Vous Ajoute des Appelle Tape 1 dans le Menu des appels entrant/sortant "<<std::endl; 
        std :: cout <<std::endl;
        return ;
    }
    std::cout<<"voici votre liste des appels entrant/sortant "<<std::endl;
    std :: cout<<"____________________________________________" <<std::endl;
    std :: cout <<std::endl;
    list<string>::iterator it;
    int i ;
    for (it =num_apb.begin(); it !=num_apb.end(); ++it){
        Contacte *tmp = recherche_appel(*it);
        Contacte *tmp2 = recherche_appel_abs(*it);
        if (tmp != NULL){
            //time(&temps_act);
            tmp->c_get();
            cout<<"recu le "<< ctime(&temps_act) <<std::endl;
            it = num_apb.erase(it);
        }
        else if (tmp2 != NULL){
            tmp2->c_get();
            cout<<"recu le "<< ctime(&temps_act) <<std::endl;
            it = num_apb.erase(it);
        }
        else{
            std::cout<< "numero => : "<<*it<<" recu le "<< ctime(&temps_act)<<std::endl;
            it = num_apb.erase(it);

        }
    }
}   

/*==================================================================================================================================================================
                                                        main 
================================================================================================================================================================*/

int main(int argc, char const *argv[])
{
    list<Contacte> contacts;
    appel p(&contacts);
    string mot ; 
    int menu , appel_abs,apel;
    bool b = 0;
do{
    std::cout<<" ----------------------- MENU -----------------------"<<std::endl;
        std::cout<<std::endl;
        cout<<"1. ajoute des contacts "<<endl;
        cout<<"2. affiche les contacts "<<endl;
        cout<<"3. cherche un contact"<<endl;
        cout<<"4. modifier les contacts ou supprimer"<<endl;
        cout<<"5. Gestion des appels en absence"<<endl;
        cout<<"6. Gestion des appels entrant/sortant"<<endl;
        
        cout<<"0. quitter "<<endl;
        std::cout<<std::endl;
        cout<<"Choix : ";
        cin>>menu;
        cout<<endl;

        switch(menu)
        {
            case 0 : std::cout<<"Au Revoir"<< std::endl ; 
            break;
 
            case 1 : ajoute_contacts(&contacts);;
            break;
 
                
            case 2 : contacts.sort(tri_contacts());
                     affiche_les_contacts(&contacts);
            break;
 
            case 3 : fonctionQuiCherche(&contacts,mot) ;
                    
            break;
 
            case 4 : modifier_contacte(&contacts,mot);;
            break;
            
            case 5: 
                do{
                    std::cout<<">>>>>>>>>>> Menu des appels en absence  <<<<<<<<<<<"<<endl;
                    std::cout<<std::endl;
                    std::cout<<"1. ajoute une appel en absence "<<std::endl;
                    std::cout<<"2. Afficher le nombre d’appels en absences"<<std::endl;
                    std::cout<<"3. Afficher les appels en absences"<<std::endl;
                    std::cout<<"4. Supprimer l’ensemble des appels en absence. "<<std::endl;
                    std::cout<<"0. Revenir au Menu Principal "<<std::endl;
                    std::cout<<std::endl;
                    cout<<"Choix : ";
                    cin>>appel_abs;
                    cout<<endl;
                    if(b==0){
                         p = appel(&contacts);
                         b= 1;
                    }
                    switch(appel_abs){  
                        case 1:
                        p.ajouter_num_appel_abs();
                        break;
                        case 2:
                        p.c_get_num_appel_abs();   
                        break;
                        case 3:
                        p.affiche_appel_abs();
                        break ;
                        case 4:
                        p.supprimer_appel();
                        break ;
                    }       
                }while(appel_abs!=0);

            break ; 
            case 6 : 
                do{
                    std::cout<<">>>>>>>>>>> Menu des appels entrant/sortant  <<<<<<<<<<<"<<endl;
                    std::cout<<std::endl;
                    std::cout<<"1. ajoute une appel entrant/sortant  "<<std::endl;
                    std::cout<<"2. Afficher le nombre d’appels entrants/sortants."<<std::endl;
                    std::cout<<"3. Afficher les appels entrants/sortants,"<<std::endl;
                    std::cout<<"4. Supprimer l’ensemble des appels entrant/sortant.. "<<std::endl;
                    std::cout<<"0. Revenir au Menu Principal "<<std::endl;
                    std::cout<<std::endl;
                    cout<<"Choix : ";
                    cin>>apel;
                    cout<<endl;
                    if(b==0){
                         p = appel(&contacts);
                         b= 1;
                    }
                    switch(apel){
                        case 1:
                        p.ajouter_num_appel();
                        break;
                        case 2:
                        p.c_get_num_appel();   
                        break;
                        case 3:
                        p.affiche_appel();
                        break ;
                        case 4:
                        p.supprimer_appel();
                        break ;
                        }       
                }while(apel!=0) ; 

            break;
        }   
}while (menu!=0);
	
    return 0;
}