
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]


class Solution {
public:
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
        int n = nums.size();
        
        // Sort the array
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n; ++i) {
            // Skip duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicates for the second element
                    while (left < right && nums[left] == nums[left + 1]) ++left;
                    // Skip duplicates for the third element
                    while (left < right && nums[right] == nums[right - 1]) --right;
                    
                    ++left;
                    --right;
                } else if (sum < 0) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
        
        return result;
    }
};
