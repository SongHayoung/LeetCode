class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long res = 0;
        for(long long i = 0; i <= limit; i++) {
            long long now = n - i;
            if(now < 0) break;
            if(now <= limit) res += (now + 1);
            else if(now > 2 * limit) continue;
            else {
                res += (limit - (now - limit) + 1);
            }
        }
        return res;
    }
};
