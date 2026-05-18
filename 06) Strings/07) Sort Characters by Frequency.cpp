class Solution {
public:
    typedef pair<int,char> pi;
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char,int> mp;
        for(auto &x : s) mp[x]++;

        priority_queue<pi> pq;
        for(auto &x : mp) pq.push({x.second,x.first});

        string ans = "";
        while(pq.size()){
            int freq = pq.top().first;
            char ch = pq.top().second;
            ans += string(freq,ch);
            pq.pop();
        }
       
        return ans;
        
    }
};
