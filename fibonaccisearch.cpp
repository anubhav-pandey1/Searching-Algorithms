#include <iostream>
#include <vector>
using namespace std;

int fibonacciNumber(int index) {                           // Returns fib(m) (fib at index m), iterative implementation
    if (index == 0 || index == 1) {                        // Base case, not covered by iterations
        return index;
    }

    int fibM2 = 0;
    int fibM1 = 1;
    int fibM = fibM2 + fibM1;

    int iteration = 2;                                     // Since fib(0), fib(1) and fib(2) have already been covered
    while (iteration < index) {
        fibM2 = fibM1;
        fibM1 = fibM;
        fibM = fibM2 + fibM1;
        iteration++;
    }

    return fibM;                                           // fibM == 2 if index is less than 2 since iteration initiated equal to 2
}

int fibonacciSearch(vector<int>& v, int K) {
    int size = v.size();
    int m = 0;
    while (fibonacciNumber(m) < size) {                    // Part 1: Finding the min. index in Fib series for which fib(m) is just greater than size
        m++;
    }

    int offset = -1;                                       // Search scope reducer: Defines how many elements in v from the starting are less than K
    int lastIdx = size - 1;                                // Search scope ends at the lastIdx of the array, so we have to look at min(searchIdx, lastIdx)

                                                           // Part 2: Finding the searchIdx which stores K if K is present in the array
    while (fibonacciNumber(m) > 1) {                       // While fib(m-2) > 0 as when fib(m) = 1, m = 2 or (m-2) = 0. We use fib(m-2) for searching the idx
        int searchIdx = offset + fibonacciNumber(m - 2);   // fib(m-2) is 1/3 of fib(m) (just greater than size), dividing the array in 1/3 and 2/3 pieces
        int idx = min(searchIdx, lastIdx);                 // Offset + fib(m-2) is the index 1/3rd dividing the subarray starting from offset, ending at lastIdx

        if (v[idx] == K) {                                 // K is found at idx
            return idx;
        }
        else if (v[idx] > K) {                             // Need to eliminate the rear-end 2/3rd of the array since K lies in the front 1/3rd
            m -= 2;                                        // m -> (m-2), (m-2) is approx m/3 so rear-end 2/3rd gets eliminated
        }
        else if (v[idx] < K) {                             // Need to eliminate the front-end 1/3rd of the array since K lies in the rear 2/3rd
            offset = idx;                                  // new offset will eliminate front 1/3 since idx represents 1/3 of current array
            m--;                                           // m -> (m-1), (m-1) because front 1/3 is gone so need to reduce m to find next fib(m-2)
        }                                                  // new offset + ((m-1)-2) will be the next searchIdx, between new offset and lastIdx
    }                                                      // This loop checks all elements except the element just next to the last offset

                                                           // Part 3: Just checking the last offset if element not found till now
                                                           // fib(m) <= 1 by now, since loop ends at that point --> fib(m-1) should be 1 for fib(m-2) to be equal to 0.
    int fibM1 = fibonacciNumber(m - 1);                    // fib(m) can also end up equal to due to m -> (m-2), so we need to check if fib(m-1) == 1 or not
    if (fibM1 == 1 && v[offset + 1] == K) {                // Checking offset + 1 and checking if fib(m) == 1 (or fib(m-1) == 1 or fib(m-2) == 0)
        return offset + 1;
    }

    return -1;                                             // If not found till now, K is not present
}

int main() {
    // vector<int> v = {1, 1, 1, 1, 2, 2, 2, 2};
    // vector<int> v = {4, 9, 17, 21, 25, 29, 32, 35, 39, 43, 47, 51, 57, 63, 67, 71}; // Size == 16
    vector<int> v = {4, 4, 17, 21, 25, 29, 35, 35, 39, 43, 47, 51, 57, 63, 71, 71}; // Duplication at beginning, middle and end

    int result = fibonacciSearch(v, 4);

    cout << ((result != -1) ? "true" : "false") << endl;
    cout << result << endl;

    return 0;
}
