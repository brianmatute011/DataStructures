//
// Created by br14n on 12/4/22.
//

#ifndef QUEUETWOSTACKS__QUEUE_TWOSTACKS_H
#define QUEUETWOSTACKS__QUEUE_TWOSTACKS_H
#include "_stack.h"
//2- Show how to implement a queue using two stacks. Analyze the running time of the queue operations.

template <class  T>
class _queue_twostacks{
private:
    _stack<T> stack1, stack2;
public:
    _queue_twostacks() = default;
    void enqueue (const T& value);
    bool empty() { return  stack1.empty();}
    bool dequeue () { return stack1.pop();};
    T peek() { return stack1.peek();}
};

template<class T>
void _queue_twostacks<T>::enqueue(const T &value) {
    while(!stack1.empty()){ stack2.push(stack1.peek());
        stack1.pop();
    }

    stack1.push(value);

    while(!stack2.empty()){ stack1.push(stack2.peek());
        stack2.pop();
    }
}
#endif //QUEUETWOSTACKS__QUEUE_TWOSTACKS_H
