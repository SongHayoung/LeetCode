class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int res = INT_MIN, n = matrix.size(), m = matrix[0].size();
        
        for(int start = 0; start < n; start++) {
            vector<int> sum(m);
            for(int i = start; i < n; i++) {
                int kadane = 0, maxKadane = INT_MIN;
                for(int j = 0; j < m; j++) {
                    sum[j] += matrix[i][j];
                    kadane = max(sum[j], kadane + sum[j]);
                    maxKadane = max(kadane, maxKadane);
                }
                
                if(maxKadane <= k) {
                    res = max(res, maxKadane);
                    continue;
                }
                
                set<int> s{0};
                int prefixSum = 0;
                for(auto num : sum) {
                    prefixSum += num;
                    auto it = s.lower_bound(prefixSum - k);
                    if(it != s.end()) {
                        res = max(res, prefixSum - *it);
                    }
                    s.insert(prefixSum);
                }
            }
        }
        
        return res;
    }
};