//
// Created by br14n on 11/4/22.
//

#ifndef LINKED_LIST__LIST_H
#define LINKED_LIST__LIST_H
#include <iostream>
//Clase nodo
template <class T>
struct node{
    T info;
    node* next = nullptr;
    node* previous = nullptr;
    node() = default;
    explicit node(const T & _info, node * _next = nullptr, node* _previous = nullptr){next = _next; previous = _previous; info = _info;}
    ~node() = default;
};

template <class T>
class _list{
protected:
    using Tnode = node<T>*;
    Tnode first = nullptr;
    Tnode last  = nullptr;
    size_t l_size = 0;

public:
    _list () = default;
    bool empty () { return (first == nullptr) and (last == nullptr);}
    bool insert (const T& new_element, const size_t& pos);
    void insert_front (const T& value);
    void insert_back (const T& value);
    void show();
    node<T>* element (const size_t& pos_element);
    size_t count () const{ return l_size;}
    bool remove (const size_t& pos);
    bool remove_front ();
    bool remove_back  ();
    void invest ();
    node<T>* get_first () const { return  this ->first;}
    node<T>* get_last  () const { return  this ->last;}
    ~_list() = default;
};

template<class T>
void _list<T>::insert_front(const T &value) {
    auto node_a = new node<T>(value, first);
    (this->empty())?
            last = node_a:
            first->previous = node_a;
    first = node_a;
    ++ l_size;
}

template<class T>
void _list<T>::show() {
    for (auto i = this->first; i != nullptr; i = i->next)
        std::cout << "[" << i->info <<"]";
    std::cout <<"\t";
}

template<class T>
void _list<T>::insert_back(const T &value) {
    auto node_a = new node<T>(value, nullptr, last);
    (this->empty())?
            first = node_a:
            last->next = node_a;
    last = node_a;
    ++l_size;
}

template<class T>
node<T> *_list<T>::element(const size_t &pos_element) {
    if (!this->empty() and (pos_element >= 0) and (pos_element < l_size)){
        auto i = this->first;
        for (int k = 0; k < pos_element; k++)
            i = i->next;
        return i;
    }
    return nullptr;
}

template<class T>
bool _list<T>::remove(const size_t &pos) {
    auto node_a = this->element(pos);
    if (node_a == nullptr){
        return false;
    }
    else{
        if(node_a == this->first){
            this->remove_front();
        }
        else{
            if(node_a == this->last){
                this->remove_back();
            }
            else{
                node_a->previous->next = node_a->next;
                node_a->next->previous = node_a->previous;
                delete node_a;
            }
            --l_size;
        }
        return true;
    }
}

template<class T>
bool _list<T>::remove_front() {
    if (this->empty())
        return false;

    auto aux = this->first;
    first = first->next;

    (first == nullptr)?
            last = nullptr:
            first->previous = nullptr;


    delete aux;
    --l_size;
    return true;
}

template<class T>
bool _list<T>::remove_back() {
    if (this->empty())
        return false;

    auto aux = this->last;
    last = last->previous;

    (last == nullptr)?
            first = nullptr:
            last->next = nullptr;


    delete aux;
    --l_size;
    return true;
}

template<class T>
bool _list<T>::insert(const T &new_element, const size_t &pos) {
    auto  node_a = element(pos);
    auto new_node = new node<T>(new_element);
    if (this->empty() or node_a == nullptr)
        return false;

    else if (node_a == this->first){
        insert_front(new_node->info);
    }
    else{
        new_node->previous = node_a->previous;
        new_node->previous->next = new_node;
        new_node->next = node_a;
        node_a->previous = new_node;
    }
    ++ l_size;
    return true;
}

template<class T>
void _list<T>::invest() {
    _list<T> new_instance;

    for(auto  i = last; i != nullptr; i = i->previous)
        new_instance.insert_back(i->info);

    *this = new_instance;
}

#endif //LINKED_LIST__LIST_H
