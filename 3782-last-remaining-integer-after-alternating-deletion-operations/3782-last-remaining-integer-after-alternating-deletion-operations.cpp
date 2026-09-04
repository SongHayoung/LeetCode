class Solution {
public:
    long long lastInteger(long long n) {
        if(n <= 2) return 1;
        switch(n & 3) {
            case 0: return 4 * lastInteger(n / 4) - 1;
            case 1: return 4 * lastInteger((n + 3) / 4) - 3;
            case 2: return 4 * lastInteger((n + 2) / 4) - 3;
            case 3: return 4 * lastInteger((n + 1) / 4) - 1;
        }
        return -1;
    }
};
