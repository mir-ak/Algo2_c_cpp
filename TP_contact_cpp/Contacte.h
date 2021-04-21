#include <string>
#include <cstring>
#include<list>
using namespace std;

class Contacte{
public:
	string nom;
	string prenom;
	public : 
	list<string> num;
public:
	void ajouter_numero(std::string nums);
	Contacte(std::string Nom, std::string Prenom, std::string Numero); 
	void affiche_num();
	void c_get();
};

struct tri_contacts
{
	
	bool operator ()(const Contacte &a, const Contacte &b)
	{
		return a.nom < b.nom;
 
	}
};
class appel
{
	list<string> num_apb ;
	time_t temps_act;
	list<Contacte> *lst ;
	list<appel> p;
public:
	appel(list<Contacte> *cont); 
	void c_get_num_appel_abs();
	void ajouter_num_appel_abs();
	Contacte *recherche_appel_abs(string num_ch);
	void affiche_appel_abs();
	Contacte *recherche_appel(std::string mots);
	void ajouter_num_appel();
	void c_get_num_appel();
	void affiche_appel();
	void supprimer_appel();
	//void affiche_appel_ebs(string numer);

};
