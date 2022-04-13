class Solution {
    int helper(vector<int>& nums, int firstLen, int secondLen) {
        vector<int> f{0};
        vector<int> psum{0};
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            psum.push_back(psum.back() + nums[i]);
            int sz = psum.size();
            if(sz >= firstLen + 1) {
                f.push_back(max(f.back(), psum.back() - psum[sz - firstLen - 1]));
            } else {
                f.push_back(0);
            }
            if(sz >= secondLen + firstLen) {
                res = max(res, psum.back() - psum[sz - secondLen - 1] + f[sz - secondLen - 1]);
            }
        }
        return res;
    }
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        return max(helper(nums, firstLen, secondLen), helper(nums, secondLen, firstLen));
    }
};