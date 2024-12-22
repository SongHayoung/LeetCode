class Solution {
    vector<int> parse(string& s) {
        vector<int> res;
        int now = 1;
        for(int i = 1; i < s.length(); i++) {
            if(s[i] == s[i-1]) now++;
            else {
                res.push_back(now);
                now = 1;
            }
        }
        res.push_back(now);
        return res;
    }
    bool helper(string& s, int t, int k) {
        if(k < 0) return false;
        vector<int> chunks = parse(s);
        int carry = 0;
        for(auto& x : chunks) {
            if(x + carry <= t) {
                carry = 0;
                continue;
            } 
            int req = (x + carry) / (t + 1);
            if(k < req) return false;
            k -= req;
           if(t == 1 and (x + carry) % 2 == 0) carry = 1;
            else carry = 0;
        }
        return 1;
    }
public:
    int minLength(string s, int numOps) {
        int l = 1, r = s.length(), res = r;
        string ss = s; ss[0] = !(ss[0] - '0') + '0';
        while(l <= r) {
            int m = l + (r - l) / 2;
            bool ok = helper(s,m,numOps) or helper(ss,m,numOps - 1);
            if(ok) {
                res = m;
                r = m - 1;
            } else l = m + 1;
        }
        return res;
    }
};