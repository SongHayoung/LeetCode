class Solution {
public:
    vector<int> missingRolls(vector<int>& A, int avg, int n) {
        long long sum = accumulate(begin(A), end(A), 0ll);
        long long req = 1ll * avg * (n + A.size()) - sum;
        if(req > 6ll * n or req < n) return {};
        vector<int> res(n, 1);
        req -= n;
        for(int i = 0; i < n and req; i++) {
            int padding = min(req, 5ll);
            res[i] += padding;
            req -= padding;
        }
        return res;
    }
};