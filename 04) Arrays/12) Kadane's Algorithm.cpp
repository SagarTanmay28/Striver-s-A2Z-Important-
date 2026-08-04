
Given an integer array nums, find the subarray with the largest sum, and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

  
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int ans = INT_MIN;

        for(int i=0;i<n;i++){
            sum += nums[i];
            ans = max(ans,sum);

            if(sum < 0) sum = 0;
        }

        return ans;
        
    }
};


// 2. Extended Version — Print the Subarray with Maximum Sum

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int ans = INT_MIN;

        int start = 0;
        int bestStart = 0, bestEnd = 0;

        for(int i=0;i<n;i++){
            if(sum == 0) start = i;   // marks potential new subarray start

            sum += nums[i];

            if(sum > ans){
                ans = sum;
                bestStart = start;
                bestEnd = i;
            }

            if(sum < 0) sum = 0;
        }

        // print the subarray
        cout << "Subarray: ";
        for(int i = bestStart; i <= bestEnd; i++)
            cout << nums[i] << " ";
        cout << "\n";

        return ans;
    }
};
