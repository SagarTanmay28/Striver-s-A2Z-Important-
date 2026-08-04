class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        int ele   = nums[0];
        int count = 1;

        for(int i=1 ;i<n ;i++){

            if(count == 0){
                ele = nums[i];
                count = 1;
            }
            else if(ele == nums[i]) count++;
            else count--;
        }

        return ele;
    }
};
