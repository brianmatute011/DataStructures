//
// Created by user on 4/10/21.
//

#ifndef SORTLIST___ORDERED_LIST_H
#define SORTLIST___ORDERED_LIST_H
#include "__list.h"

template <class T>
class __ordered_list: __list<T>{
public:
    __ordered_list() = default;
    void show() override;
    bool insert (const T& new_element);
    bool remove (const T& delete_elem);
    bool remove_front() override{ return __list<T>::remove_front();}
    bool remove_back() override{ return  __list<T>::remove_back();}
    bool find(const T& searchvalue);
    node<T>* get_first () const override { return  this ->first;}
    node<T>* get_last  () const override { return  this ->last;}
    void set_first(node<T>* __first) override;
    void set_last(node<T>* __last) override;
    const __ordered_list<T> &operator=(const __ordered_list<T> & v_asing);
    size_t count() const override { return __list<T>::count();}
private:
    std::pair<node<T>*, bool> ptr_element(const T& element);
};


template<class T>
void __ordered_list<T>::show() {
    __list<T>::show();
}

template<class T>
bool __ordered_list<T>::find(const T& searchvalue) {
    auto current = this->first;
    while(current->next != nullptr){
        if(current->info >= searchvalue)
            break;
        current = current->next;
    }

    return (current->info == searchvalue);
}

template<class T>
bool __ordered_list<T>::insert(const T &new_element) {
    if(this->empty())
        __list<T>::insert_back(new_element);
    else{
        if (new_element > this->last->info)
            __list<T>::insert_back(new_element);

        else if(new_element < this->first->info)
            __list<T>::insert_front(new_element);
        else{
            auto node_position = ptr_element(new_element);
            if(!node_position.second)
                return false;

            auto new_node = new node<T>(
                    new_element,
                    node_position.first,
                    node_position.first->previous
            );
            node_position.first->previous->next = new_node;
            node_position.first->previous = new_node;
            __list<T>::l_size++;
        }
    }

    return true;
}

template<class T>
std::pair<node<T> *, bool> __ordered_list<T>::ptr_element(const T &element) {
    std::pair<node<T> *, bool> value;

    auto i = this->first;
    for(; i->next != nullptr; i = i->next){
        if (element <= i->info)
            break;
    }
    value.first = i;
    value.second = (i->info != element);

    return value;

}

template<class T>
void __ordered_list<T>::set_first(node<T>* __first) {
    __list<T>::set_first(__first);
}

template<class T>
void __ordered_list<T>::set_last(node<T>* __last) {
    __list<T>::set_last(__last);
}

template<class T>
const __ordered_list<T>& __ordered_list<T>::operator=(const __ordered_list<T> &v_asing) {
    if(this != &v_asing){
        this->first = v_asing.first;
        this->last = v_asing.last;
        this->l_size = v_asing.l_size;
    }
    return *this;
}

template<class T>
bool __ordered_list<T>::remove(const T &delete_elem) {
    if(!this->empty()){
        if(delete_elem == get_first()->info)
            this->remove_front();
        else if(delete_elem == get_last()->info)
            this->remove_back();
        else{
            auto n_search_del = ptr_element(delete_elem);
            if(n_search_del.second)
                return false;

            n_search_del.first->previous->next = n_search_del.first->next;
            n_search_del.first->next->previous = n_search_del.first->previous;
        }
        __list<T>::l_size--;
        return true;
    }

    return false;
}

#endif //SORTLIST___ORDERED_LIST_H
