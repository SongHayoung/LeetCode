class Solution {
    unordered_map<string, int> memo;
    string key(vector<long long>& A) {
        string res = "";
        for(auto& a : A) res += to_string(a) + "#";
        return res;
    }
    int calculate(vector<int>& A, vector<long long> B, vector<int> ord) {
        vector<long long> dp(B.size() + 1, INT_MAX); dp[0] = 0;
        for(auto& a : A) {
            for(int i = ord.size() - 1; i >= 0; i--) {
                dp[i+1] = min(dp[i+1], dp[i] + (B[ord[i]] - a % B[ord[i]]) % B[ord[i]]);
            }
        }
        return dp[B.size()];
    }
    int calculate(vector<int>& A, vector<long long> B) {
        vector<int> ord;
        for(int i = 0; i < B.size(); i++) ord.push_back(i);
        int res = INT_MAX;
        do {
            res = min(res, calculate(A,B,ord));
        } while(next_permutation(begin(ord), end(ord)));
        return res;
    }
    int helper(vector<int>& A, vector<long long> B) {
        sort(begin(B), end(B));
        string k = key(B);
        if(memo.count(k)) return memo[k];
        int& res = memo[k] = calculate(A,B);
        if(B.size() > 1) {
            for(int i = 0; i < B.size(); i++) {
                for(int j = i + 1; j < B.size(); j++) {
                    long long g = __gcd(B[i], B[j]);
                    vector<long long> C{B[i] / g * B[j]};
                    for(int k = 0; k < B.size(); k++) {
                        if(k != i and k != j) C.push_back(B[k]);
                    }
                    res = min(res, helper(A,C));
                }
            }
        }
        return res;
    }
public:
    int minimumIncrements(vector<int>& nums, vector<int>& target) {
        sort(begin(nums), end(nums));
        memo = {};
        vector<long long> ltarget;
        for(auto& t : target) ltarget.push_back(t);
        return helper(nums, ltarget);
    }
};