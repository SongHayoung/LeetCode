class Solution {
    long long helper(vector<long long>& psum, int k) {
        long long res = 0;
        for(int i = 0; i < psum.size() - 1; i++) {
            long long f = psum[i] + k;
            res += upper_bound(begin(psum) + i, end(psum), f) - begin(psum) - i - 1;
        }
        return res;
    }
public:
    int kthSmallestSubarraySum(vector<int>& A, int k) {
        vector<long long> psum{0};
        for(auto& a : A) psum.push_back(psum.back() + a);
        long long res = INT_MAX, l = 0, r = psum.back();
        while(l <= r) {
            long long m = l + (r - l) / 2;
            long long mk = helper(psum, m);
            if(mk >= k) {
                res = min(res, m);
                r = m - 1;
            } else l = m + 1;
        }
        return res;
    }
};