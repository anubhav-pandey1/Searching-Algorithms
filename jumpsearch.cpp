#include <bits/stdc++.h>
using namespace std;

int jumpSearch(vector<int>& v, int K) {            // Optimal time complexity is O(sqrt(n)), works for sorted arrays only
    int step = sqrt(v.size());                     // Sqrt(n) is the most optimal step size, as proved by finding minima
    int lo = 0;                                    // Lo and Hi pointers to outline the range identified by the jumping
    int hi = step;
    while (hi < v.size()) {                        // Finding the block where the target is - while hi is in bounds of the array
        if (K > v[hi]) {                           // If target lies beyond the Hi pointer, we must jump to a different range
            lo += step;
            hi += step;
        }
        else if (K <= v[hi] &&  K >= v[lo]) {      // If target lies in between [lo, hi], then break out of the loop
            break;
        }
    }

    for (int i = lo; i <= hi; i++) {               // Linear search for target in the range [lo, hi]
        if (v[i] == K) {
            return i;
        }
    }
    return -1;                                     // If not found in the range, return -1 to signify element not found
}

int main() {
    // vector<int> v = {1, 1, 1, 1, 2, 2, 2, 2};
    vector<int> v = {4, 9, 17, 21, 29, 25, 32, 35, 39, 43, 47, 51, 57, 63, 67, 71}; // Size == 16
    // sort(v.begin(), v.end());                  // Jump
    int result = jumpSearch(v, 4);

    cout << ((result != -1) ? "true" : "false") << endl;
    cout << result << endl;

    return 0;
}
