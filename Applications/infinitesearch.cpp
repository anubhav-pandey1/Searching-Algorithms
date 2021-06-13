#include <bits/stdc++.h>
using namespace std;

int infiniteSearch(vector<int>& v, int n) {
	int lo = 0, hi = 1;
	while (v[hi] <= n) {               // Find the correct hi which is greater than n
		if (v[hi] < n) {                 // This is O(logN) since we are doubling hi
			lo = hi;                       // Lo is the last value of hi, which was less than n
			hi *= 2;                       // Knuth Sequence can also be used
		}
		else if (v[hi] == n) {
			return hi;
		}
	}

	while (lo <= hi) {                 // Regular binary search between lo and hi
		int mid = lo + (hi - lo) / 2;    // This is also O(logN)
		if (v[mid] == n) {
			return mid;
		}
		if (v[mid] > n) {
			hi = mid - 1;
		}
		else if (v[mid] < n) {
			lo = mid + 1;
		}
	}
	return -1;
}

int main() {
	return 0;
}
