class Solution {
public:
    int solve(int i, vector<int>& height, int k, int n, vector<int>& dp) {
        if (i == n - 1) return 0;   // base case: already at destination
        if (dp[i] != -1) return dp[i];

        int minCost = INT_MAX;

        // look FORWARD: try jumping to i+1, i+2, ..., i+k
        for (int jump = 1; jump <= k; jump++) {
            if (i + jump < n) {
                int jumpCost = abs(height[i + jump] - height[i]) + solve(i + jump, height, k, n, dp);
                minCost = min(minCost, jumpCost);
            }
        }

        return dp[i] = minCost;
    }

    int minimizeCost(int n, int k, vector<int>& height) {
        vector<int> dp(n, -1);
        return solve(0, height, k, n, dp);   // <-- now starts from index 0!
    }
};
