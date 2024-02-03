
class Solution {
public:
    vector<int> sameEndSubstringCount(string s, vector<vector<int>>& queries) {
        vector<vector<int>> pre;
        vector<int> freq(26);
        pre.push_back(freq);
        for(auto& ch : s) {
            freq[ch-'a'] += 1;
            pre.push_back(freq);
        }
        vector<int> res;
        auto qry = [&](int r, int l) {
            int res = 0;
            for(int i = 0; i < 26; i++) {
                int x = pre[r+1][i] - pre[l][i];
                res += x * (x + 1) / 2;
            }
            return res;
        };
        for(auto& q : queries) {
            res.push_back(qry(q[1],q[0]));
        }
        return res;
    }
};
