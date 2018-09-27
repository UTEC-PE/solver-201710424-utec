#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T data;
    struct Node* next;
    void killSelf(){
        if(this->next)
            this->next->killSelf();
        delete this;
    };
};

#endif
