//powered by apu.mp
#include <iostream>
#include <map>
#include <utility>
#include "solver.cpp"

using namespace std;

char* menu() {
      cout<<"==========================================================="<<endl;
      cout<<"\t\tPractica Operaciones"<<endl;
      cout<<"==========================================================="<<endl;

      //char* str="7/4*((a+b)*a)+3";
      char* str="7/4*((a+-+--b)*a)+3";
      //char* str="2+(3)";
      //char* str="7/4*((a+b)^4*a)+3";
      cout <<str <<'\n';
      return str;
}

int main(int argc, char const *argv[]) {
  char* str;
  str = (char*) malloc(sizeof(menu()));
  str = menu();
  plus_minus(str);
  cout << str <<'\n';
  remplazo_variable(str);
  cout << str <<'\n';
  return 0;
}
