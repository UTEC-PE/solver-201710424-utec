#ifndef QUEUE_H
#define QUEUE_H

#include "node.h"
#include <iostream>
using namespace std;

template <typename T>
class Queue{
//FIFO
private:
    Node<T>* head;
    Node<T>* tail;
public:
    Queue(){
        head= nullptr;
        tail= nullptr;
    };

    T get(){
        if(!head){
            throw "empty queue";
        } else{
            return head->data;
        }
    };
    void push(T value){
        Node<T>* temp= new Node<T>{value, nullptr};
        if (!this->head) {
          this->head=temp;
        }else{
          this->tail->next=temp;
        }
        this->tail = temp;
        temp = nullptr;
        delete temp;
    };
    void pop(){
        Node<T>* temp=this->head;
        if(!temp)
          throw "empty queue";
        else if(this->tail==temp)
          this->clear();
        else{
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
        cout<<this->tail->data<<'\n';
    };
    bool empty(){
        return !(this->head);
    };
    int size(){
        Node<T>* current=this->head;
        int n=0;
        while (current) {
          n++;
          current=current->next;
        }
        return n;
    };
    void clear(){
        this->head=nullptr;
        this->tail=nullptr;
    };

    ~Queue(){
        if(this->head){
            this->head->killSelf();
        }
    };
};
#endif
