//
// Created by User on 29/09/2021.
//
#ifndef STACKTWOQUEUE__QUEUE_H
#define STACKTWOQUEUE__QUEUE_H
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

//Clase Queue
template <class T>
class _queue{
protected:
    using Tnode = node<T>*;
    Tnode top = nullptr;
    Tnode bottom = nullptr;
    int q_size = -1;

public:
    _queue () = default;
    bool empty() { return (top == nullptr);}
    void enqueue (const T& value);
    bool dequeue  ();
    T front() const { return  this->top->info;}
    T back() const { return  this->bottom->info;}
    const _queue<T>& operator=(const _queue<T>&);
    void swap(_queue<T>&);
    ~_queue() = default;
};



template<class T>
void _queue<T>::enqueue(const T &value) {
    auto newnode_a = new node<T>(value);
    (this->empty())?
            top = newnode_a:
            bottom->_next = newnode_a;

    bottom = newnode_a;
    ++q_size;
}

template<class T>
bool _queue<T>::dequeue() {
    if(this->empty())
        return false;

    auto  aux = top;
    top = top->_next;
    delete aux;
    --q_size;
    return true;
}

template <class T>
const _queue<T>& _queue<T>::operator=(const _queue<T> & _value) {
    if (this != &_value){
        this->top = _value.top;
        this->bottom = _value.bottom;
        this->q_size = _value.q_size;
    }
    return *this;
}

template<class T>
void _queue<T>::swap(_queue<T> & _q) {
    auto temp = _q;
    _q = *this;
    *this = temp;
}

#endif //STACKTWOQUEUE__QUEUE_H
