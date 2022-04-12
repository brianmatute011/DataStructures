//
// Created by br14n on 12/4/22.
//

#ifndef STACK__STACK_H
#define STACK__STACK_H
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
    void show ();
    bool pop  ();
    node<T>* peek() const { return  this ->top;}
    ~_stack() = default;
};



template<class T>
void _stack<T>::show() {
    for (auto i = this->top; i != nullptr; i = i->_next)
        std::cout << "[" << i ->info << "]";
}

template<class T>
void _stack<T>::push(const T &value) {
    auto newnode_a = new node<T>(value, top);
    top = newnode_a;
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

#endif //STACK__STACK_H
