#include <bits/stdc++.h>
using namespace std;

int binaryLower(vector<int>& v, int n) {
    int lo = 0, hi = v.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (v[mid] < n) {
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }

    if (lo < v.size()) {
        return lo;
    }
    else {
        return -1;
    }
}

// This implementation is already duplication-compliant
// Must add more test cases with different vectors to check

int main() {
    vector<int> v = {4, 9, 9, 17, 21, 25, 29, 29, 35};

    int result1 = binaryLower(v, 9);       // Test case 1
    cout << result1 << endl;

    int result2 = binaryLower(v, 35);      // Test case 2
    cout << result2 << endl;

    return 0;
}
