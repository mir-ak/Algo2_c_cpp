#include <iostream>

void permut(int &a, int &b){

  int tmp  ;
  tmp = a  ;
  a   = b  ;
  b   = tmp;
}


int main(int argc, char *argv[]){

  std::cout << "Hello World ! " << std::endl ;

  int a,b;
  
  std::cout << "entier 1 " ;
  std::cin >> a;
  std::cout <<  "entier 2 ";
  std::cin >> b ;
  std::cout <<  a+b << std::endl;

  std::cout <<  "a = " << a << "  b=" << b << std::endl;
  permut (a,b);
  std::cout <<  "a = " << a << "  b=" << b << std::endl;

  return 0;
}
