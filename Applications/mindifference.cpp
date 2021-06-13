#include <bits/stdc++.h>
using namespace std;

int binarySearchDiff(vector<int>& v, int n) {  // Can be done by finding floor and ceil
	int diff = INT_MAX, idx = -1;              // This can also be used to find floor and ceil
	int lo = 0, hi = v.size() - 1;             // diff <= 0 for floor and diff >= 0 for ceil
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		int temp = abs(v[mid] - n);            // Bookkeeping for maintaining abs difference
		if (temp < diff) {                     // Update books if diff is lower than before
			diff = temp;
			idx = mid;
		}

		if (v[mid] > n) {                      // Search space reduction as usual
			hi = mid - 1;
		}
		else if (v[mid] < n) {
			lo = mid + 1;
		}
		else if (v[mid] == n) {                // Once you encounter n, diff can't go lower
			break;
		}
	}
	return idx;
}

// Alt. approach:- min(abs(mid - n), min(abs(lo - n), abs(hi - n))) after running regular BS
// Running a regular binary search ends with low and high being equal to the neighbours of target
// If target is present, regular BS returns the target ie. diff = 0. Otherwise, lo and hi point
// to the ceil and floor for the particular target (can be used to find ceil and floor)

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

		int result = binarySearchDiff(v, target);
		cout << result << endl;
	}

	return 0;
}


// Test cases:-

// Input:

// 7
// 9
// 25
// 4 9 11 12 17 21 25 25 31
// 9
// 4
// 4 9 11 12 17 21 25 25 31
// 9
// 31
// 4 9 11 12 17 21 25 25 31
// 9
// 16
// 4 9 11 12 17 21 25 25 31
// 9
// 15
// 4 9 11 13 17 21 25 25 31
// 9
// 1
// 4 9 11 12 17 21 25 25 31
// 9
// 33
// 4 9 11 12 17 21 25 25 31

// Output:

// 6
// 0
// 8
// 4
// 4
// 0
// 8
