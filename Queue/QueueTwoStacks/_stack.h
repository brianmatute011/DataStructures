//
// Created by User on 29/09/2021.
//
#ifndef QUEUETWOSTACK__STACK_H
#define QUEUETWOSTACK__STACK_H
#include <iostream>

template <class T>
struct node{
    T info;
    node* _next = nullptr;
    node() = default;
    explicit node(const T & _info, node * _prox = nullptr) {info = _info; _next = _prox;}
    ~node() = default;
};

//Clase Stack
template <class T>
class _stack{
protected:
    using Tnode = node<T>*;
    Tnode top = nullptr;
    int st_size = -1;

public:
    _stack () = default;
    bool empty() { return (top == nullptr);}
    void push (const T& value);
    bool pop  ();
    T peek() const { return  this->top->info;}
    ~_stack() = default;
};


template<class T>
void _stack<T>::push(const T &value) {
    top = new node<T>(value, top);
    ++st_size;
}

template<class T>
bool _stack<T>::pop() {
    if(this->empty())
        return false;

    top = top->_next;
    --st_size;
    return true;
}

#endif //QUEUETWOSTACK__STACK_H
