class Solution {
    long long helper(int n) {
        int len = to_string(n).length();
        if(len & 1) len += 1;
        else len += 2;
        string res(len,'1');
        for(int i = 1; i < 1 + len/2; i++) res[i] = '0';
        return stoll(res);
    }
    long long helper2(string s, int p, int cnt, bool fl) {
        if(s.length() & 1) return INT_MAX;
        if(p == s.length()) return cnt ? INT_MAX : 0;
        long long res = INT_MAX;
        if(fl) {
            int rem = s.length() - p - abs(cnt);
            if(rem < 0) return INT_MAX;
            string now = string(rem,'0');
            for(int i = rem / 2; i < rem; i++) now[i] = '1';
            if(cnt < 0) now = now + string(-cnt,'1');
            else now = string(cnt,'0') + now;
            res = stoll(now);
            return res;
        }
        int v = s[p] - '0';
        res = min(res, (long long)(pow(10,s.length() - p - 1) * v) + helper2(s,p+1,cnt + (v & 1 ? 1 : -1), false));
        if(v < 9) {
            res = min(res, (long long)(pow(10,s.length() - p - 1) * (v + 1)) + helper2(s,p+1,cnt + ((v + 1) & 1 ? 1 : -1), true));
        }
        if(v < 8) {
            res = min(res, (long long)(pow(10,s.length() - p - 1) * (v + 2)) + helper2(s,p+1,cnt + ((v + 2) & 1 ? 1 : -1), true));
        }
        return res;
    }
public:
    int closestFair(int n) {
        long long res = helper(n);
        res = min(res, helper2(to_string(n), 0, 0,false));
        return res;
    }
};