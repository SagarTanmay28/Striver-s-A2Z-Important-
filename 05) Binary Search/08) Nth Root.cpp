class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here
        long long lo = 0;
        long long hi = m;
    
        // Binary Search 
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            
            long long ans = 1;
            for(int i=1;i<=n;i++){
                ans *= mid;
                
                if(ans > m) break;
            }
            
            if(ans == m) return mid;
            
            if(ans < m) lo = mid + 1;
            else hi = mid - 1;
            
        }
        
        return -1;
        
    }
};
