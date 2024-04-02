class Solution {
    bool helper(vector<int>& A, int k, double avg) {
        double ma = -1e9;
        for(int i = A.size() - k - 1, j = A.size() - 1; i >= 0; i--,j--) {
            ma = max(ma, A[j] - j * avg);
            if(ma >= A[i] - i * avg) return true;
        }
        return false;
    }
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double l = -1e4, r = 1e4, EPS = 1e-9;
        nums.insert(begin(nums),0);
        for(int i = 1; i < nums.size(); i++) nums[i] += nums[i-1];
        while(r - l >= EPS) {
            double m = l + (r - l) / 2;
            bool ok = helper(nums, k, m);
            if(ok) {
                l = m;
            } else r = m;
        }
        return r;
    }
};