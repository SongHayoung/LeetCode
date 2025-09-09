class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        sort(begin(nums), end(nums));
        while(nums.size()) {
            int x = nums.back(), cnt = 0;
            while(nums.size() and nums.back() == x) {
                nums.pop_back();
                cnt += 1;
            }
            if(cnt == 1) return x;
        }
        return -1;
    }
};