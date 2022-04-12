#include <iostream>
#include "_queue_twostacks.h"

/**Analisis de Complejidad
 * void enqueue (const T& value) -> O(n)
 * bool empty () -> O(1)
 * bool dequeue () -> O(1)
**/


int main(){
    char a [4]{'a', 'b', 'c', 'd'};
    _queue_twostacks<char> Q;

    for (char i: a)
        Q.enqueue(i);

    while(!Q.empty()){
        std::cout << Q.peek() <<"\n";
        Q.dequeue();
    }


    return 0;
}