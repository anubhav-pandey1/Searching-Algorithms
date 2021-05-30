#include <iostream>
#include <vector>
using namespace std;

bool binarySearchIter(vector<int>& v, int n) {       // This is for an ascending order sorted array. Flip signs for descending order sorted
    int start = 0, end = v.size() - 1;               // Keeping track of the range of the subarray for the search using two pointers
    while (start <= end) {                           // While the subarray is a valid subarray, keep doing the following..
        int mid = start + (end - start)/2;           // Must use this as (start+end)/2 might overflow integer limits if close to INT_MAX
        if (v[mid] == n) {                           // Element found! In BinarySearchIterative, element is only found at this step
            return true;                             // We can return mid as well if we need the index of the found element
        }
        else if (n < v[mid]) {                       // If the element is smaller than the middle element of the current subarray
            end = mid - 1;                           // Re-adjust the subarray to exclude the mid element and elements after mid
        }                                            // Due to the while loop, keep looking in the newly formed subarray from start->(mid-1)
        else if (n > v[mid]) {                       // If the element is larger than the middle element of the current subarray
            start = mid + 1;                         // Re-adjust the subarray to exclude the mid element and the elements before mid
        }                                            // Due to the while loop, keep looking in the newly formed subarray from (mid+1)->end
    }                                                // Either end decreases and becomes less than start or start becomes larger than end
    return false;                                    // If not found in the vector, return false. Can return -1 to signify no index found
}

bool binarySearchRec(vector<int>& v, int n, int start, int end) {
    if (start > end) {                               // Base case 1: When start goes up higher than end, or end goes down lower than start
        return false;                                // Return false if base case 1 is hit ie. none of the nodes of the recursion tree find n
    }                                                // We can also return -1 or index of the found element instead of a boolean

    int mid = start + (end - start)/2;               // If base case 1 is not hit, find mid to kick start binary search
    if (v[mid] == n) {                               // Base case 2: If mid element is equal to n, then this is base case 2
        return true;                                 // Return true if base case 2 is hit ie. this is the main searching step
    }
    else if (n < v[mid]) {                           // Else if n is less than the middle element, then conduct new binary search
        return binarySearchRec(v, n, start, end-1);  // New binary search in the range start -> )end - 1)
    }
    else if (n > v[mid]) {                           // Otherwise if n is greater than the middle element, conduct new binary search
        return binarySearchRec(v, n, mid+1, end);    // New binary search in the range (mid + 1) -> start
    }
    return false;                                    // If nothing returns anything, return false to avoid -Wreturn type warning as..
}                                                    // if nothing returns anything, n has not been found in the vector

int main() {
    vector<int> v = {4, 9, 17, 21, 25, 29, 32, 35};

    bool result1 = binarySearchIter(v, 32);          // Test cas 1 - for iterative binary search
    cout << ((result1) ? "true" : "false") << endl;

    bool result2 = binarySearchRec(v, 10, 0, 7);     // Test case 2 - for recursive binary search
    cout << ((result2) ? "true" : "false") << endl;

    return 0;
}
