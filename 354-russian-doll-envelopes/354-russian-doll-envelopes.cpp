class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        unordered_map<int, unordered_set<int>> tree;
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& v1, const vector<int>& v2) -> bool { return v1[0] == v2[0] ? v1[1] > v2[1] : v1[0] < v2[0]; });
        int sz = envelopes.size();
        vector<int> contain;
        contain.push_back(INT_MIN);
        for(int i = 0; i < sz; i++) {
            if(contain.back() < envelopes[i][1])
                contain.push_back(envelopes[i][1]);
            else {
                auto it = lower_bound(contain.begin(), contain.end(), envelopes[i][1]);
                *it = envelopes[i][1];
            }
        }

        return contain.size() - 1;
    }
};