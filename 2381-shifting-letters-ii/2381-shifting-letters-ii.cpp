class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> pre(s.length() + 1);
        for(auto& s : shifts) {
            int l = s[0], r = s[1], op = s[2] ? 1 : -1;
            pre[l] += op;
            pre[r+1] -= op;
        }
        for(int i = 0; i < s.length(); i++) {
            if(i) pre[i] += pre[i-1];
            int op = (pre[i] % 26 + 26) % 26;
            int val = (s[i] - 'a' + op) % 26;
            s[i] = val + 'a';
        }
        return s;
    }
};