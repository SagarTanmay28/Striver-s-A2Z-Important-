class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

    int n = matrix.size();
        
    //transposing the matrix
    for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
       int temp = matrix[i][j];
       matrix[i][j] = matrix[j][i];
       matrix[j][i] = temp;
    }
    }
    //reversing each row of the matrix
     for(int k=0;k<n;k++){
        int i=0;
        int j=n-1;
        while(i<=j){
            int temp = matrix[k][i];
             matrix[k][i] = matrix[k][j];
             matrix[k][j] = temp;
             i++;
             j--;   
        }
     }
     return;
    }
};
