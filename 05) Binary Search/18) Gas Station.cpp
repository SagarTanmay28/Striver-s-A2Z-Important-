We have a horizontal number line. On that number line, we have gas stations at positions stations[0], stations[1], ..., stations[n-1]. Now, we add k more gas stations so that d, the maximum distance between adjacent gas stations, is minimized. We have to find the smallest possible value of d. Find the answer exactly to 6 decimal places.
Note: stations is in a strictly increasing order.

Examples:

Input: stations[] = [1, 2, 3, 4, 5], k = 2
Output: 1.00
Explanation: Since all gaps are already equal (1 unit each), adding extra stations in between does not reduce the maximum distance.
Input: stations[] = [3, 6, 12, 19, 33], k = 3
Output: 6.00 
Explanation: The largest gap is 14 (between 19 and 33). Adding 2 stations there splits it into approx 4.67. The next largest gap is 7 (between 12 and 19). Adding 1 station splits it into 3.5. Now the maximum gap left is 6.



class Solution {
public:
    bool canPlace(double dist, vector<int>& stations, int K) {
        int used = 0;
        
        for (int i = 1; i < stations.size(); i++) {
            double gap = stations[i] - stations[i - 1];
            used += (int)(ceil(gap / dist) - 1);
            
            if (used > K) return false;
        }
        return true;
    }

    double minMaxDist(vector<int>& stations, int K) {
        double low = 0;
        double high = 0;

        // Find max initial gap
        for (int i = 1; i < stations.size(); i++) {
            high = max(high, (double)(stations[i] - stations[i - 1]));
        }

        // Binary Search on Answer
        while (high - low > 1e-6) {
            double mid = (low + high) / 2;

            if (canPlace(mid, stations, K))
                high = mid;
            else
                low = mid;
        }

        return high;
    }
};
