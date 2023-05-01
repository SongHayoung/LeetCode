class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int ma = 0;
        vector<long long> pre;
        for(auto n : nums) {
            ma = max(ma, n);
            pre.push_back((pre.size() ? pre.back() : 0) + ma + n);
        }
        return pre;
    }
};
