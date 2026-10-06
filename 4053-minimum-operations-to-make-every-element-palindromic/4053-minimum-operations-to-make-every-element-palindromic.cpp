class Solution {
    long long build(long long p, int len) {
        long long res = p, q = len & 1 ? p / 10 : p;
        while(q) res = res * 10 + q % 10, q /= 10;
        return res;
    }
public:
    long long minOperations(vector<int>& nums) {
        vector<vector<long long>> bound(12);
        for(int l = 1; l <= 11; l++) {
            long long b = 1;
            for(int i = 1; i < (l + 1) / 2; i++) b *= 10;
            for(int g = 1; g <= 9; g++) {
                bound[l].push_back(build(g * b, l));
                bound[l].push_back(build((g + 1) * b - 1, l));
            }
        }
        long long res = 0;
        for(long long x : nums) {
            int len = 0;
            for(long long t = x; t; t /= 10) len++;
            int half = (len + 1) / 2;
            long long lo = 1, p = x, best = LLONG_MAX;
            for(int i = 1; i < half; i++) lo *= 10;
            for(int i = half; i < len; i++) p /= 10;
            auto upd = [&](long long v) {
                if((v & 1) == (x & 1)) best = min(best, abs(v - x) / 2);
            };
            for(int d = -1; d <= 1; d++) {
                long long q = p + d;
                if(q >= lo and q < lo * 10) upd(build(q, len));
            }
            for(int l = max(1, len - 1); l <= len + 1; l++) {
                for(auto& v : bound[l]) upd(v);
            }
            res += best;
        }
        return res;
    }
};