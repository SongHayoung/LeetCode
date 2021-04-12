class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int mask = 0;
        vector<int> masks(1);
        vector<bool> res(queries.size());

        for(char& c : s) {
            masks.push_back(mask ^= 1 << (c - 'a'));
        }

        for(int i = 0 ; i < queries.size(); i++) {
            res[i] = queries[i][2] >= __builtin_popcount(masks[queries[i][1] + 1] ^ masks[queries[i][0]]) >> 1;
        }

        return res;
    }
};
