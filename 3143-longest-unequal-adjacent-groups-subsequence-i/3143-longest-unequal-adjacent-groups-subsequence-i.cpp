class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        unordered_map<int, int> best;
        unordered_map<int, int> at;
        vector<int> go(n);
        int pick = -1;
        for(int i = 0; i < n; i++) {
            int who = -1;
            for(auto& [k,v] : best) {
                if(k == groups[i]) continue;
                if(who == -1) who = k;
                else {
                    if(best[who] < v) who = k;
                }
            }
            if(who == -1) {
                go[i] = -1;
                best[groups[i]] = 1;
                at[groups[i]] = i;
            } else {
                go[i] = at[who];
                best[groups[i]] = best[who] + 1;
                at[groups[i]] = i;
            }
            if(best[groups[i]] > best[pick]) pick = groups[i];
        }
        vector<string> res;
        int p = at[pick];
        while(p != -1) {
            res.push_back(words[p]);
            p = go[p];
        }
        reverse(begin(res), end(res));
        return res;
    }
};
