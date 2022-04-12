#include <iostream>
#include <vector>
#include <algorithm>


std::vector<int> counting_sort(const std::vector<int> &a) {
    std::vector<int> c(*max_element(a.begin(), a.end()) + 1); //let c[0...k] be new array; k = max_element(a);
    std::vector<int> b(a.size()); //let b[0...a.length] be new array

    for (const int &i: a)
        c[i]++;

    for (int k = 1; k < c.size(); k++)
        c[k] = c[k] + c[k - 1];

    for (int j = int(a.size() - 1); j >= 0; j--){
        b[c[a[j]] - 1] = a[j];
        c[a[j]]--;
    }
    return b;

}

int main() {
    std::vector<int> arr{6, 0, 2, 0, 1, 3, 4, 6, 1, 3, 2};

    for (const auto &i: counting_sort(arr))
        std::cout <<i <<" ";



}