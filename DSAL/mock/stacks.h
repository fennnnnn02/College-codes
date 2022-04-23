// Header File

#include <iostream>

using namespace std;

template <class T>
class Stack;


// Class NODE
template <class T>
class Node{
    private:
    T info;
    Node<T> *next;
    public:
    Node();
    friend class Stack<T>;
};


// Class STACK
template <class T>
class Stack{
    private:
    Node<T>* top=NULL;
    public:
    Stack();
    bool isempty();
    T peek();
    void push(T a);
    void pop();
    void display();
};
