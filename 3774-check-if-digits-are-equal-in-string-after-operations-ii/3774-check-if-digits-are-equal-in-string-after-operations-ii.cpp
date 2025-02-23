
class Solution {
    int po2[4]{6,2,4,8};
    array<int,3> factor(int n) {
        int c2 = 0, c5 = 0;
        while(n and n % 2 == 0) {
            n /= 2; c2++;
        }
        while(n and n % 5 == 0) {
            n /= 5; c5++;
        }
        return {c2,c5,n % 10};
    }
   int helper(long long c2, long long c5, long long v) {
        if(c2 > 0 and c5 > 0) return 0;
        int res = v;
        if(c2 > 0) res = (res * po2[c2 % 4]) % 10;
        if(c5 > 0) res = (res * 5) % 10;
        return res % 10;
    }

    vector<int> pascal(int x) {
        vector<int> inv(10,-1);
        inv[1] = 1, inv[3] = 7, inv[7] = 3, inv[9] = 9;
        vector<int> res(x+1); res[0] = 1;
        long long c2 = 0, c5 = 0, val = 1;
        for(int i = 1; i < res.size(); i++) {
            auto [a2,a5,rem] = factor(x - i + 1);
            c2 += a2, c5 += a5, val = (val * rem) % 10;
            auto [b2, b5, brem] = factor(i);
            c2 -= b2, c5 -= b5, val = (val * inv[brem]) % 10;
            res[i] = helper(c2,c5,val);
        }
        return res;
    }
public:
    bool hasSameDigits(string s) {
        vector<int> p = pascal(s.length() - 2);
        int res = 0;
        for(int i = 0; i < p.size(); i++) {
            res = (res + (s[i] - s[i+1]) * p[i] % 10) % 10;
        }

        return res % 10 == 0;
    }
};