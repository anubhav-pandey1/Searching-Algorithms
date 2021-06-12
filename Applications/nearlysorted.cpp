#include <bits/stdc++.h>
using namespace std;

int binarySearchK(vector<int>& v, int n) {
    int lo = 0, hi = v.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (v[mid] == n) {                          // N can be at i, i - 1, i + 1
            return mid;
        }
        if (v[mid + 1] == n && (mid + 1) <= hi) {
            return mid + 1;
        }
        if (v[mid - 1] == n && (mid - 1) >= lo) {
            return mid - 1;
        }

        if (n > v[mid]) {                           // Search space reduction - D&C
            lo = mid + 2;
        }
        else {
            hi = mid - 2;
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
        int size, target;
        cin >> size;
        cin >> target;
        vector<int> v;
        for (int i = 0; i < size; i++) {
            int ele;
            cin >> ele;
            v.push_back(ele);
        }

        int result = binarySearchK(v, target);
        cout << result << endl;
    }

    return 0;
}

// My implementation of the algorithm: It works

// Keep going as if everything is normal unless you encounter a swap

// int binarySearchK(vector<int>& v, int n) {
//     int lo = 0, hi = v.size() - 1;
//     while (lo <= hi) {
//         int mid = lo + (hi - lo) / 2;
//         int next = mid + 1, prev = mid - 1;
//         if (v[mid] == n) {
//             return mid;
//         }
//         else if (v[next] >= v[mid] && v[prev] <= v[mid]) { // Everything is normal
//             if (n > v[mid]) {
//                 lo = next;
//             }
//             else if (n < v[mid]) {
//                 hi = prev;
//             }
//         }
//         else {
//             if (v[next] != n && v[prev] != n) { // Everything is practically normal
//                 if (n > v[mid]) {
//                     lo = next;
//                 }
//                 else if (n < v[mid]) {
//                     hi = prev;
//                 }
//             }
//             else if (v[next] == n) { // next has the target instead of mid (swap)
//                 return next;
//             }
//             else if (v[prev] == n) { // prev has the target instead of mid (swap)
//                 return prev;
//             }
//         }
//     }
//     return -1;
// }
