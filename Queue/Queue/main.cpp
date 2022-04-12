#include <iostream>
#include "_queue.h"
#define jump_line  std::cout << "\n";



int main(){
    _queue<char> a;
    char  text[] = {'a', 'b', 'c', 'd'};

    for (char i: text)
        a.enqueue(i);
    //Imprimiendo la Cola
    if(!a.empty())
        a.show(); jump_line

    //Desencolando y Mostrando
    a.dequeue();
    a.show(); jump_line

    //Mostrando el retorno del primer elemento insertado
    std::cout <<a.peek()->info; jump_line

    //Mostrando un mensaje si encuentra el elemento solicitado
    if(a.onqueue('c'))
        std::cout<<"found"; jump_line
    return 0;
}