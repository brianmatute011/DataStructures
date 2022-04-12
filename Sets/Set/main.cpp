#include "__set.h"
using namespace std;

int main() {
    int arr[]{3, 20, 5, 3, 1, 7, 9};
    int arr2[]{60, 7, 1, 6, 9, 5};
    __set<int>A, B;

    for (int i: arr2)
        B.Insert(i);

    for (int i: arr)
        A.Insert(i);

    cout<< "\nB: ";
    B.Show();

    cout<< "\nA: ";
    A.Show();

    cout << "\nInterseccion: ";
    A.Intersection(B).Show();

    cout << "\nUnion: ";
    A.Union(B).Show();

    cout << "\nMin de set(A): ";
    cout << A.Min();

    int del_value = 7;
    cout <<"\nBorrando valor(" << del_value <<"): ";
    A.Delete(del_value);
    A.Show();

    cout <<"\nVerificando si " << del_value <<" es Miembro de A: ";
    (A.Member(del_value))? cout <<"Existe  \n": cout <<"No existe\n";


    return 0;
}
