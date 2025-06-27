class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        queue<string> q;
        string res = "";
        q.push(res);
        while(!q.empty()) {
            auto sub = q.front(); q.pop();
            for(int i = 0; i < 26; i++) {
                string nsub = sub + string(1, 'a' + i);
                if(nsub.length() * k <= s.length()) {
                    if(isSub(s,nsub,k)) {
                        q.push(nsub);
                        res = nsub;
                    }
                }
            }
        }
        return res;
    }
    bool isSub(string& o, string& sub, int k) {
        for(int i = 0, j = 0; i < o.length() and k; i++) {
            if(o[i] == sub[j]) {
                j = (j + 1) % sub.length();
                if(!j) k--;
            }
        }
        return k == 0;
    }
};