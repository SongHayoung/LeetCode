
class Solution {
    int helper(vector<vector<int>>& pre, vector<int>& f, int p) {
        int l = p, r = pre.size() - 2, res = pre.size() - 1;
        auto check = [&](int x) {
            for(int i = 0; i < 26; i++) {
                if(pre[x+1][i] - pre[p][i] < f[i]) return false;
            }
            return true;
        };
        while(l <= r) {
            int m = l + (r - l) / 2;
            bool ok = check(m);
            if(ok) {
                res = m;
                r = m - 1;
            } else l = m + 1;
        }
        
        return pre.size() - 1 - res;
    }
public:
    long long validSubstringCount(string word1, string word2) {
        vector<int> freq(26);
        for(auto& ch : word2) freq[ch-'a']++;
        
        vector<int> now(26);
        vector<vector<int>> pre{now};
        for(int i = 0; i < word1.size(); i++) {
            now[word1[i] - 'a']++;
            pre.push_back(now);
        }
        
        long long res = 0;
        for(int i = 0; i < word1.size(); i++) {
            int now = helper(pre,freq,i);
            if(!now) break;
            res += now;
        }
        return res;
    }
};