#include <bits/stdc++.h>
using namespace std;

int binarySearchFloor(vector<int>& v, int n) {
	int lo = 0, hi = v.size() - 1;
	int result = -1;
	if (n < v[lo]) {
		return -1;
	}
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if (v[mid] == n) {          // If any element == target, then it must be the floor
			result = mid;             // If we are returning indices, we might want to return the first occurence
			break;
		}
		if (v[mid] < n) {           // If we encounter any element less than the target, we update result
			result = mid;             // We then look towards the right of that element to find greater elements
			lo = mid + 1;
		}
		else if (v[mid] > n) {      // Search space reduction based on the condition
			hi = mid - 1;
		}
	}
	return v[result];
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

		int result = binarySearchFloor(v, target);
		cout << result << endl;
	}

	return 0;
}

// My first, explicit implementation: Do a dry run

// int binarySearchFloor(vector<int>& v, int n) {
// 	int lo = 0, hi = v.size() - 1;
// 	int result = -1;
// 	while (lo < hi) {
// 		int mid = lo + (hi - lo) / 2;
// 		if (v[mid] == n) {
// 			result = mid;
// 			break;
// 		}
// 		else if (v[mid] < n) {
// 			lo = mid + 1;
// 		}
// 		else {
// 			hi = mid - 1;
// 		}
// 	}

// 	if (v[result] == n && result != -1) {
// 		return result;
// 	}
// 	else if (v[lo] > n) {
// 		return lo - 1;
// 	}
// 	else if (v[lo] <= n) {
// 		return lo;
// 	}
// 	else {
// 		return -1;
// 	}
// }

// Improved implementation: Do a dry run

// int binarySearchFloor(vector<int>& v, int n) {
// 	int lo = 0, hi = v.size() - 1;
// 	while (lo < hi) {
// 		int mid = lo + (hi - lo) / 2;
// 		if (v[mid] < n) {
// 			lo = mid + 1;
// 		}
// 		else {
// 			hi = mid - 1;
// 		}
// 	}

// 	if (v[lo] > n && lo > 0) {
// 		return v[lo - 1];
// 	}
// 	else if (v[lo] <= n) {
// 		return v[lo];
// 	}
// 	else {
// 		return -1;
// 	}
// }


// Test Cases:-
//Inputs:

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

// Outputs (indices of floor):
// 5
// 5
// -1
// 0
// 3
// 7
// 3

// Outputs (floor):

// 21
// 21
// -1
// 3
// 40
// 8
// 8
// 4
