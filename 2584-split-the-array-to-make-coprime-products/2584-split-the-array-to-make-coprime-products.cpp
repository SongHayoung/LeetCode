class Solution {
    unordered_map<int, int> helper(vector<int> A) {
        unordered_map<int, int> res;
        for(int i = 0; i < A.size(); i++) {
            for(int j = 2; j * j <= A[i]; j++) {
                if(A[i] % j) continue;
                res[j] = i;
                while(A[i] % j == 0) A[i] /= j;
            }
            if(A[i] != 1) res[A[i]] = i;
        }
        return res;
    }
public:
    int findValidSplit(vector<int>& nums) {
        unordered_map<int, int> mp = helper(nums);
        int ma = 0;
        for(int i = 0; i < nums.size() and i <= ma; i++) {
            for(int j = 2; j * j <= nums[i]; j++) {
                if(nums[i] % j) continue;
                ma = max(ma,mp[j]);
                while(nums[i] % j == 0) nums[i] /= j;
            }
            if(nums[i] != 1) ma = max(ma,mp[nums[i]]);
        }
        if(ma == nums.size() - 1) return -1;
        return ma;
    }
};