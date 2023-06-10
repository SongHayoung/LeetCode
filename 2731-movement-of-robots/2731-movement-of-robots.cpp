class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        vector<long long> A;
        for(int i = 0; i < nums.size(); i++) {
            long long x = nums[i];
            if(s[i] == 'L') x -= d;
            else x += d;
            A.push_back(x);
        }
        sort(begin(A), end(A));
        for(int i = A.size() - 1; i >= 0; i--) A[i] -= A[0];
        long long sum = 0, res = 0, mod = 1e9 + 7;
        for(int i = 0; i < A.size(); i++) {
            res = (res + A[i] * i % mod - sum + mod)  % mod;
            sum = (sum + A[i]) % mod;
        }
        return res;
    }
};
