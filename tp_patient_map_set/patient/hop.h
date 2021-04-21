#include <string>
#include <cstring>
#include<list>
using namespace std;

class Patient{
public:
	string nom;
	string prenom;
	string Nss;
	int douleur;
	Patient(std::string Nom, std::string Prenom, std::string Numero,int dlr ); 
	void c_get();
	int get_douleur();
};
struct CustomCompare
{
    bool operator()(Patient & a, Patient & b)
    {
        return a.douleur < b.douleur;
    }
};
typedef struct CustomCompare cmp ;

