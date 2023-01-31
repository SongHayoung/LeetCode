class Solution {
public:
    int goodBinaryStrings(int minLength, int maxLength, int oneGroup, int zeroGroup) {
        long long res = 0, mod = 1e9 + 7;
        vector<long long> dp1(maxLength + 1), dp2(maxLength + 1);
        dp1[oneGroup] = dp2[zeroGroup] = 1;
        for(int i = 1; i <= maxLength; i++) {
            int l1 = i - oneGroup, l2 = i - zeroGroup;
            if(l1 >= 0) dp1[i] = (dp1[i] + dp1[l1] + dp2[l1]) % mod;
            if(l2 >= 0) dp2[i] = (dp2[i] + dp1[l2] + dp2[l2]) % mod;
            if(i >= minLength) res = (res + dp1[i] + dp2[i]) % mod;
        }
        return res;
    }
};