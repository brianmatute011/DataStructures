#include <iostream>
#include "_stack.h"
#define jump_line  std::cout << "\n";




int main(){
    _stack<char>a;
    char text[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};

    //Insertando elementos a la pila
    for (char i: text)
        a.push(i);


    //Mostrando elementos
    a.show();jump_line

    //Eliminando el ultimo elemento insertado
    a.pop();
    a.show();jump_line

    //Imprimendo el ultimo elemento insertado en la pila
    std::cout <<a.peek() ->info; jump_line;

    return 0;
}