#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <set>
#include <stdlib.h> 
 
using namespace std;

int main(int argc, char const *argv[])
{
	const char *file;
	if(argc ==2){
		file = argv[1];
		ifstream is(file);
	 	string mot;
		string tmp;
	 	std::cout << "Saisissez un mot : " ;
	    std::cin >> tmp;
	    int b ; 
		set<std::string> trouveMots;
		while (is >> mot)
		{
			trouveMots.insert(mot);
		}
		for (auto it = trouveMots.begin(); it != trouveMots.end() ; ++it)
		{
			if (it == trouveMots.find(tmp))
			{	
				b=1;
				break;
			}
			else{
				b=0;
			}
		}
		if (b==1){
			cout <<  "le mots existe" << endl;
		}
		else{
			cout <<  "le mots ne existe pas" << endl;
		}
	}
	else{
		std::cout<<"========ERREUR======="<<std::endl;
	}
}
		
