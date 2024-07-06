class Solution {
public:
    long long maximumPoints(vector<int>& A, int k) {
        long long res = 0, tot = k;
        int mi = INT_MAX;
        for(auto& x : A) {
            mi = min(mi, x);
            tot += x;
        }
        return k < mi ? 0 : (tot - mi) / mi;
    }
};