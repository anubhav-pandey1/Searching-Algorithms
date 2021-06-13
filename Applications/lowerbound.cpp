#include <bits/stdc++.h>
using namespace std;

int binaryLower(vector<int>& v, int n) {
    int lo = 0, hi = v.size() - 1;
    int result = -1;
    if (n > v[hi]) {
        return -1;
    }
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (v[mid] == n) {
            result = mid;
            break;
        }
        if (v[mid] > n) {
            result = mid;
            hi = mid - 1;
        }
        else if (v[mid] < n) {
            lo = mid + 1;
        }
    }
    return result;
}

// int binaryLower(vector<int>& v, int n) {
//     int lo = 0, hi = v.size() - 1;
//     while (lo <= hi) {
//         int mid = lo + (hi - lo) / 2;
//         if (v[mid] < n) {
//             lo = mid + 1;
//         }
//         else {
//             hi = mid - 1;
//         }
//     }

//     if (lo < v.size()) {   // Do a dry run
//         return v[lo];
//     }
//     else {
//         return -1;
//     }
// }

// This implementation is already duplication-compliant
// Must add more test cases with different vectors to check

int main() {
    // vector<int> v = {4, 9, 9, 17, 21, 25, 29, 29, 35};

    // int result1 = binaryLower(v, 9);       // Test case 1
    // cout << result1 << endl;

    // int result2 = binaryLower(v, 35);      // Test case 2
    // cout << result2 << endl;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int testNum;
    cin >> testNum;
    while (testNum--) {
        int size, target;
        cin >> size;
        cin >> target;
        vector<int> v;
        for (int i = 0; i < size; i++) {
            int ele;
            cin >> ele;
            v.push_back(ele);
        }

        int result = binaryLower(v, target);
        cout << result << endl;
    }

    return 0;
}

// Test cases:-

// Inputs:
// 8
// 10
// 23
// 4 9 11 12 17 21 25 29 31 37
// 10
// 21
// 4 9 11 12 17 21 25 29 31 37
// 10
// 1
// 4 9 11 12 17 21 25 29 31 37
// 7
// 3
// 3 10 20 40 50 70 80
// 7
// 42
// 3 10 20 40 50 70 80
// 8
// 8
// 1 2 3 4 5 6 7 8
// 8
// 9
// 1 2 3 4 5 6 7 8
// 9
// 5
// 1 2 3 4 8 10 10 12 14

// Outputs (ceil/lowerbound element):
// 25
// 21
// 4
// 3
// 50
// 8
// -1
// 8

// Output (indices):
// 6
// 5
// 0
// 0
// 4
// 7
// -1
// 4
