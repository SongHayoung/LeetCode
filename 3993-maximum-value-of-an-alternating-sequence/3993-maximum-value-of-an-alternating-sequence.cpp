class Solution {
public:
    long long maximumValue(int n, int s, int m) {  
        return n == 1 ? s : s + ((n / 2 - 1) * 1ll * (m - 1)) + (n / 2 ? m : 0);
    }
};