class Solution {
public:
    char findKthBit(int n, int k) {
        if(n == 1) return '0';
        int p = pow(2,n) - 1;
        if(k - 1 == p / 2) return '1';
        if(k - 1 < p / 2) return findKthBit(n - 1, k);
        return findKthBit(n - 1, p - k + 1) == '0' ? '1' : '0';
    }
};