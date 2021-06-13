#include <bits/stdc++.h>
using namespace std;

char nextLetter(vector<char>& v, char input) {  // Basically the same algorithm as lowerbound()
    char c = tolower(input, locale());          // Convert char to lowercase
    int lo = 0, hi = v.size() - 1;
    char result;
    if (c >= v[hi]) {                           // Since last element will have no next element
        return '-';
    }
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (v[mid] == c && mid != v.size() - 1) {
            result = v[mid + 1];                // Since we have to return next character
            break;
        }
        else if (v[mid] > c) {
            result = v[mid];
            hi = mid - 1;
        }
        else if (v[mid] < c) {
            lo = mid + 1;
        }
    }
    return result;
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
        char target;
        cin >> size;
        cin >> target;
        vector<char> v;
        for (int i = 0; i < size; i++) {
            char ele;
            cin >> ele;
            v.push_back(ele);
        }

        auto result = nextLetter(v, target); // Can return indices too
        cout << result << endl;
    }

    return 0;
}

// Test cases:-

// Input:
// 5
// 4
// a
// a c f h
// 4
// C
// a c f h
// 4
// g
// a c f h
// 4
// h
// a c f h
// 4
// q
// a c f h

// Output:
// c
// f
// h
// -
// -
