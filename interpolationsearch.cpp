#include <iostream>
#include <vector>
using namespace std;

int interpolationSearch(vector<int>& v, int K) {
    int lo = 0;
    int hi = v.size() - 1;
    while (lo < hi) {
        int loc = lo + (((K - v[lo]) * (hi - lo)) / (v[hi] - v[lo])); // Similar to binary search, but speeds up to O(1) if elements make a straight line
        if (v[loc] == K) {
            return loc;
        }
        else if (K > v[loc]) {
            lo = loc + 1;
        }
        else if (K < v[loc]) {
            hi = loc - 1;
        }
    }
    return -1;
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
