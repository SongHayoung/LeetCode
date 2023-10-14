class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        unordered_map<string, pair<int,int>> mp;
        vector<int> go(n + 100);
        int pick = 0, c = 1;
        for(int i = 0; i < n; i++) {
            int len = words[i].size();
            int best = -1, cnt = -1;
            for(int j = 0; j < len; j++) {
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    if(ch == words[i][j]) continue;
                    char ori = words[i][j];
                    words[i][j] = ch;
                    if(mp.count(words[i])) {
                        auto [who, cost] = mp[words[i]];
                        if(groups[who] != groups[i]) {
                            if(cnt < cost) {
                                best = who;
                                cnt = cost;
                            }
                        }
                    }
                    words[i][j] = ori;
                }
            }
            cnt = cnt + 1;
            cnt = max(cnt, 1);
            mp[words[i]] = {i,cnt};
            go[i] = best;
            if(c < cnt) {
                c = cnt, pick = i;
            }
        }

        vector<string> res;
        int p = pick;
        while(p != -1) {
            res.push_back(words[p]);
            p = go[p];
        }
        reverse(begin(res), end(res));
        return res;
    }
};