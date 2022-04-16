class Solution {
public:
    int minWastedSpace(vector<int>& P, vector<vector<int>>& B) {
        long long res = LLONG_MAX, mod = 1e9 + 7;
        sort(begin(P), end(P));
        for(auto& b : B) {
            sort(begin(b), end(b));
            long long sum = 0;
            if(b.back() < P.back()) continue;
            long long i = 0, j = 0, k = 0, n = P.size(), m = b.size();
            while(i < m and j < n and sum < res) {
                k = upper_bound(begin(P) + j, end(P), b[i]) - begin(P);
                sum += b[i++] * (k - j);
                j = k;
            }
            
            res = min(res, sum);
        }
        return res == LLONG_MAX ? -1 : (res - accumulate(begin(P), end(P), 0ll)) % mod;
    }
};