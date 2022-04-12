#include <iostream>
#include <iterator>
#include <array>
//Worst case O(n * n)
//Best case O(n);
template <class random_iterator>
void cocktail_sort(random_iterator begin, random_iterator end){
    bool no_sorted = true;
    auto start = begin,
            __end  = end - 1;
    while(no_sorted and start != __end){
        no_sorted = false;
        for(auto i = begin; i != __end; i++){
            if (*(i) > *(i + 1)){
                std::swap(*(i), *(i + 1));
                no_sorted = true;
            }
        }
        if (! no_sorted) break;
        no_sorted = false;

        __end --;
        for (auto ii = end - 1; ii != begin + 1; ii --){
            if(*(ii) < *(ii - 1)){
                std::swap(*(ii), *(ii - 1));
                no_sorted = true;
            }
        }
        start ++;
    }
}




int main() {
    std::array<int, 10> a{26, 24, 3, 17, 25, 24, 13, 60, 47, 1};
    std::cout <<"Arreglo desordenado: ";
    for (const auto &i: a)
        std::cout<< i <<" ";

    cocktail_sort(a.begin(), a.end());
    
    std::cout <<"\nArreglo despues de la clasificacion: ";
    for (const auto &i: a)
        std::cout<< i <<" ";



    return 0;
}
