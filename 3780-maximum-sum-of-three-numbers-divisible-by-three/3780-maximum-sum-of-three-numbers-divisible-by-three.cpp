class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,vector<int>> S;
        for(auto& n : nums) S[n % 3].push_back(n);
        for(auto& [k,v] : S) sort(begin(v), end(v));
        int res = 0;
        for(int i = 0; i < 3; i++) {
            if(S[i].size() >= 3) {
                int sz = S[i].size();
                res = max(res, S[i][sz-1] + S[i][sz-2] + S[i][sz-3]);
            }
        }
        
        if(S[0].size() and S[1].size() and S[2].size()) {
            res = max(res, S[0].back() + S[1].back() + S[2].back());
        }
        return res;
    }
};