#include <iostream>
#include <vector>


template <class _TArray>
int ternary_search(_TArray a, int low, int high, int search_key){
    if (low <= high){

        int m1 = low + (high - low) / 3;
        int m2 = high - (high - low) / 3;

        if(a[m1] == search_key)
            return m1;
        if (a[m2] == search_key)
            return m2;

        else if (search_key < a[m1])
            return  ternary_search(a, low, m1 - 1, search_key);
        else if (a[m2] < search_key)
            return  ternary_search(a, m2 + 1, high, search_key);
        else
            return  ternary_search(a, m1 + 1, m2 - 1, search_key);
    }
    return - 1;
}



int main() {

    std::vector<int> arr{3, 6, 9, 11, 50, 90};

    std::cout << arr[ternary_search(arr, 0, arr.size() - 1, 6)] <<"\n";
    return 0;
}