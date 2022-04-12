//
// Created by br14n on 12/4/22.
//

#ifndef STACK_TWOQUEUES__STACK_TWOQUEUES_H
#define STACK_TWOQUEUES__STACK_TWOQUEUES_H
#include "_queue.h"

template <class T>
class _stack_twoqueues{
private:
    _queue<T> queue1, queue2;
    int s_size{};
public:
    _stack_twoqueues() = default;
    void push(const T&);
    void pop();
    bool empty() { return  queue1.empty();}
    T peek()  { return (!queue1.empty())? queue1.front(): -1;}
};

template<class T>
void _stack_twoqueues<T>::push(const T &_value) {
    //Encolar valor en queue2
    queue2.enqueue(_value);
    //Migrar todos los valores de queue1 a queue2
    while(!queue1.empty()){
        queue2.enqueue(queue1.front());
        queue1.dequeue();
    }
    //Intercambiar queue1 con queue2
    queue1.swap(queue2);
    ++s_size;
}

template<class T>
void _stack_twoqueues<T>::pop() {
    if(!queue1.empty()){
        queue1.dequeue();
        --s_size;
    }
}


#endif //STACK_TWOQUEUES__STACK_TWOQUEUES_H
