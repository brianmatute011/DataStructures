#include <iostream>
#include "_bs_tree.h"

int main() {
    _bs_tree<int>A;
    int arr[]{60, 50, 70, 30, 58, 69, 80, 46, 77, 90};
    for (int i : arr)
        A.insert(i);

    A.print_inorder();



    std::cout <<"\n" <<A.leftchild(70)->info;
    std::cout <<"\n" <<A.rightchild(70)->info;
    std::cout <<"\n" <<A.parent(80)->info;
    
    int a = 800;
    (A.__NULL(a))?
        std::cout <<"\n" <<a <<" Es Nulo \n":
            std::cout <<a << "No es Nulo"; 

    return 0;
}