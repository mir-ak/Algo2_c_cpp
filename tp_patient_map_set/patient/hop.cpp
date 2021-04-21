#include<iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <list>
#include <time.h>
#include <ctime>
#include <cstdio>
#include <unistd.h>
#include "hop.h"
#include <queue>
#include <vector>
using namespace std;
Patient::Patient(std::string Nom,std::string Prenom, std::string Numero,int dlr){
    int nb ;
    std::cout << "Saisissez le nom : " ;
    std::cin >> Nom ;
    std::cout << "Saisissez le prenom : " ;
    std::cin >> Prenom ;
    std::cout << "Saisissez le Numero de sécurité sociale : " ;
    std::cin >> Numero ;
    do{
    	std::cout << "Saisissez la douleur par l’échell [0,10] de patient : " ;
    	std::cin >> dlr ;
    if (dlr >0 && dlr <= 10)
    {
    	douleur = dlr ;
  	}
  	else{
  		std::cout <<"************************* ERREUR ***************************"<<std::endl ;
  		std::cout << " on a dit la douleur entre 0 & 10 ;  " << std::endl;
       	std::cout <<"************************************************************"<<std::endl ;
  	}
  	}while(dlr < 0 || dlr > 10);
    nom = Nom;
    prenom = Prenom ;
    Nss = Numero ;
}
int Patient::get_douleur(){
	return douleur;
}
void Patient::c_get (){  
    std :: cout << "nom => : "<< nom << std::endl; 
    std :: cout << "prenom => : "<< prenom << std::endl;
    std :: cout << "Numero de sécurité sociale => : "<< Nss << std::endl;   
    std :: cout << "la douleur de patient : " << douleur << std::endl ;
}
void ajoute_Patient( std::priority_queue<Patient,vector<Patient>,cmp> *patient){
    string i_buffer1, i_buffer2, i_buffer3 ; 
   	int douleur;
    char deja ; 
    int nb_patient ;
    
    std::cout << "Combien De Patient Souhaitez-Vous Enregistrer : " ;
    std::cin >> nb_patient ;
    std::cout<<std::endl;
    std::vector<Patient> v;
    std::vector<Patient>::iterator it;
    for (int i = 0; i < nb_patient; ++i){
        Patient tmp = Patient(i_buffer1, i_buffer2,i_buffer3,douleur);
        if (nb_patient > i+1){
            std::cout << "\n" ;
            std::cout << "on passe en "<<i+2<<"éme Patient"<<std::endl ;      
            std::cout << "\n" ;
            }
        
            patient->push(tmp);
            
        
    }     
}
void affiche_les_Patient(priority_queue<Patient ,vector<Patient>,cmp> patient){
    int i;
    std::priority_queue<Patient ,vector<Patient>,cmp> temp = patient;
    std::cout<<std::endl;
    if (temp.empty())
        {
     	std :: cout <<" Vous-Avez Aucun patient Souhaitez-Vous Ajoute des patient Tape 1 dans le Menu "<<std::endl; 
		std :: cout<<std::endl;
        }
    else{
    	std::cout<<"voici la liste des patient"<<endl;
	std::cout<<std::endl;
        while(!temp.empty()){
			Patient p = temp.top();
		    temp.pop();
			std::cout<<"==============Enregistre"<<"=================="<<std::endl;
		    p.c_get();
        	std::cout<<"=========================================="<<std::endl;
        }
   
    }           
}

void nb_patient(priority_queue<Patient ,vector<Patient>,cmp> *patient){ 
	if (patient->empty()){
     	std :: cout <<" Vous-Avez Aucun patient Souhaitez-Vous Ajoute des patient Tape 1 dans le Menu "<<std::endl; 
		std :: cout<<std::endl;
    }
	else{
    	std :: cout << "nombre de patient : "<< patient->size()<< std::endl;
        }
}
void affiche_le_passage(priority_queue<Patient ,vector<Patient>,cmp> *patient){
    if (patient->empty())
        {
     	std :: cout <<" Vous-Avez Aucun patient Souhaitez-Vous Ajoute des patient Tape 1 dans le Menu "<<std::endl; 
		std :: cout<<std::endl;
    }
    else{
		Patient p = patient->top();
	    patient->pop();
		std::cout<<"==============Prochaine Patient"<<"=================="<<std::endl;
	    p.c_get();
    	std::cout<<"================================================="<<std::endl;
        }

    }
int main(int argc, char const *argv[])
{	
	int menu ;
	 std::priority_queue<Patient,vector<Patient>,struct CustomCompare> patient;
	do{
    std::cout<<" ----------------------- MENU -----------------------"<<std::endl;
        std::cout<<std::endl;
        cout<<"1. Enregistrer des patient "<<endl;
        cout<<"2. affiche la liste des Patients "<<endl;
        cout<<"3. affiche le nombre de Patient"<<endl;
       	cout<<"4. affiche le Passage"<<endl;
        cout<<"0. quitter "<<endl;
        std::cout<<std::endl;
        cout<<"Choix : ";
        cin>>menu;
        cout<<endl;
        switch(menu)
        {
            case 0 : std::cout<<"Au Revoir"<< std::endl ; 
            break;
 
            case 1 : ajoute_Patient(&patient);
            break;
                
            case 2 : affiche_les_Patient(patient);
            break;
            
            case 3 : nb_patient(&patient);
        	break ;
        	
        	case 4 : affiche_le_passage(&patient);
        	break ; 
        }
    }while (menu!=0);
	return 0;

}
