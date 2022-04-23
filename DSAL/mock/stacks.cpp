#include <iostream>

#include "stacks.h"

using namespace std;

template <class T>
Node<T>::Node(){
    next = NULL;
}

template <class T>
Stack<T>::Stack(){
    top = NULL;
}

template <class T>
bool Stack<T>::isempty(){
    if(top==NULL) return true;
    else return false;
}

template <class T>
void Stack<T>::push(T a){
    Node<T>* temp = new Node<T>;
    temp->info = a;
    temp->next = top;
    top = temp;
}

template <class T>
void Stack<T>::pop(){
    if(isempty()) cout<<"Empty"<<endl;
    else{
        Node<T>*p = top;
        top = top->next;
        delete p;
        p=NULL;
    }
}

template <class T>
T Stack<T>::peek(){
    if(top==NULL) return 0;
    return top->info;
}

template <class T>
void Stack<T>::display(){
    if(isempty()) cout<<"Empty"<<endl;
    else{
        Node<T> *p = top;
        while(p!=NULL){
            cout<<p->info<<" ";
            p = p->next;
        }
    }
}



