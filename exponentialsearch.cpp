#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& v, int K, int start, int end) {
    int lo = start, hi = end;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (v[mid] == K) {
            return mid;
        }
        else if (v[mid] > K) {
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }
    return -1;
}

int exponentialSearch(vector<int>& v, int K) {
    int n = v.size();
    if (v[0] == K) {                                   // Must check the 0'th element as it can't be covered in exp. jumps
        return 0;
    }

    int i = 1;                                         // Exponential jumps to find range indices for K in O(logN)
    while (v[i] <= K) {                                // i will be just greater than or equal to the index for K
        i *= 2;                                        // i can go out of bounds as well, so high == min(i, last index)
    }                                                  // i/2 is definitely lower than the index for K, so low == i/2

    return binarySearch(v, K, i / 2, min(i, n - 1));   // Binary search between the low and high range indices for K in O(logN)
}

int main() {
    // vector<int> v = {1, 1, 1, 1, 2, 2, 2, 2};
    // vector<int> v = {4, 9, 17, 21, 25, 29, 32, 35, 39, 43, 47, 51, 57, 63, 67, 71}; // Size == 16
    vector<int> v = {4, 4, 17, 21, 25, 29, 35, 35, 39, 43, 47, 51, 57, 63, 71, 71}; // Duplication at beginning, middle and end

    int result = exponentialSearch(v, 123);

    cout << ((result != -1) ? "true" : "false") << endl;
    cout << result << endl;

    return 0;
}
