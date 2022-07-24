class Solution {
public:
    long long countExcellentPairs(vector<int>& A, int k) {
        unordered_map<int, int> pcnt;
        vector<int> psum(66);
        for(auto& a : A) pcnt[a] = __builtin_popcount(a);
        for(auto [_,v] : pcnt) psum[v] += 1;
        for(int i = 1; i < 66; i++) psum[i] += psum[i-1];

        long long res = 0;
        for(auto [me, cnt] : pcnt) {
            res += psum.back() - psum[max(k-cnt-1,0)];
        }

        return res;
    }
};