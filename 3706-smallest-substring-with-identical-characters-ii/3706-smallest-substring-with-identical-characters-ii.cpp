class Solution {
    vector<int> parse(string& s) {
        vector<int> res{1};
        for(int i = 1; i < s.length(); i++) {
            if(s[i] == s[i-1]) res.back()++;
            else res.push_back(1);
        }
        return res;
    }
    bool helper(vector<int>& chunks, int t, int k) {
        for(int i = 0, carry = 0; i < chunks.size() and k >= 0; i++) {
            int req = (chunks[i] + carry) / (t + 1);
            k -= req;
            carry = t == 1 and (chunks[i] + carry) % 2 == 0;
        }
        return k >= 0;
    }
public:
    int minLength(string s, int numOps) {
        int l = 1, r = s.length(), res = r;
        string ss = s; ss[0] = !(ss[0] - '0') + '0';
        vector<int> chunk1 = parse(s), chunk2 = parse(ss);
        while(l <= r) {
            int m = l + (r - l) / 2;
            bool ok = helper(chunk1,m,numOps) or helper(chunk2,m,numOps - 1);
            if(ok) {
                res = m;
                r = m - 1;
            } else l = m + 1;
        }
        return res;
    }
};