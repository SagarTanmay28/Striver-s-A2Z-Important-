class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int ans = INT_MAX;

        int lo = 0;
        int hi = n - 1;
        // Binary Search 
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(nums[lo] <= nums[hi]){
                ans = min(ans,nums[lo]);
                break;
            }

            if(nums[lo] <= nums[mid]){
                ans = min(ans,nums[lo]);
                lo = mid + 1;
            }
            else if(nums[mid] <= nums[hi]){
                ans = min(ans,nums[mid]);
                hi = mid - 1;
            }
        }

        return ans;
    }
};
