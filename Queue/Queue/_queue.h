//
// Created by br14n on 12/4/22.
//

#ifndef QUEUE__QUEUE_H
#define QUEUE__QUEUE_H
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
    void show ();
    bool dequeue  ();
    bool onqueue(const T& value);
    node<T>* peek() const { return  this ->top;}
    ~_queue() = default;
};



template<class T>
void _queue<T>::show() {
    for (auto i = this->top; i != nullptr; i = i->_next)
        std::cout << "[" << i ->info << "]";
}

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

template<class T>
bool _queue<T>::onqueue(const T &value) {

    for (auto& i = top; i != nullptr; i = i->_next)
        if(value == i->info) return true;

    return false;
}

#endif //QUEUE__QUEUE_H
