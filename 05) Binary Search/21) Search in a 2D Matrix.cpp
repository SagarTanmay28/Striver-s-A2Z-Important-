// Matrix Flatten Wala Question 

class Solution {
public: // O(log(m * n))
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        // 0 1 2 3 4
        // 1 5 6 7 8
        // 2 9 10 11 12

        int lo = 0;
        int hi = (m*n)-1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            int row = mid/n;
            int col = mid%n;
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]<target) lo = mid + 1;
            else hi = mid - 1;
        }
        return false;
        
    }
};

// Row and Column Sorted wala Question 

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int row = 0, col = m-1;
        while(row<n && col>=0){
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]<target) row++;
            else col--;
        }

        return false;
        
    }
};
