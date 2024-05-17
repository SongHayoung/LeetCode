class Solution {
public:
    int countSubstrings(string s) {
        queue<pair<int,int>> q;
        for(int i = 0; i < s.length(); i++) {
            q.push({i,i});
            if(i + 1 < s.length() and s[i] == s[i+1]) q.push({i,i+1});
        }
        int res = 0;
        while(q.size()) {
            auto [l,r] = q.front(); q.pop();
            l -= 1, r += 1;
            if(0 <= l and r < s.length() and s[l] == s[r]) q.push({l,r});
            res++;
        }
        return res;
    }
};