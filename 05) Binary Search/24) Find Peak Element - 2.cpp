class Solution {
public:
    int max(vector<vector<int>>& mat,int n,int m,int mid){
        int max = -1;
        int idx = -1;
        for(int i=0;i<n;i++){
           if(mat[i][mid]>max){
             max = mat[i][mid];
             idx = i;
           } 
        }
        return idx;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int lo = 0;
        int hi = m-1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            int row = max(mat,n,m,mid);
            int left = mid-1>=0 ? mat[row][mid-1] : -1;
            int right = mid+1<m ? mat[row][mid+1] : -1;

            if(mat[row][mid]>left && mat[row][mid]>right) return {row,mid};
            else if(mat[row][mid]<left) hi = mid - 1;
            else lo = mid + 1;
        }

        return {-1,-1};
        
    }
};
