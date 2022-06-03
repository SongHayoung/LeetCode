class Solution {
public:
    bool isPerfectSquare(int num) {
        long long l = 1, r = INT_MAX;
        while(l <= r) {
            long long m = l + (r - l) / 2;
            long long product = m * m;
            if(product == num) return true;
            else if(product < num) l = m + 1;
            else r = m - 1;
        }
        return false;
    }
};