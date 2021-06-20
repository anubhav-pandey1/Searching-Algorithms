#include <bits/stdc++.h>
using namespace std;

bool check(const vector<int>& v, int K, int mid) {
	vector<int> parts = {0};
	for (int i = 0; i < v.size(); i++) {
		int len = parts.size();
		if (parts[len - 1] + v[i] <= mid) {
			parts[len - 1] += v[i];
		}
		else {
			parts.push_back(v[i]);
		}
	}

	if (parts.size() <= K) {
		return true;
	}
	else {
		return false;
	}
}

int allocateBooks(const vector<int>& books, int K) {
	int lo = *max_element(books.begin(), books.end());
	int hi = accumulate(books.begin(), books.end(), 0);
	int prev_lo, prev_hi;
	int result;
	while (prev_lo != lo || prev_hi != hi) {
		int mid = lo + (hi - lo) / 2;
		prev_lo = lo, prev_hi = hi;
		// cout << lo << " " << mid << " " << hi << endl;
		if (check(books, K, mid)) {
			result = mid;
			hi = mid;
		}
		else {
			lo = mid;
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
		int numStudents;
		cin >> size;
		cin >> numStudents;
		vector<int> v;
		for (int i = 0; i < size; i++) {
			int ele;
			cin >> ele;
			v.push_back(ele);
		}

		int res = allocateBooks(v, numStudents);
		cout << res << endl;
	}
	return 0;
}

// Testcases:-

// Inputs:

// 8
// 4
// 2
// 12 34 67 90
// 10
// 4
// 1 2 3 4 5 6 7 8 9 10
// 5
// 3
// 10 20 30 40 50
// 4
// 3
// 1 96 98 99
// 10
// 4
// 1 3 6 10 15 21 28 36 45 55
// 5
// 2
// 5 7 10 98 195
// 6
// 4
// 5 10 14 25 30 40
// 6
// 3
// 5 10 15 25 30 40

// Outputs:

// 113
// 17
// 60
// 99
// 64
// 195
// 40
// 55
