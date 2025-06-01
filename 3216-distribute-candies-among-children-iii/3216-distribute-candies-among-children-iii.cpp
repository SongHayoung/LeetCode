class Solution {
    long long count(long long a) {
        return a < 0 ? 0 : (a + 2) * (a + 1) / 2;
    }
public:
    long long distributeCandies(int n, int limit) {
        if(limit * 3 < n) return 0;
        return count(n) - 3 * count(n - limit - 1) + 3 * count(n - 2 * limit - 2) - 3 * count(n - 3 * limit - 3);
    }
};