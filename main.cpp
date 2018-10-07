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

// Carlos creo que debiste haber empezado implementando funciones simples tipo 5+3, y de ahí continuar agregando otras operaciones
int main(int argc, char const *argv[]) {
    char* str;
    if (argc == 2) {
        str = (char*)argv[1];
    }
    else {
      throw "One argument expected";
    }

    plus_minus(str);
    cout << str <<'\n';
    remplazo_variable(str);
    cout << str <<'\n';
    return 0;
}
