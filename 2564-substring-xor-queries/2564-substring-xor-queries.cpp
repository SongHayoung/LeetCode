class Solution {

public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < queries.size(); i++) {
            auto bit = queries[i][0] ^ queries[i][1];
            mp[bit].push_back(i);
        }
        vector<vector<int>> res(queries.size(), {-1,-1});
        for(int len = 1; len <= 30; len++) {
            long long mask = (1ll<<len) - 1;
            for(long long i = 0, now = 0; i < s.length(); i++) {
                now = (now * 2 + s[i] - '0') & mask;
                if(i + 1 >= len) {
                    if(mp.count(now)) {
                        for(auto idx : mp[now]) {
                            res[idx] = {(int)i-len+1,(int)i};
                        }
                        mp.erase(now);
                    }
                }
            }
        }
        return res;
    }
};
