#include <iostream>
#include "__priority_queue.h"


template <class T>
class PriorityQueue{
    __priority_queue<T> q;

public:
    PriorityQueue() = default;
    void SuprimeMax() {q.dequeue();}    // O(log n)
    void Insert(const T &value) {q.enqueue(value);} // O(log n)
    T Top() const{ return  q.top();}
    bool Empty() const{ return q.empty();}
    PriorityQueue<T> UnionHeap(const PriorityQueue<T> & __pq);
};

template<class T>
PriorityQueue<T> PriorityQueue<T>::UnionHeap(const PriorityQueue<T> &__pq) {
    auto temp = *this;
    if (! __pq.Empty())
        temp.q = temp.q + __pq.q;
    return  temp;
}


int main() {
    int arr[] {15, 60, 72, 70, 56, 32, 62, 92, 45, 30, 65};
    int arr2[] {89, 34, 50, 90};
    PriorityQueue<int> a, b;

    for(int i: arr)
        a.Insert(i);

    for (int i: arr2)
        b.Insert(i);

    auto c = a.UnionHeap(b);

    std::cout <<"a: ";
    while(!a.Empty()){
        std::cout << "[" << a.Top() << "]";
        a.SuprimeMax();
    }

    std::cout <<"\nb: ";
    while(!b.Empty()){
        std::cout << "[" << b.Top() << "]";
        b.SuprimeMax();
    }




    std::cout <<"\nc(UnionHeaps): ";
    while(!c.Empty()){
        std::cout << "[" << c.Top() << "]";
        c.SuprimeMax();
    }







    return 0;
}