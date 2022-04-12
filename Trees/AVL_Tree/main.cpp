#include <iostream>
#include <stack>
#include "avl_btree.h"
#include <vector>

template <class T>
void show_insert_tree(avl_btree<T> &__A, std::stack<char> &__s, std::vector<char> &__arr ){
    std::cout<<"\nInsert:\n";
    for (char i : __arr){
        __s.push(i);
        __A.insert(i);
        std::cout<< "insert(" <<int(i) <<" or " <<i <<"): ";
        __A.print_inorder();
        std::cout <<"root: "  <<__A.root->info <<"\n";
    }
}

template <class T>
void show_delete_lifoorder(avl_btree<T> &__A, std::stack<char> &__s){
    __A.print_inorder();
    std::cout<<"\nDelete:\n";
    while(!__s.empty()){
        std::cout <<"delete(" <<int(__s.top()) <<" or " <<__s.top() <<"): ";
        std::cout <<" root: "  <<__A.root->info <<"\n";
        __A._delete(__s.top());
        __s.pop();
        __A.print_inorder();
    }
}


int main() {
    std::vector<std::vector<char>>container{
        {'A', 'Z', 'B', 'Y', 'C', 'X'},
        {'A', 'B', 'C', 'D', 'E', 'F'},
        {'M', 'T', 'E', 'A', 'Z', 'G', 'P'},
        {'A', 'Z', 'B', 'Y', 'C', 'X', 'D', 'W', 'E', 'V', 'F'},
        {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L'},
        {'A', 'V', 'L', 'T', 'R', 'E', 'I', 'S', 'O', 'K'}
        };
    std::stack<char> s;
    avl_btree<int> A;

    for(auto & i : container){
        show_insert_tree(A, s, i);
        std::cout<<"Height: " <<A.height() <<"\n";
        std::cout<<"Leftmost leaf: " <<A.lmost_leaf()->info <<"\n";
        show_delete_lifoorder(A, s);
        std::cout <<"\n-------------";
    }

    return 0;
}
