#include <iostream>

template <typename T>
T add (T a, T b){

  T tmp  ;
  return a + b;
}

template <typename T, typename U>
T add (T a, U b){

  T tmp  ;
  return  a + b;
}



int main(int argc, char *argv[]){

  int a=4, b=6 ;
  std::cout << add (a,b) << std::endl;

  float c=5.0 , d=6.6;
  std::cout << add (c, d) << std::endl;


  int   e=5  ;
  float f=7.6;
  std::cout << add (f,e) << std::endl;


  return 0;
}
