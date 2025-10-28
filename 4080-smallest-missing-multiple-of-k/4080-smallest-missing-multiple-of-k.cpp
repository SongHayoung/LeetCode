class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(rbegin(nums), rend(nums));
        int res = k;
        while(nums.size()) {
            while(nums.size() and nums.back() < res) nums.pop_back();
            if(nums.size()) {
                if(nums.back() == res) res += k;
                else return res;
            }
        }
        return res;
    }
};