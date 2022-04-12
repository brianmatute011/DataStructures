//
// Created by user on 11/10/21.
//

#ifndef QUEUETEST___PRIORITY_QUEUE_H
#define QUEUETEST___PRIORITY_QUEUE_H
#include <vector>
template <class T>
class __priority_queue{
private:
    std::vector<T> q;

public:
    __priority_queue() = default;
    bool empty() const{ return q.empty();}
    /**
     * @brief: inserta  el elemento en la primera posicion disponible, luego restaura el heap (costo: O(log n)).
     ***/
    void enqueue(const T& value);
    /**
     * @brief: Intercambia el primer elemento con el ultimo, reduce el arreglo en 1 y luego restaura el heap (costo: O(log n));
     ***/
    bool dequeue();
    T top() const{ return q.front();}
    unsigned long size() const{ return q.size();}
    __priority_queue<T> operator+(const __priority_queue<T> &q2);
    const __priority_queue<T>& operator=(const __priority_queue<T> &q2);

private:
    void restore_heap_down();
    void restore_heap_up();
};


template<class T>
void __priority_queue<T>::enqueue(const T &value) {
    q.push_back(value);
    this->restore_heap_down();
}

template<class T>
bool __priority_queue<T>::dequeue() {
    std::swap(q[0], q[q.size() - 1]);
    q.pop_back();
    restore_heap_up();
    return true;
}

template<class T>
void __priority_queue<T>::restore_heap_down() {
    for (int i = q.size() - 1; i != 0; i = (i - 1)/2){
        if(q[(i - 1)/2] < q[i])
            std::swap(q[(i - 1)/2], q[i]);
    }
}

template<class T>
void __priority_queue<T>::restore_heap_up() {
    int itervalue = 0,
            high = q.size() -1;

    for (int i_child = itervalue * 2 + 1; i_child <= high;){
        if(i_child < high and q[i_child] < q[i_child + 1])
            i_child++;

        if(q[itervalue] < q[i_child]){
            std::swap(q[itervalue], q[i_child]);
            itervalue = i_child;
            i_child = itervalue * 2 + 1;
        } else break;
    }

}

template<class T>
__priority_queue<T> __priority_queue<T>::operator+(const __priority_queue<T> &q2) {
    auto qtemp = *this;
    if(!q2.empty()){
        for(const auto &value: q2.q)
            qtemp.enqueue(value);
    }
    return qtemp;
}

template<class T>
const __priority_queue<T> &__priority_queue<T>::operator=(const __priority_queue<T> &q2) {
    if(this != &q2)
        this->q = q2.q;
    return *this;
}

#endif //QUEUETEST___PRIORITY_QUEUE_H
