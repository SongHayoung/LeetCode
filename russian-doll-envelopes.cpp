class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end());
        int res = 0, sz = envelopes.size();
        vector<int> contain(sz, 0);
        for(int i = 0; i < sz; i++) {
            for(int j = 0; j < i; j++) {
                if(envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1])
                    contain[i] = max(contain[i], contain[j]);
            }
            res = max(res, ++contain[i]);
        }
        return res;
    }
};
