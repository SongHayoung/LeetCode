class Solution {
public:
    vector<int> longestCommonPrefix(vector<string>& words) {
        vector<int> res, match(words.size()), suf(words.size() + 1);
        auto query = [&](int i, int j) {
            if(0 <= i and i < words.size() and 0 <= j and j < words.size()) {
                int res = 0;
                for(int p = 0; p < words[i].size() and p < words[j].size(); p++) {
                    if(words[i][p] != words[j][p]) break;
                    res++;
                }
                return res;
            }
            return 0;
        };
        for(int i = 0; i < words.size() - 1; i++) match[i] = query(i, i + 1);
        for(int i = match.size() - 1; i >= 0; i--) suf[i] = max(match[i], suf[i+1]);
        for(int i = 0, best = 0; i < match.size(); i++) {
            if(i >= 2) best = max(best, match[i-2]);
            res.push_back(max({best, suf[i+1], query(i - 1, i + 1)}));
        }
        return res;
    }
};
