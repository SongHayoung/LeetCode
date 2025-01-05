class Solution {
    long long gcd(long long a, long long b) {
        return __gcd(a,b);
    }
    long long lcm(long long a, long long b) {
        return a / gcd(a,b) * b;
    }
public:
    int maxLength(vector<int>& nums) {
        int res = 2, n = nums.size();
        for(int i = 0; i < n; i++) {
            long long p = nums[i], l = nums[i], g = nums[i];
            for(int j = i + 1; j < n; j++) {
                p *= nums[j];
                l = lcm(l,nums[j]);
                g = gcd(g,nums[j]);
                if(p == l * g) res = max(res, j - i + 1);
            }
        }
        return res;
    }
};