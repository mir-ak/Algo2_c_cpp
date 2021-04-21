#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
 
using namespace std;

int main(int argc, char const *argv[])
{
	map<string, int> compteMots;
	const char *file;
	if(argc ==2){
		file = argv[1];
		ifstream is(file);
	 	string mot;
		string tmp;
	 	std::cout << "Saisissez un mot : " ;
	    std::cin >> tmp;
		while (is >> mot)
		{
			compteMots[mot]++;
		}
		for (auto it = compteMots.begin(); it != compteMots.end() ; ++it)
		{
			if (it == compteMots.find(tmp))
			{	
				
				cout << setw(20) <<" Le Mots : "<< it->first << '\t'<<"Nb_Occurrences : "<< it->second << endl;
			}
		}
		
	}
	else{
		std::cout<<"========ERREUR======="<<std::endl;
	}
}
		
