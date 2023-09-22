class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        multiset<int> s;
        int res = 0;
        for(auto &n : nums) {
            s.erase(next(s.insert(n)), s.end());
            res += s.size();
        }
        return res;
    }
};