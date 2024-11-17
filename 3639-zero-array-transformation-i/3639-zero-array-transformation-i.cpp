class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> pre(nums.size() + 1);
        for(auto& q : queries) {
            pre[q[0]]++;
            pre[q[1] + 1]--;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(i) pre[i] += pre[i-1];
            nums[i] -= pre[i];
            if(nums[i] > 0) return false;
        }
        return true;
    }
};