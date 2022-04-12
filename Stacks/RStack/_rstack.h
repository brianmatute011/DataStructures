//
// Created by br14n on 12/4/22.
//

#ifndef RSTACK__RSTACK_H
#define RSTACK__RSTACK_H
#include <iostream>

//Clase nodo
template <class T>
struct node{
    T info;
    node* _next = nullptr;
    node() = default;
    explicit node(const T & _info, node * _prox = nullptr) {info = _info; _next = _prox;}
    ~node() = default;
};

//Clase RStack
template <class T, const int N>
class _rstack{
public:
    using Tnode = node<T>*;
    Tnode top = nullptr;
    int rst_size = -1;

public:
    _rstack () = default;
    bool empty() { return (top == nullptr);}
    bool push (const T& value);
    void show ();
    bool pop  ();
    size_t capacity() const{ return N;}
    size_t count() const{ return rst_size + 1;}
    node<T>* peek() const { return  this ->top;}
    ~_rstack() = default;
};



template <class T, const int N>
void _rstack<T, N>::show() {
    for (auto i = this->top; i != nullptr; i = i->_next)
        std::cout << "[" << i ->info << "]";
}

template <class T, const int N>
bool _rstack<T, N>::push(const T &value) {
    auto newnode_a = new node<T>(value, top);
    if ((N - 1) - this->rst_size < 1)
        return false;

    top = newnode_a;
    ++rst_size;
    return true;
}

template <class T, const int N>
bool _rstack<T, N>::pop() {
    if(this->empty())
        return false;

    top = top->_next;
    --rst_size;
    return true;
}
#endif //RSTACK__RSTACK_H
