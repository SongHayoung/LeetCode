class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(rbegin(nums), rend(nums));
        vector<int> res;
        int now = nums.back();
        while(nums.size()) {
            if(nums.back() == now) nums.pop_back();
            else res.push_back(now);
            now++;
        }
        return res;
    }
};