#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

int main(int argc, char *argv[]){

  srand (time(NULL));
  
  vector<int> vec ;

  for(int i=0 ; i < 10 ; i ++){
    vec.push_back(i+1);
  }

  for(int i=0 ; i < vec.size() ; i ++){
    cout << vec[i] << " , " ;
  }

  cout << endl;
  random_shuffle(vec.begin(),vec.end());

  for(int i=0 ; i < vec.size() ; i ++){
    cout << vec[i] << " , " ;
  }

  cout << endl;

  cout << "max : " << *max_element(vec.begin(),vec.end());
  cout << endl;

  cout << "min : " << *min_element(vec.begin(),vec.end());;
  cout << endl;


  sort(vec.begin(),vec.end());;


  for(int i=0 ; i < vec.size() ; i ++){
    cout << vec[i] << " , " ;
  }


  cout << endl;;

  
  return 0;
}
