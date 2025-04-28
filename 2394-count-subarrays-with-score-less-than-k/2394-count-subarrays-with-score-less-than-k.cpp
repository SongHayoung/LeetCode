class Solution {
public:
    long long countSubarrays(vector<int>& A, long long k) {
        vector<long long> psum{0};
        long long res = 0, l = 0, n = A.size();
        for(int i = 0; i < n; i++) {
            psum.push_back(psum.back() + A[i]);
            while((psum.back() - psum[l]) * (i - l + 1) >= k) l++;
            res += (i - l + 1);
        }
        return res;
    }
};