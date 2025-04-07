class Solution {
    bool nok(vector<int>& A) {
        for(int i = 0; i < A.size() - 1; i++) {
            if(A[i] > A[i+1]) return true;
        }
        return false;
    }
public:
    int minimumPairRemoval(vector<int>& nums) {
        int res = 0;
        while(nok(nums)) {
            int best = 0;
            for(int i = 1; i < nums.size() - 1; i++) {
                if(nums[i] + nums[i+1] < nums[best] + nums[best+1]) best = i;
            }
            nums[best] += nums[best+1];
            for(int i = best + 1; i < nums.size() - 1; i++) nums[i] = nums[i+1];
            nums.pop_back();
            res++;
        }
        return res;
    }
};