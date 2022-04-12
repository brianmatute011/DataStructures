#include <iostream>
#include "_list.h"

int main() {
    _list<char>a;
    char text[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};

    //insertamos todos los elementos de text
    for(char i : text)
        a.insert_back(i);


    //Mostrando elementos si no esta vacio
    if (!a.empty())
        a.show();
    std::cout<<"\n";
    //Si existe la posicion la eliminamos
    if(a.remove(3))
        a.show();
    std::cout<<"\n";

    //Insertando elemento en una posicion solicitada
    a.insert('z', 6);
    a.show();
    std::cout<< " \n";

    //Imprimiendo elemento de la posicion dada
    std::cout <<a.element(4)->info <<"\n";

    //Imprimiendo cantidad de elemntos
    std::cout << a.count() << "\n";

    //Invirtiendo la lista;
    a.invest();
    a.show();

    return 0;
}