
class Solution {
    long long kadane(vector<int>& nums, int k) {
        long long best = LLONG_MIN, cur = LLONG_MIN;
        for (int x : nums) {
            long long v = (x % k == 0 ? x : -x);
            if (cur == LLONG_MIN) cur = v;
            else cur = max(v, cur + v);
            best = max(best, cur);
        }
        return best;
    }

public:
    int divisibleGame(vector<int>& nums) {
        int n = nums.size();
        int ma = max(2, *max_element(begin(nums), end(nums)));

        vector<int> spf(ma + 1);
        for (int i = 0; i <= ma; i++) spf[i] = i;
        for (int i = 2; 1LL * i * i <= ma; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= ma; j += i)
                    if (spf[j] == j) spf[j] = i;
            }
        }

        unordered_set<int> us;
        for (int x : nums) {
            int v = abs(x);
            while (v > 1) {
                int p = spf[v];
                us.insert(p);
                while (v % p == 0) v /= p;
            }
        }

        us.erase(1);
        if(us.size() == 0) us.insert(2);

        long long bestDiff = LLONG_MIN;
        int bestK = 2;

        for (int k : us) {
            long long d = kadane(nums, k);
            if (d > bestDiff || (d == bestDiff && k < bestK)) {
                bestDiff = d;
                bestK = k;
            }
        }

        long long mod = 1e9 + 7;
        return (bestDiff % mod * bestK % mod + mod) % mod; 
    }
};