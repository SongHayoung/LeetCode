class Solution {
public:
    long long maxGCDScore(vector<int>& nums, int k) {
        long long res = 0;
        for(int i = 0; i < nums.size(); i++) {
            long long g = 0, two = 0, cnt = 0;
            for(int j = i; j < nums.size(); j++) {
                long long ct = 1, x = nums[j];
                while(x % 2 == 0) {
                    ct *= 2, x /= 2;
                }
                if(i == j) g = x, two = ct, cnt = 1;
                else {
                    g = __gcd(g,x);
                    if(two > ct) two = ct, cnt = 1;
                    else if(two == ct) cnt++;
                }
                long long t = cnt <= k ? two * 2 : two;
                res = max(res, g * t * (j - i + 1));
            }
        }
        return res;
    }
};
