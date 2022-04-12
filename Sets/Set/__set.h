//
// Created by user on 4/10/21.
//
#ifndef SORTLIST___SET_H
#define SORTLIST___SET_H
#include <iostream>
#include "__ordered_list.h"

template <class T>
class __set{
private:
    __ordered_list<T> l1;
public:
    __set() = default;
    T Min() const{ return l1.get_first()->info;};
    size_t Count() const{ return l1.count();};
    bool Insert(const T& value) { return l1.insert(value);}
    bool Delete(const T& value) { return l1.remove(value);}
    bool Member(const T& value) { return  l1.find(value);}
    __set<T> Union(const __set &s1);
    __set<T> Intersection(const __set &s1);
    void Show();
    const __set<T> &operator=(const __set<T> &);
};

template<class T>
__set<T> __set<T>::Union(const __set &s1) {
    __set<T> union_result = *this;

    auto i = s1.l1.get_first();
    for(; i != nullptr; i = i->next)
        union_result.Insert(i->info);

    return union_result;
}

template<class T>
const __set<T> &__set<T>::operator=(const __set<T> &s1) {
    if (this != &s1)
        this->l1 = s1.l1;

    return *this;
}

template<class T>
void __set<T>::Show() {
    auto i = this->l1.get_first();
    std::cout <<"{" <<i->info; i = i->next;

    for (; i != nullptr; i = i->next)
        std::cout <<", " << i->info;
    std::cout <<"}\t";

}

template<class T>
__set<T> __set<T>::Intersection(const __set &s1) {
    __set<T> inter_result, temp = *this;
    auto i = s1.l1.get_first();

    for(; i != nullptr; i = i->next)
        if(!temp.Insert(i->info))
            inter_result.Insert(i->info);

    return inter_result;
}



template <class T>
__ordered_list<T> Intersection(const __ordered_list<T> &l1, const __ordered_list<T> &l2){
    __ordered_list<T> inter_result, temp = l1;

    auto i = l2.get_first();

    for(; i != nullptr; i = i->next)
        if(!temp.Insert(i->info))
            inter_result.Insert(i->info);

    return  inter_result;
}
#endif //SORTLIST___SET_H
