Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 

Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
Example 3:

Input: s = "abc"
Output: 1


class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> mp(3,0);

        int ans = 0;
        int i = 0;
        int j = 0;
        while(j < n){
            mp[s[j] - 'a']++;
            while(mp[0] > 0 && mp[1] > 0 && mp[2] > 0){
                ans += (n-j);
                mp[s[i] - 'a']--;
                i++;
            }
            j++;
        }
        return ans;
        
    }
};
