class Solution {
    bool helper(vector<int>& A, long long m) {
        long long op = 0;
        for(auto& a : A) {
            op += (a + m - 1) / m;
        }
        return op <= m * m;
    }
public:
    int minimumK(vector<int>& nums) {
        int l = 1, r = 1e5, res = r;
        while(l <= r) {
            int m = l + (r - l) / 2;
            bool ok = helper(nums, m);
            if(ok) {
                res = m;
                r = m - 1;
            } else l = m + 1;
        }
        return res;
    }
};