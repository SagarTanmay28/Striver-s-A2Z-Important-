You are given a string s consisting only lowercase alphabets and an integer k. Your task is to find the length of the longest substring that contains exactly k distinct characters.

Note : If no such substring exists, return -1. 

Examples:

Input: s = "aabacbebebe", k = 3
Output: 7
Explanation: The longest substring with exactly 3 distinct characters is "cbebebe", which includes 'c', 'b', and 'e'.
Input: s = "aaaa", k = 2
Output: -1
Explanation: There's no substring with 2 distinct characters.
Input: s = "aabaaab", k = 2
Output: 7
Explanation: The entire string "aabaaab" has exactly 2 unique characters 'a' and 'b', making it the longest valid substring.

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int n = s.size();
        
        unordered_map<char,int> mp;
        
        int ans = -1;
        int i = 0;
        int j = 0;
        // Sliding Window 
        while(j < n){
            mp[s[j]]++;
            
            while(mp.size() > k){
                mp[s[i]]--;
                if(mp[s[i]] == 0) mp.erase(s[i]);
                i++;
            }
            
            if(mp.size() == k) ans = max(ans,j-i+1);
            j++;
        }
        
        return ans;
    }
};
