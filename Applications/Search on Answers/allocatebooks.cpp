#include <bits/stdc++.h>
using namespace std;

// bool check(const vector<int>& v, int K, int mid) {
// 	int sum = 0;
// 	int count = 1;
// 	for (int i = 0; i < v.size(); i++) {
// 		if (sum + v[i] <= mid) {                  // Operations inside if () are slower
// 			sum += v[i];
// 		}
// 		else {                                    // This branch can be eliminated
// 			sum = v[i];
// 			count++;
// 		}
// 		if (count > K) {
// 			return false;
// 		}
// 	}
// 	return true;
// }

bool check(const vector<int>& v, int K, int mid) { // Branchless functions are better
	int sum = 0;                                   // Compare with other two predicates
	int count = 1;
	for (int i = 0; i < v.size(); i++) {
		sum += v[i];                               // Add to sum beforehand only
		if (sum > mid) {                           // If sum goes higher than mid, we can reset
			sum = v[i];                            // Reset sum
			count++;                               // Increase count of students
		}
		if (count > K) {                           // Checking inside loop only if count > K
			return false;                          // Return false as soon as count goes higher
		}
	}
	return true;                                   // If count does not go higher, return true
}

int allocateBooks(const vector<int>& books, int K) {
	if (books.size() < K) {
		return -1;
	}
	int lo = *max_element(books.begin(), books.end());
	int hi = accumulate(books.begin(), books.end(), 0);
	int result = -1;
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		// cout << lo << " " << mid << " " << hi << ", " << result << endl;
		if (check(books, K, mid)) {
			result = mid;
			hi = mid - 1;
		}
		else {
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

// My initial almost-optimal approach:-
// Need to change hi to mid - 1 and lo to mid + 1 to optimise binary search
// No need to use prev_lo and prev_hi if we make the change given above
// Predicate check() can be optimized by not using a vector and returing false ASAP

// bool check(const vector<int>& v, int K, int mid) {
// 	vector<int> parts = {0};
// 	for (int i = 0; i < v.size(); i++) {
// 		int len = parts.size();
// 		if (parts[len - 1] + v[i] <= mid) {
// 			parts[len - 1] += v[i];
// 		}
// 		else {
// 			parts.push_back(v[i]);
// 		}
// 	}

// 	if (parts.size() <= K) {
// 		return true;
// 	}
// 	else {
// 		return false;
// 	}
// }

// int allocateBooks(const vector<int>& books, int K) {
// 	if (books.size() < K) {
// 		return -1;
// 	}
// 	int lo = *max_element(books.begin(), books.end());
// 	int hi = accumulate(books.begin(), books.end(), 0);
// 	int prev_lo, prev_hi;
// 	int result = -1;
// 	while (prev_lo != lo || prev_hi != hi) {
// 		int mid = lo + (hi - lo) / 2;
// 		prev_lo = lo, prev_hi = hi;
// 		// cout << lo << " " << mid << " " << hi << endl;
// 		if (check(books, K, mid)) {
// 			result = mid;
// 			hi = mid;
// 		}
// 		else {
// 			lo = mid;
// 		}
// 	}
// 	return result;
// }

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
