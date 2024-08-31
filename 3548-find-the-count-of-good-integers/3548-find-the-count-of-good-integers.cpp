long long binom[11][11];
class Solution {
    long long nCr(long long n, long long r) {
        if(binom[n][r] != -1) return binom[n][r];
        long long& res = binom[n][r] = 0;
        if(r == 0 or n == r) return res = 1;
        if(r > n - r) return res = nCr(n, n - r);
        return res = nCr(n-1,r-1) + nCr(n-1,r);
    }
    unordered_map<string, long long> dp;
    long long rev(long long x) {
        long long res = 0;
        while(x) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
    long long helper(vector<int>& S) {
        string key = "";
        long long sum = 0;
        for(auto& n : S) key += to_string(n) + "#", sum += n;
        if(dp.count(key)) return dp[key];
        long long& res = dp[key] = 1;
        for(auto& r : S) {
            res = res * nCr(sum,r);
            sum -= r;
        }
        return res;
    }
    long long helper(string s) {
        long long res = 0;
        vector<int> f(10);
        for(auto& ch : s) f[ch-'0']++;
        for(int i = 1; i < 10; i++) {
            if(!f[i]) continue;
            f[i]--;
            vector<int> A = f;
            sort(rbegin(A), rend(A));
            while(A.size() and A.back() == 0) A.pop_back();
            res += helper(A);
            f[i]++;
        }
        return res;
    }

public:
    long long countGoodIntegers(int n, int k) {
        if(n == 1) {
            int res = 0;
            for(int i = 1; i <= 9; i++) if(i % k == 0) res++;
            return res;
        }
        dp.clear();
        memset(binom, -1, sizeof binom);
        long long po = pow(10, n/2 - 1), ppo = po * 10;
        unordered_set<string> us;
        for(long long i = po; i < ppo; i++) {
            vector<long long> A;
            long long p = i * ppo, r = rev(i);
            if(n & 1) {
                p *= 10;
                for(long long i = 0; i < 10; i++) {
                    A.push_back(p + po * i * 10 + r);
                }
            } else A.push_back(p + r);
            for(auto& n : A) if(n % k == 0) {
                    string s = to_string(n);
                    sort(begin(s), end(s));
                    us.insert(s);
                }
        }
        long long res = 0;
        unordered_map<string, long long> mp;
        for(auto s : us) {
            char id = '1';
            unordered_map<char,char> match;
            for(int i = 0; i < s.length(); i++) {
                if(s[i] == '0') continue;
                if(!match.count(s[i])) match[s[i]] = id++;
                s[i] = match[s[i]];
            }
            mp[s]++;
        }
        for(auto [s,cnt] : mp) {
            res += cnt * helper(s);
        }
        return res;
    }
};