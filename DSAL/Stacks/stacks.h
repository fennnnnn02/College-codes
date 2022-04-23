#include <iostream>

using namespace std;

template <class T>
class Stack;

template <class T>
class Node{
    private:
    T info;
    Node<T> *next;
    public:
    Node();
    friend class Stack<T>;
};

template <class T>
class Stack{
    private:
    Node<T>* top=NULL;
    public:
    Stack();
    bool isempty();
    bool isfull();
    T peek();
    void push(T a);
    void pop();
    void display();
};
