#include <iostream>
#include <vector>
using namespace std;

bool linearSearch(vector<int>& v, int n) {
    for (int& elem : v) {
        if (elem == n) {
            return true;
        }
    }
    return false;
}

int main() {
    // vector<int> v = {1, 1, 1, 1, 2, 2, 2, 2};
    vector<int> v = {17, 21, 29, 35, 4, 9, 25, 32};

    bool result = linearSearch(v, 27);

    cout << ((result) ? "true" : "false") << endl;

    return 0;
}
