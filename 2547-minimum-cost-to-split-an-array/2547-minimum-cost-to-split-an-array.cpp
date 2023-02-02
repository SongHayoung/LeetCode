class Solution {
public:
    int minCost(vector<int>& A, int k) {
        vector<int> dp(A.size() + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 0; i < A.size(); i++) {
            int len = 0, cut = 0;
            unordered_map<int,int> freq;
            for(int j = i; j < A.size(); j++) {
                len += 1;
                ++freq[A[j]];
                if(freq[A[j]] == 1) cut += 1;
                else if(freq[A[j]] == 2) cut -= 1;
                dp[j+1] = min(dp[j+1], dp[i] + len - cut + k);
            }
        }
        return dp.back();
    }
};