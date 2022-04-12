#include <iostream>
#include "_rstack.h"
#define jump_line  std::cout << "\n";



int main(){
    //Definiendo  <tipo de datos, capacidad maxima>
    _rstack<char, 9> a;
    char text[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'x', 'x', 'x'};

    //Insertando los elementos en la Pila
    for (char i : text)
        a.push(i);

    //Mostrando los elementos de la Pila si no esta vacia
    if (!a.empty())
        a.show();
    jump_line


    //Eliminando un elemento de la Pila y Mostrandola
    if (a.pop())
        a.show();
    jump_line;


    //Devolviendo el ultimo elemento insertado en la Pila
    std::cout<< a.peek()->info; jump_line

    //Mostrando la Capacidad maxima que tiene la Pila
    std::cout << a.capacity(); jump_line

    //Mostrando la cantidad de elementos que tiene la Pila
    std::cout<< a.count(); jump_line


    return 0;
}