#include <bits/stdc++.h>
using namespace std;

int infiniteBoolSearch(vector<int>& v) {       // Similar to finding first occurence
	int lo = 0, hi = 1;
	while (v[hi] != 1) {
		lo = hi;
		hi *= 2;
	}

	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if (v[mid] == 1) {
			if (v[mid - 1] != 1 && mid != 0) {
				return mid;
			}
			else {
				hi = mid - 1;
			}
		}
		else if (v[mid] == 0) {
			lo = mid + 1;
		}
	}
	return -1;
}

int main() {
	return 0;
}
