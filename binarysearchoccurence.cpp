#include <iostream>
#include <vector>
using namespace std;

int binarySearchFirst(vector<int>& v, int n) {
    int start = 0, end = v.size() - 1;
    while (start <= end) {
        int mid = start + (end - start)/2;
        if (v[mid] == n) {
            if (v[mid-1] != n) {
                return mid;
            }
            else {
                end = mid - 1;
            }
        }
        else if (n < v[mid]) {
            end = mid - 1;
        }
        else if (n > v[mid]) {
            start = mid + 1;
        }
    }
    return -1;
}

int binarySearchLast(vector<int>& v, int n) {
    int start = 0, end = v.size() - 1;
    while (start <= end) {
        int mid = start + (end - start)/2;
        if (v[mid] == n) {
            if (v[mid+1] != n) {
                return mid;
            }
            else {
                start = mid + 1;
            }
        }
        else if (n < v[mid]) {
            end = mid - 1;
        }
        else if (n > v[mid]) {
            start = mid + 1;
        }
    }
    return -1;
}

int main() {
    vector<int> v = {4, 9, 17, 21, 29, 32, 32, 32};

    int result1 = binarySearchFirst(v, 32);
    cout << result1 << endl;

    int result2 = binarySearchLast(v, 32);
    cout << result2 << endl;

    return 0;
}
