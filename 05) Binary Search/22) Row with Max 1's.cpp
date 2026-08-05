#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rowWithMax1sBinarySearch(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    int maxCount = 0, rowIndex = -1;

    for(int i = 0; i < n; i++){
        // find first index where value is 1 (lower_bound for value 1)
        auto it = lower_bound(matrix[i].begin(), matrix[i].end(), 1);
        int countOnes = matrix[i].end() - it;

        if(countOnes > maxCount){
            maxCount = countOnes;
            rowIndex = i;
        }
    }

    return rowIndex;
}

int main() {
    vector<vector<int>> matrix = {
        {0, 0, 0, 1},
        {0, 1, 1, 1},
        {0, 0, 1, 1}
    };

    cout << rowWithMax1sBinarySearch(matrix);  // 1
}
