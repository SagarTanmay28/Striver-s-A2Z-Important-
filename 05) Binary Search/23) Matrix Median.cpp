The key idea is that for a number x to be the median in an n x m matrix, there must be exactly (n * m) / 2 elements less than or equal to x. We perform binary search over the range [minElement, maxElement], where minElement and maxElement are the smallest and largest elements in the matrix.
At each step, we compute the number of elements less than or equal to the current mid.
=> If this count is less than or equal to (n * m) / 2, we search in the upper half of the range to increase the candidate value.
=> Otherwise, we search in the lower half to reduce it


#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int median(vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();

    int minVal = INT_MAX, maxVal = INT_MIN;
  
    // finding the minimum and maximum elements
    // in the matrix
    for (int i = 0; i < n; i++) {
        if (mat[i][0] < minVal)
            minVal = mat[i][0];
        if (mat[i][m - 1] > maxVal)
            maxVal = mat[i][m - 1];
    }

    int desired = (n * m + 1) / 2;
	int lo = minVal, hi = maxVal;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        int place = 0;

        // count elements smaller than or equal to mid
        for (int i = 0; i < n; ++i)
            place += 
            upper_bound(mat[i].begin(), mat[i].end(), mid)
                     - mat[i].begin();
        
        // adjust the range based on the count of 
        // elements found
        if (place < desired)
            lo = mid + 1;
        else
            hi = mid;
    }
    return lo;
}
int main() {
    vector<vector<int>> mat = {{1, 3, 5}, 
                               {2, 6, 9}, 
                               {3, 6, 9}};
    cout << median(mat) << endl;
    return 0;
}


