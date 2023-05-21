class Solution {
public:
    bool helper(string& s, int n, int p) {
        if(p == s.length()) return n == 0;
        if(n < 0) return false;
        for(int i = p, sum = 0; i < s.length(); i++) {
            sum = sum * 10 + s[i] - '0';
            if(helper(s,n-sum,i+1)) return true;
        }
        return false;
    }
    bool ok(long n) {
        long long sq = n * n;
        string str = to_string(sq);
        return helper(str, n, 0);
    }
    int punishmentNumber(int n) {
        long res = 0;
        for(long long i = 1; i <= n; i++) {
            if(ok(i)) res += i * i;
        }
        return res;
    }
};
