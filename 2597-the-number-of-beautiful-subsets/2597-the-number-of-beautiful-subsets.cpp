class Solution {
    int dp[22];
public:
    int beautifulSubsets(vector<int>& A, int k) {
        unordered_map<int, vector<int>> mp;
        for(auto a : A) mp[a%k].push_back(a);
        dp[0] = 1, dp[1] = 2;
        for(int i = 2; i < 22; i++) dp[i] = dp[i-1] + dp[i-2];
        int res = 1;
        for(auto [_,vec] : mp) {
            if(vec.size() == 1) res = res * 2;
            else {
                sort(begin(vec), end(vec));
                vector<int> now{vec[0]};
                for(int i = 1; i < vec.size(); i++) {
                    if(now.back() + k == vec[i]) now.push_back(vec[i]);
                    else {
                        res *= dp[now.size()];
                        now = {vec[i]};
                    }
                }
                res *= dp[now.size()];
            }
        }
        return res - 1;
    }
};