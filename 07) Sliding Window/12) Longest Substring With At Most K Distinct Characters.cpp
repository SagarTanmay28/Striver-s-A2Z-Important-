Given a string s and an integer k.Find the length of the longest substring with at most k distinct characters.


Example 1

Input : s = "aababbcaacc" , k = 2

Output : 6

Explanation : The longest substring with at most two distinct characters is "aababb".

The length of the string 6.

Example 2

Input : s = "abcddefg" , k = 3

Output : 4

Explanation : The longest substring with at most three distinct characters is "bcdd".

The length of the string 4.


class Solution {
public:
    int longestKSubstr(string &s, int k) {

        int n = s.size();

        unordered_map<char,int> mp;

        int ans = -1;

        int i = 0;
        int j = 0;

        // Sliding Window
        while(j < n){

            mp[s[j]]++;

            // shrink window if distinct chars > k
            while(mp.size() > k){

                mp[s[i]]--;

                if(mp[s[i]] == 0)
                    mp.erase(s[i]);

                i++;
            }

            // valid window
            ans = max(ans , j - i + 1);

            j++;
        }

        return ans;
    }
};
