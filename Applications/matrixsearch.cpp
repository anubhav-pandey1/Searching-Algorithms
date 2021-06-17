#include <bits/stdc++.h>
using namespace std;

// More efficient method similar to grid-search taking advantage of row-col sorted property of the matrix
// Bottom-left and top-right elements have heterogenous neighbours ie one is smaller and other is larger
// Top-left and bottom-right elements have homogenous neighboures ie both are smaller or larger than them
// Elements to the left are always smaller and elements below are always larger due to the sorted property
// Actually it's like the matrix contains two "binary search tree" and it has two "roots" correspondingly

pair<int, int> searchMatrix(vector<vector<int>>& mtx, int n) {
    int r = 0, c = mtx[0].size() - 1;             // Starting from the top-right corner as it is hetero.
    while (r <= mtx.size() - 1 && c >= 0) {       // While the pointer stays in the matrix's bounds
        int ptr = mtx[r][c];
        if (ptr == n) {                           // Return coordinates if the pointer is the target
            return make_pair(r, c);
        }
        else if (ptr > n) {                       // Else if ptr is greater than target, then move leftwards
            c--;                                  // Since smaller elements are found leftwards
        }
        else if (ptr < n) {                       // Else if ptr is less than the target, then move downwards
            r++;                                  // Since larger elements are found downwards
        }
    }
    return make_pair(-1, -1);                     // If target not found by the end of the search, it's not there
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
        int rowSize, colSize;
        int target;
        cin >> rowSize >> colSize;
        cin >> target;
        vector<vector<int>> matrix;
        for (int r = 0; r < rowSize; r++) {
            vector<int> v;
            for (int c = 0; c < colSize; c++) {
                int ele;
                cin >> ele;
                v.push_back(ele);
            }
            matrix.push_back(v);
        }

        pair<int, int> result = searchMatrix(matrix, target);
        cout << result.first << " " << result.second << endl;
    }

    return 0;
}

// My longer, slightly less inefficient implementation based on search space reduction
// It uses 4 helper functions:-
// checkCols and checkRows to check if n can be present in the col/row and to update the limits if it can/cannot
// colBinSearch and rowBinSearch to check the cols/rows after the SSR operations

// These helper functions take inputs by reference to modify it at the original memory location
// Test-cases are below these 5 functions


void checkCols(vector<vector<int>>& mtx, int n, const int& rl, const int& ru, int& cl, int& cu) {
    for (int c = cl; c <= cu; c++) {               // Check from lower limit to upper limit
        if (mtx[rl][c] <= n && mtx[ru][c] >= n) {  // If n lies in the col, break out of loop
            break;
        }
        else if (cl < cu) {                        // Prevent overflow out of bounds when cu == cl
            cl++;                                  // Increase lower limit if n doesnt lie in col
        }
    }

    for (int c = cu; c >= cl; c--) {               // Check from upper limit to lower limit
        if (mtx[rl][c] <= n && mtx[ru][c] >= n) {  // If n lies in the col, break out of loop
            break;
        }
        else if (cu > cl) {                        // Prevent overflow out of bounds when cu == cl
            cu--;                                  // Decrease upper limit if n doesnt lie in col
        }
    }
}

void checkRows(vector<vector<int>>& mtx, int n, int& rl, int&ru, const int& cl, const int& cu) {
    for (int r = rl; r <= ru; r++) {               // Check from lower limit to upper limit
        if (mtx[r][cl] <= n && mtx[r][cu] >= n) {  // If n lies in the row, break out of loop
            break;
        }
        else if (rl < ru) {                        // Prevent overflow out of bounds when ru == rl
            rl++;                                  // Increase lower limit if n doesnt lie in row
        }
    }

    for (int r = ru; r >= rl; r--) {               // Check from upper limit to lower limit
        if (mtx[r][cl] <= n && mtx[r][cu] >= n) {  // If n lies in the row, break out of loop
            break;
        }
        else if (ru > rl) {                        // Prevent overflow out of bounds when ru == rl
            ru--;                                  // Decrease upper limit if n doesnt lie in row
        }
    }
}

pair<int, int> colBinSearch(vector<vector<int>>& mtx, int n, int col, int rl, int ru) {
    int lo = rl, hi = ru;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (mtx[mid][col] == n) {
            return make_pair(mid, col);
        }

        if (mtx[mid][col] > n) {
            hi = mid - 1;
        }
        else if (mtx[mid][col] < n) {
            lo = mid + 1;
        }
    }
    return make_pair(-1, -1);
}

pair<int, int> rowBinSearch(vector<vector<int>>& mtx, int n, int row, int cl, int cu) {
    int lo = cl, hi = cu;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (mtx[row][mid] == n) {
            return make_pair(row, mid);
        }

        if (mtx[row][mid] > n) {
            hi = mid - 1;
        }
        else if (mtx[row][mid] < n) {
            lo = mid + 1;
        }
    }
    return make_pair(-1, -1);
}

pair<int, int> matrixSearch(vector<vector<int>>& mtx, int n) {
    int cl = 0, cu = mtx[0].size() - 1;
    int rl = 0, ru = mtx.size() - 1;

    int ssr = min(cu, ru);                 // Why does min work? Why does max work? Count for search space redn.
    while (ssr--) {                        // After ssr search space reductions, we have the minimal matrix
        checkCols(mtx, n, rl, ru, cl, cu); // Each checkRow/checkCol reduces atleast 1 row/col out of search space
        checkRows(mtx, n, rl, ru, cl, cu); // ssr checkRow/checkCols reduce min(ru, cu) rows/cols out of the SS
    }                                      // After the minimal SS, no reduction takes place -> max works too

    if ((cu - cl) <= (ru - rl)) {          // Search the minimal matrix colwise/rowwise based on whichever is less
        return colBinSearch(mtx, n, cl, rl, ru); // No. of cols left to search between cu and cl are less
    }
    else {
        return rowBinSearch(mtx, n, rl, cl, cu); // No. of rows left to search between ru and rl are less
    }

    // if (mtx[rl][cl] == n)                // Why is this not needed anymore? Because we're already using
    //     return make_pair(rl, cl);        // colBinSearch and rowBinSearch if cu - cl <= ru - rl
    // else                                 // This was required when binSearch was run if cu = cl or ru = rl
    //     return make_pair(-1, -1);        // This was required when only one row/col left after SSR but that
}                                           // is not feasible if multiple copies of target are present in matrix


// Test cases:-

// Inputs:

// 7
// 4 5
// 22
// 2 3 5 6 7
// 4 5 7 8 10
// 9 11 12 14 16
// 15 17 18 22 24
// 4 4
// 29
// 10 20 30 40
// 15 25 35 45
// 27 29 37 48
// 32 33 39 50
// 5 5
// 75
// 1 4 7 11 15
// 2 5 8 12 19
// 3 6 9 16 22
// 10 13 14 17 24
// 18 21 23 26 30
// 1 2
// 1
// 1 1
// 3 3
// 14
// 1 3 5
// 6 7 12
// 11 14 14
// 3 3
// 9
// 5 6 9
// 9 10 11
// 11 14 18
// 1 1
// 1
// 1

// Outputs:

// 3 3
// 2 1
// -1 -1
// 0 0
// 2 1
// 0 2
// 0 0
