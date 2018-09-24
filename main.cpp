//powered by apu.mp
#include <iostream>
#include <ctype.h>
#include <cstring>
#include <map>
#include <utility>

using namespace std;

void remplazo_variable(char* str, map <char, double> &variables){
  typedef pair<char, double> variable;
  for (int i = 0; str[i] != '\0'; i++) {
    if (isalpha(str[i])) {
      if (variables.find(str[i])==variables.end()) {
        double value;
        cout << "Ingrese el valor de " <<str[i] <<": ";
        cin >> value;
        variables.insert(variable(str[i],value));
      }
    }
  }
};

void plus_minus( char* &str){
  char* temp;
  temp = (char*) malloc((i+1)sizeof(str));
  int minus = -1;
  int pos_s = 0;
  int av = 0; //la cantidad de signos a omitir
  for (int i = 0; str[i] != '\0'; i++) {
    if ((str[i]=='+' || str[i]=='-') && minus < 0) {
      minus++;
      pos_s = i -av;
    }else if(str[i]=='+' || str[i]=='-') {
      av++;
      if (str[i]=='-') {
        minus++;
      }
    }else if (minus >=0) {
      if (minus%2==0) {
        *(temp+pos_s) = '+';
      }else *(temp+pos_s) = '-';
      minus =-1;
      *(temp+i-av) = *(str+i);
    }else{
      *(temp+i-av) = *(str+i);
    }
    if (*(str+i+1)=='\0') {
      *(temp+i-av+1)='\0';
    }
  }
  str = (char*) malloc(sizeof(temp));
  strcpy(str,temp);
  delete[] temp;
}

double operator(char* str, map <char, double> variables)
{
    for (int i = 0; *(str+i) != '\0'; i++) {
      if (ispunct(*(str+i))) {
        char* a;
        a = (char*) malloc(sizeof(str))
      }
    }

    switch(op)
    {
        case '+':
            cout << num1+num2;
            break;

        case '-':
            cout << num1-num2;
            break;

        case '*':
            cout << num1*num2;
            break;

        case '/':
            cout << num1/num2;
            break;

        default:
            // If the operator is other than +, -, * or /, error message is shown
            cout << "Error! operator is not correct";
            break;
    }

    return 0;
}

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
  map <char, double> variables;
  remplazo_variable(str, variables);
  return 0;
}
