#include <iostream>
#include <map>
#include <utility>
#include <cmath>
#include <cstring>
#include "queue.h"
#include "stack.h"

using namespace std;

void remplazo_variable(char* &str){
  typedef pair<char, char*> variable;
  map <char, char*> variables;
  char* temp;
  temp = (char*) malloc(sizeof(str));
  int pos_s = 0;
  int av = 0; //la cantidad de espacios a aumentar
  for (int i = 0; str[i] != '\0'; i++) {
    if (isalpha(str[i])) {
      if (variables.find(str[i])==variables.end()) {
        char* value_temp;
        cout << "Ingrese el valor de " <<str[i] <<": ";
        cin >> value_temp;
        char* value;
        value = (char*) malloc(sizeof(value_temp));
        strcpy(value,value_temp);
        variables.insert(variable(str[i],value));
      }
    }
  }
  for (auto i = variables.begin(); i != variables.end(); i++) {
    temp = (char*) malloc(sizeof(temp) + sizeof(i->second) - sizeof(*(i->second)));
  }
  for (int i = 0; str[i] != '\0'; i++) {
    if (isalpha(str[i])) {
      for (int j = 0; *(variables.find(str[i])->second+j) != '\0'; j++) {
        *(temp+i+av) = *(variables.find(str[i])->second+j);
        av++;
      }
    }else{
      *(temp+i+av) = *(str+i);
    }
  }
  str = (char*) malloc(sizeof(temp));
  strcpy(str,temp);
  delete[] temp;
};

void plus_minus(char* &str){
  char* temp;
  temp = (char*) malloc(sizeof(str));
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

string masmenos(string x){
  char *str=&x[0];
  string answer="";
  int cont=0;
  while (*str!='\0') {
    if(*str==45)
      cont++;
    str++;
  }
  if(cont%2==0)
    answer='+';
  else{
    answer='-';
  }
  return answer;
};

// Por qué retornar int?
int transform(char *str){
  std::map<string, int> map{{"+",2},{"-",2},{"*",3},{"/",3},{"^",4}};
  Stack<string> stack;
  Queue<string> queue;
  string acum="";
  string temp="";
  while(*str != '\0'){
    if(*str<58 && *str>47){

      while(*str<58 && *str>47){
        acum+=*str;
        str++;
        if(*str==46){
          acum+=*str;
          str++;
        }
      }str--;
      queue.push(acum);
    }
    if(*str==42 || *str==43 || *str==47 || *str==94 || *str==45){
      if(*str==45 || *str==43){
        while (*str==43 || *str==45) {
          acum+=*str;
          str++;
        }
        str--;
        acum=masmenos(acum);
      }
      acum=*str;
      if(!stack.empty()){
        while (!stack.empty() &&  map[stack.get()]>=map[acum] && acum!="(") {
          temp=stack.get();
          stack.pop();
          queue.push(temp);
        }
      }
      stack.push(acum);
    }
    if(*str==40){
      acum=*str;
      stack.push(acum);
    }
    if(*str==41){
      while(stack.get()!="("){
        temp=stack.get();
        stack.pop();
        queue.push(temp);
      }
      stack.pop();
    }
    acum="";
    str++;
  }
  while (!stack.empty()) {
    temp=stack.get();
    stack.pop();
    queue.push(temp);
  }
  queue.print();
  int size=queue.size();
  for(int i=0;i<size;i++){
    if(!(queue.get()=="+" || queue.get()=="-" || queue.get()=="*" || queue.get()=="/" || queue.get()=="^")){
        if(queue.get()!="")
          stack.push(queue.get());
    }
    else{
      if(queue.get()=="+"){
        //cout<<"suma"<<endl;
        double x=stod(stack.get());
        stack.pop();
        double y=stod(stack.get());
        stack.pop();
        double z=y+x;
        stack.push(to_string(z));
      }
      else if(queue.get()=="-"){
        //cout<<"resta"<<endl;
        double x=stod(stack.get());
        stack.pop();
        double y=stod(stack.get());
        stack.pop();
        double z=y-x;
        stack.push(to_string(z));
      }
      else if(queue.get()=="*"){
        //cout<<"multi"<<endl;
        double x=stod(stack.get());
        stack.pop();
        double y=stod(stack.get());
        stack.pop();
        double z=y*x;
        stack.push(to_string(z));
      }
      else if(queue.get()=="/"){
        //cout<<"division"<<endl;
        double x=stod(stack.get());
        stack.pop();
        double y=stod(stack.get());
        stack.pop();
        double z=y/x;
        stack.push(to_string(z));
      }
      else if(queue.get()=="^"){
        //cout<<"potencia"<<endl;
        double x=stod(stack.get());
        stack.pop();
        double y=stod(stack.get());
        stack.pop();
        double z=pow(y,x);
        stack.push(to_string(z));
      }
    }
    queue.pop();
  }
  stack.print();
};
