class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> l(n), r(n);
        for(int i = 1; i < n; i++) {
            l[i] = l[i-1] + nums[i-1];
        }
        for(int i = n - 2; i >= 0; i--) {
            r[i] = r[i+1] + nums[i+1];
        }
        vector<int> res(n);
        for(int i = 0; i < n; i++) {
            res[i] = abs(l[i]-r[i]);
        }
        return res;
    }
};