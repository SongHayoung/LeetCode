class Solution {
public:
    int longestSubstring(string s, int k) {
        int res = 0;
        vector<vector<int>> pre;
        vector<vector<int>> pos(26);
        {
            vector<int> freq(26);
            pre.push_back(freq);
            for(int i = 0; i < s.length(); i++) {
                freq[s[i]-'a']++;
                pre.push_back(freq);
                pos[s[i]-'a'].push_back(i);
            }
        }
        auto qry = [&](int l, int r) {
            vector<int> res(26);
            for(int i = 0; i < 26; i++) res[i] = pre[r+1][i] - pre[l][i];
            return res;
        };
        auto check = [&](int at) {
            int r = at + k - 1, best = at - 1;
            unordered_set<int> skip;
            for(; r < s.length();) {
                auto now = qry(at,r);
                bool ok = true;
                for(int i = 0; i < 26; i++) {
                    if(!now[i]) continue;
                    if(now[i] >= k) {
                        skip.insert(i + 'a');
                    } else {
                        ok = false;
                        auto idx = lower_bound(begin(pos[i]), end(pos[i]), at) - begin(pos[i]);
                        if(idx + k > pos[i].size()) r = s.length() + 10;
                        else r = max(r, pos[i][idx+k-1]);
                    }
                }
                if(ok) {
                    while(r < s.length() and skip.count(s[r])) best = r++;
                }
            }
            return best - at + 1;
        };
        for(int i = 0; i < s.length() - res; i++) {
            if(i and s[i] == s[i-1]) continue;
            res = max(res, check(i));
        }
        return res;
    }
};