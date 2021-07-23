#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& v, int K, int lo, int hi) {

}

int exponentialSearch(vector<int>& v, int K) {

}

int main() {
    // vector<int> v = {1, 1, 1, 1, 2, 2, 2, 2};
    // vector<int> v = {4, 9, 17, 21, 25, 29, 32, 35, 39, 43, 47, 51, 57, 63, 67, 71}; // Size == 16
    vector<int> v = {4, 4, 17, 21, 25, 29, 35, 35, 39, 43, 47, 51, 57, 63, 71, 71}; // Duplication at beginning, middle and end

    int result = interpolationSearch(v, 35);

    cout << ((result != -1) ? "true" : "false") << endl;
    cout << result << endl;

    return 0;
}
