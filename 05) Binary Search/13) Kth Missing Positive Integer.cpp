
Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Return the kth positive integer that is missing from this array.

 

Example 1:

Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.



 In a perfect sorted positive array, value at index i should be (i+1), so missing numbers till any index can be calculated
using missing = arr[i] - (i+1). If actual value is bigger than expected, the difference tells how many numbers are missing before that element. 
 We use binary search to find the first index where missing >= k because that means the k-th missing number lies before or at that position. 
 If missing < k, it means not enough numbers are missing yet, so move right using lo = mid + 1; otherwise move left using hi = mid - 1. 
After the loop ends, lo becomes the first position where missing count is greater than or equal to k, and it also represents how many array elements 
exist before the answer. Therefore, among the first (lo + k) natural numbers, lo numbers are present and k are missing, so the final answer is lo + k.

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int lo = 0;
        int hi = n-1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            int missing = arr[mid]-(mid+1);
            if(missing<k) lo = mid + 1;
            else hi = mid - 1;
        }
        return (lo+k);       
    }
};
