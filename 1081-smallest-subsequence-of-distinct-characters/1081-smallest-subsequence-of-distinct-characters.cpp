class Solution {
    bool bit(int x, int p) {
        return (x>>p) & 1;
    }
public:
    string smallestSubsequence(string s) {
        vector<vector<pair<int,int>>> at(26);
        int mask = 0;
        for(int i = s.length() - 1; i >= 0; i--) {
            int x = s[i] - 'a';
            mask |= 1<<x;
            at[x].push_back({mask,i});
        }
        string res = "";
        for(int pos = 0; mask;) {
            int x;
            for(int i = 25; i >= 0; i--) {
                if(!bit(mask,i)) continue;
                while(at[i].size() and at[i].back().second < pos) at[i].pop_back();
                if((at[i].back().first & mask) == mask) x = i;
            }
            res.push_back(x + 'a');
            mask ^= 1<<x;
            pos = at[x].back().second;
        }
        return res;
    }
};