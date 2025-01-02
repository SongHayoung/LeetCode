class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> psum{0};
        unordered_set<char> v{'a','e','i','o','u'};
        for(auto w : words) {
            int now = v.count(w.front()) and v.count(w.back());
            psum.push_back(psum.back() + now);
        }
        vector<int> res;
        for(auto q : queries) {
            int l = q[0], r = q[1];
            res.push_back(psum[r+1] - psum[l]);
        }
        return res;
    }
};