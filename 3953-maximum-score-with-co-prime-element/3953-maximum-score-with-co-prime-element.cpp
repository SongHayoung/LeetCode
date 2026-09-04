class Solution {
public:
    int maxScore(vector<int>& nums, int maxVal) {
        int n = nums.size();
        int M = max(maxVal, *max_element(nums.begin(), nums.end()));

        vector<int> freq(M + 1);
        for (int x : nums) freq[x]++;

        vector<int> mu(M + 1), lp(M + 1), primes;
        mu[1] = 1;
        for (int i = 2; i <= M; i++) {
            if (lp[i] == 0) {
                lp[i] = i;
                primes.push_back(i);
                mu[i] = -1;
            }
            for (int p : primes) {
                long long v = 1LL * i * p;
                if (v > M) break;
                lp[v] = p;
                if (i % p == 0) {
                    mu[v] = 0;
                    break;
                } else {
                    mu[v] = -mu[i];
                }
            }
        }

        vector<int> multCnt(M + 1);
        for (int d = 1; d <= M; d++) {
            for (int k = d; k <= M; k += d) {
                multCnt[d] += freq[k];
            }
        }

        vector<int> cop(M + 1);
        for (int d = 1; d <= M; d++) {
            if (mu[d] == 0) continue;
            int add = mu[d] * multCnt[d];
            for (int x = d; x <= M; x += d) {
                cop[x] += add;
            }
        }

        int ans = 0;

        for (int x = 1; x <= M; x++) {
            int bad = n - cop[x];

            if (freq[x] > 0) {
                if (x == 1) ans = max(ans, 1);
                else ans = max(ans, x - bad + 1);
            } else if (x <= maxVal) {
                if (bad > 0) ans = max(ans, x - bad);
                else ans = max(ans, x - 1);
            }
        }

        return ans;
    }
};