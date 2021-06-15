#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int>& v) { // Helper 1 - helps find the peak element
    int lo = 0, hi = v.size() - 1;
    while (lo < hi) {
        int m = lo + (hi - lo) / 2;
        if (v[m + 1] > v[m]) {
            lo = m + 1;
        }
        else {
            hi = m;
        }
    }
    return lo;
}

int firstBinarySearchAsc(vector<int>&v, int n, int start, int end) { // Helper 2
    int lo = start, hi = end + 1;                                    // Helps find first occurrence in ascending array
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (v[mid] < n) {
            lo = mid + 1;
        }
        else {
            hi = mid;
        }
    }
    if (lo < end + 1 && v[lo] == n) {
        return lo;
    }
    else {
        return -1;
    }
}

int firstBinarySearchDesc(vector<int>&v, int n, int start, int end) { // Helper 3
    int lo = start, hi = end + 1;                                     // Helps find first occurrence in descending array
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (v[mid] > n) {
            lo = mid + 1;
        }
        else {
            hi = mid;
        }
    }
    if (lo < end + 1 && lo >= start && v[lo] == n) {
        return lo;
    }
    else {
        return -1;
    }
}

int findInMountainArray(vector<int>& v, int target) {
    int peak = findPeakElement(v);                                            // Find peak element - Helper 1
    int result1 = firstBinarySearchAsc(v, target, 0, peak);                   // Search from start to peak - Helper 2
    int result2 = firstBinarySearchDesc(v, target, peak + 1, v.size() - 1);   // Search from peak to end - Helper 3
    return (result1 >= 0 ? result1 : result2);                                // If ans is not -1, return it
}                                                                             // else return -1

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
        int target;
        cin >> size;
        cin >> target;
        vector<int> v;
        for (int i = 0; i < size; i++) {
            int ele;
            cin >> ele;
            v.push_back(ele);
        }

        int result = findInMountainArray(v, target);
        cout << result << endl;
    }

    return 0;
}

// Test cases:

// Inputs:

// 4
// 7
// 3
// 1 2 3 4 5 3 1
// 6
// 3
// 0 1 2 4 2 1
// 7
// 4
// 2 3 4 5 7 4 2
// 7
// 5
// 1 2 3 4 6 6 5

// Outputs (multiple possible in case of duplicates):

// 2
// -1
// 2
// 6
