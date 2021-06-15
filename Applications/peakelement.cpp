#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int>& v) { // Improve
    if (v.size() < 2) {  // For small arrays (missed it)
        return 0;
    }
    int lo = 0, hi = v.size() - 1;
    if (v[lo] > v[lo + 1]) {
        return lo;
    }
    if (v[hi] > v[hi - 1]) {
        return hi;
    }

    while (lo <= hi) {
        int m = lo + (hi - lo) / 2;
        if (m > 0 && m < v.size() - 1) { // Must be before else m - 1 not defined, missed
            if (v[m] > v[m + 1] && v[m] > v[m - 1]) {
                return m;
            }
            else if (v[m - 1] >= v[m + 1] && m > 0) {  // Missed equality case
                hi = m - 1;
            }
            else if (v[m - 1] < v[m + 1] && m > 0) {
                lo = m + 1;
            }
        }
        else if (m == 0) {        // Must be handled explicitly, missed
            return 1;
        }
        else if (m == v.size() - 1) {
            return v.size() - 2;
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int testNum;
    cin >> testNum;
    while (testNum--) {
        int size;
        cin >> size;
        vector<int> v;
        for (int i = 0; i < size; i++) {
            int ele;
            cin >> ele;
            v.push_back(ele);
        }

        int result = findPeakElement(v);
        cout << result << endl;
    }

    return 0;
}

// My initial, inconcise code:-

// int findPeakElement(vector<int>& v) { // Improve
//     if (v.size() < 2) {  // For small arrays (missed it)
//         return 0;
//     }
//     int lo = 0, hi = v.size() - 1;
//     if (v[lo] > v[lo + 1]) {
//         return lo;
//     }
//     if (v[hi] > v[hi - 1]) {
//         return hi;
//     }

//     while (lo <= hi) {
//         int m = lo + (hi - lo) / 2;
//         if (m > 0 && m < v.size() - 1) { // Must be before else m - 1 not defined, missed
//             if (v[m] > v[m + 1] && v[m] > v[m - 1]) {
//                 return m;
//             }
//             else if (v[m - 1] >= v[m + 1] && m > 0) {  // Missed equality case
//                 hi = m - 1;
//             }
//             else if (v[m - 1] < v[m + 1] && m > 0) {
//                 lo = m + 1;
//             }
//         }
//         else if (m == 0) {        // Must be handled explicitly, missed
//             return 1;
//         }
//         else if (m == v.size() - 1) {
//             return v.size() - 2;
//         }
//     }

//     return -1;
// }

// Test cases:-

// Inputs:

// 8
// 6
// 5 10 20 19 16 6
// 6
// 5 10 20 18 21 17
// 7
// 5 8 10 15 19 26 20
// 7
// 10 20 15 2 23 90 67
// 4
// 1 2 3 1
// 7
// 1 2 1 3 5 6 4
// 5
// 3 4 3 2 1
// 5
// 1 2 3 4 3
// 5
// 1 2 1 2 1

// Outputs (can have other outputs too):

// 2
// 2
// 5
// 5
// 2
// 5
// 1
// 3
// 2
