#include <iostream>
#include "_stack_twoqueues.h"

/*Complejidad temporal por mÃ©todos
 * void push(const T&) -> O(n)
 * void pop() -> O(1)
 * bool empty() -> O(1)
 * T peek() -> O(1)
*/
int main(){
    char text[] {'a', 'b', 'c'};
    _stack_twoqueues<char> s;

    for(char i: text)
        s.push(i);

    while (!s.empty()){
        std::cout <<s.peek() <<"\n";
        s.pop();
    }



    return 0;
}