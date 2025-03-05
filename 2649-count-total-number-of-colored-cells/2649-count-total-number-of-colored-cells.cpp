class Solution {
public:
    long long coloredCells(int n) {
        if(n == 1) return 1;
        return 2ll * n - 1 + 1ll * (n - 1) * (1ll + 2ll * n - 3ll);
    }
};