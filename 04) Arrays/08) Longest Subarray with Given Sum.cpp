class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {

        int n = nums.size();

        unordered_map<long long,int> mp;

        long long sum = 0;

        int maxi = 0;

        int i = 0;
        int j = 0;

        // Sliding Window Style
        while(j < n){

            sum += nums[j];

            if(sum == k){
                maxi = max(maxi, j - i + 1);
            }

            long long rem = sum - k;

            if(mp.find(rem) != mp.end()){
                maxi = max(maxi, j - mp[rem]);
            }

            if(mp.find(sum) == mp.end()){
                mp[sum] = j;
            }

            j++;
        }

        return maxi;
    }
};
