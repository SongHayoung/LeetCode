class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size(), res = 0;
        vector<vector<int>> neg(k);
        vector<int> pres(k,INT_MAX);
        pres[0] = -1;
        for(int i = 0, pre = 0; i < n; i++) {
            pre = (pre + nums[i] % k + k) % k;
            neg[(2 * nums[i] % k + k ) % k].push_back(i);
            pres[pre] = min(pres[pre], i);
        }
        vector<vector<pair<int,int>>> at(n);
        for(int i = 0; i < k; i++) {
            if(pres[i] == INT_MAX) continue;
            for(int j = 0; j < k; j++) {
                if(!neg[j].size()) continue;
                auto it = std::upper_bound(neg[j].begin(), neg[j].end(),pres[i]);
                if(it == end(neg[j])) continue;

                at[*it].push_back({(i + j) % k, pres[i]});
            }
        }
        vector<int> seen(k, INT_MAX);
        for(int i = 0, pre = 0; i < n; i++) {
            pre = (pre + nums[i] % k + k) % k;
            for(auto& [t,p] : at[i]) {
                seen[t] = min(seen[t], p);
            }
            if(pres[pre] < i) {
                res = max(res, i - pres[pre]);
            }
            if(seen[pre] < i) {
                res = max(res, i - seen[pre]);
            }
        }
        return res;
    }
};