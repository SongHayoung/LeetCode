long long memoSum[20][200];
bool visSum[20][200];

long long memoGD[20][2][3][11][200];
long long memoBoth[20][2][3][11][200];
bool visG[20][2][3][11][200];

class Solution {
    bool isGoodSum[200];

    bool goodInt(int x) {
        if (x < 10) return true;
        string s = to_string(x);
        bool inc = true, dec = true;
        for (int i = 1; i < (int)s.size(); i++) {
            if (s[i] <= s[i - 1]) inc = false;
            if (s[i] >= s[i - 1]) dec = false;
        }
        return inc || dec;
    }

    long long dfsSum(const string& s, int pos, int sum, bool tight) {
        if (pos == (int)s.size()) return isGoodSum[sum] ? 1LL : 0LL;
        if (!tight && visSum[pos][sum]) return memoSum[pos][sum];

        int lim = tight ? (s[pos] - '0') : 9;
        long long res = 0;
        for (int d = 0; d <= lim; d++) {
            res += dfsSum(s, pos + 1, sum + d, tight && (d == lim));
        }

        if (!tight) {
            visSum[pos][sum] = true;
            memoSum[pos][sum] = res;
        }
        return res;
    }

    void dfsG(const string& s, int pos, int started, int dir, int last, int sum, bool tight, long long& outGD, long long& outBoth) {
        if (pos == (int)s.size()) {
            outGD = 1;
            outBoth = isGoodSum[sum] ? 1LL : 0LL;
            return;
        }

        if (!tight && visG[pos][started][dir][last][sum]) {
            outGD = memoGD[pos][started][dir][last][sum];
            outBoth = memoBoth[pos][started][dir][last][sum];
            return;
        }

        int lim = tight ? (s[pos] - '0') : 9;
        long long gd = 0, both = 0;

        for (int d = 0; d <= lim; d++) {
            bool ntight = tight && (d == lim);

            if (!started) {
                if (d == 0) {
                    long long a, b;
                    dfsG(s, pos + 1, 0, 0, 10, sum, ntight, a, b);
                    gd += a;
                    both += b;
                } else {
                    long long a, b;
                    dfsG(s, pos + 1, 1, 0, d, sum + d, ntight, a, b);
                    gd += a;
                    both += b;
                }
            } else {
                if (dir == 0) {
                    if (d == last) continue;
                    int ndir = (d > last) ? 1 : 2;
                    long long a, b;
                    dfsG(s, pos + 1, 1, ndir, d, sum + d, ntight, a, b);
                    gd += a;
                    both += b;
                } else if (dir == 1) {
                    if (d <= last) continue;
                    long long a, b;
                    dfsG(s, pos + 1, 1, 1, d, sum + d, ntight, a, b);
                    gd += a;
                    both += b;
                } else {
                    if (d >= last) continue;
                    long long a, b;
                    dfsG(s, pos + 1, 1, 2, d, sum + d, ntight, a, b);
                    gd += a;
                    both += b;
                }
            }
        }

        if (!tight) {
            visG[pos][started][dir][last][sum] = true;
            memoGD[pos][started][dir][last][sum] = gd;
            memoBoth[pos][started][dir][last][sum] = both;
        }
        outGD = gd;
        outBoth = both;
    }

    long long countUpTo(long long n) {
        if (n < 0) return 0;
        string s = to_string(n);

        memset(visSum, 0, sizeof(visSum));
        memset(visG, 0, sizeof(visG));

        long long goodSumCnt = dfsSum(s, 0, 0, true);

        long long gd = 0, both = 0;
        dfsG(s, 0, 0, 0, 10, 0, true, gd, both);

        return gd + goodSumCnt - both;
    }

public:
    long long countFancy(long long l, long long r) {
        int maxSum = 9 * 16;
        for (int i = 0; i <= maxSum; i++) isGoodSum[i] = goodInt(i);
        return countUpTo(r) - countUpTo(l - 1);
    }
};