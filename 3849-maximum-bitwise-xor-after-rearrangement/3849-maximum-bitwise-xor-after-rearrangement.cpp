class Solution {
public:
    string maximumXor(string s, string t) {
        int op = count(begin(t), end(t), '1');
        vector<bool> done(s.length());
        for(int i = 0; i < s.length() and op; i++) {
            if(s[i] == '0') {
                s[i] = '1';
                op--;
                done[i] = true;
            }
        }
        for(int i = s.length() - 1; i >= 0 and op; i--) {
            if(done[i]) continue;
            if(s[i] == '1') {
                s[i] = '0';
                op--;
            }
        }
        return s;
    }
};