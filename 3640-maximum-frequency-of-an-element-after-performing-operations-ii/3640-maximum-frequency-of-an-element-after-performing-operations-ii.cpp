class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        unordered_map<int,int> freq;
        for(auto& n : nums) {
            freq[n]++;
            freq[n-k] += 0;
            freq[n+k] += 0;
        }
        vector<pair<int,int>> S;
        for(auto& [k,v] : freq) S.push_back({k,v});
        sort(begin(S), end(S));
        int res = 0, n = S.size();
        for(int i = 0, l = 0, r = 0, cnt = 0; i < n; i++) {
            while(S[l].first < S[i].first - k) {
                cnt -= S[l++].second;
            }
            while(r < n and S[r].first <= S[i].first + k) {
                cnt += S[r++].second;
            }
            res = max(res, S[i].second + min(cnt - S[i].second, numOperations));
        }
        return res;
    }
};