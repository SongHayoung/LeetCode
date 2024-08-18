class Solution {
public:
    long long maxProfit(vector<int>& profitsA, vector<int>& profitsB) {
        int n = profitsA.size();
        if (n == 0) return 0;

        vector<long long> dpA(n, 0);
        vector<long long> dpB(n, 0);

        // Initial values for day 0
        dpA[0] = profitsA[0];
        dpB[0] = profitsB[0];

        for (int i = 1; i < n; ++i) {
            dpA[i] = max(dpA[i-1] + profitsA[i], (i-2 >= 0 ? dpB[i-2] : 0) + profitsA[i]);
            dpB[i] = max(dpB[i-1] + profitsB[i], (i-2 >= 0 ? dpA[i-2] : 0) + profitsB[i]);
        }

        // The maximum profit we can get on the last day
        return max(dpA[n-1], dpB[n-1]);
    }
};