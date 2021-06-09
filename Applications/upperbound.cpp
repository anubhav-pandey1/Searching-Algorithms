#include <bits/stdc++.h>
using namespace std;

int binaryUpper(vector<int>& v, int n) {
    int lo = 0, hi = v.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (v[mid] > n) {
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }

    if (v[lo] == n && lo < v.size() - 1) {
        return lo + 1;
    }
    else if (v[lo] == n && lo == v.size() - 1) {
        return -1;
    }
    else if (lo < v.size()) {
        return lo;
    }
    else {
        return -1;
    }
}

int main() {
    vector<int> v = {4, 4, 9, 17, 21, 25, 29, 35, 35};

    int result1 = binaryUpper(v, 4);      // Test case 1
    cout << result1 << endl;

    int result2 = binaryUpper(v, 35);     // Test case 2
    cout << result2 << endl;

    return 0;
}
