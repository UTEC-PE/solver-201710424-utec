#ifndef STACK_H
#define STACK_H

#include "node.h"
#include <iostream>
using namespace std;

template <typename T>
class Stack {
//LIFO
private:
    Node<T>* head;
    Node<T>* tail;
public:
    Stack(){
        this->head= nullptr;
        this->tail= nullptr;
    };

    T get(){
        if(!this->head){
            throw("empty stack");
        } else{
            return this->head->data;
        }
    };
    void push(T value){
        Node<T>* temp= new Node<T>{value, this->head};
        this->head=temp;
        if (!this->head->next) {
            this->tail=temp;
        }
    };
    void pop(){
        Node<T>* temp=head;
        if (!temp) {
          throw("empty stack");
        }else if (temp==this->tail) {
          this->clear();
        }else{
          this->head=temp->next;
        }
        delete temp;
    };
    void print(){
        Node<T>* current=this->head;
        while(current!=this->tail){
            cout<<current->data<<' ';
            current=current->next;
        }
        cout<<current->data<<'\n';
    };
    bool empty(){
        return !(this->head);
    };
    int size(){
      Node<T>* current = this->head;
      int n=0;
      while (current) {
        current=current->next;
        n++;
      }
      return n;
    };
    void clear(){
        this->head=nullptr;
        this->tail=nullptr;
    };

    ~Stack(){
        if(this->head){
            this->head->killSelf();
        }
    };
};
#endif
