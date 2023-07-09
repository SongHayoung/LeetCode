    class Solution {
    public:
        bool checkArray(vector<int>& nums, int k) {
            vector<int> pre(nums.size() + 1);
            for(int i = 0; i < nums.size() - k + 1; i++) {
                if(i) pre[i] += pre[i-1];
                nums[i] -= pre[i];
                if(nums[i] < 0) return false;
                pre[i] += nums[i];
                pre[i+k] -= nums[i];
            }
            for(int i = nums.size() - k + 1; i < nums.size(); i++) {
                if(i) pre[i] += pre[i-1];
                nums[i] -= pre[i];
                if(nums[i] != 0) return false;
            }
            return true;
        }
    };
