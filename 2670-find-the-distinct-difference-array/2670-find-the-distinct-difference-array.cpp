class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        unordered_map<int, int> pre, suf;
        for(auto n : nums) suf[n] += 1;
        vector<int> res;
        for(auto& n : nums) {
            pre[n] += 1;
            if(--suf[n] == 0) suf.erase(n);
            res.push_back(pre.size() - suf.size());
        }
        return res;
    }
};
