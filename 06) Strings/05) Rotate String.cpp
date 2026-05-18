Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

A shift on s consists of moving the leftmost character of s to the rightmost position.

For example, if s = "abcde", then it will be "bcdea" after one shift.
 

Example 1:

Input: s = "abcde", goal = "cdeab"
Output: true
Example 2:

Input: s = "abcde", goal = "abced"
Output: false


class Solution {
public:
    bool rotateString(string s, string goal) {
        
        int n1 = s.size();
        int n2 = goal.size();
        if(n1 != n2) return false;

        for(int i=0;i<n1;i++){
           s = s.substr(1) + s[0];
            if(s==goal) return true;
        }
        return false;
        
    }
};
