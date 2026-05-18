The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.

For example, the beauty of "abaacc" is 3 - 1 = 2.
Given a string s, return the sum of beauty of all of its substrings.

 

Example 1:

Input: s = "aabcb"
Output: 5
Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.
Example 2:

Input: s = "aabcbaa"
Output: 17

class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int sum = 0;
        int maxi = 0;
        int mini = 0;


        for(int i=0;i<n;i++){

            vector<int> freq(26,0);

            for(int j=i;j<n;j++){
                freq[s[j] - 'a']++;
                maxi = *max_element(freq.begin(),freq.end());
                int mini = INT_MAX;
                for (int f : freq) {
                    if (f > 0) mini = min(mini, f);
                }
                    sum += (maxi - mini);
                }
        }

        return sum;
        
    }
};
