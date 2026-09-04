class Solution {
    bool bit(int n, int x) {
        return (n>>x) & 1;
    }
    bool ok(int x) {
        int l = 64ll - __builtin_clzll(x) - 1ll, r = 0;
        while(r < l) {
            if(bit(x,l) != bit(x,r)) return false;
            l--,r++;
        }
        return true;
    }
public:
    vector<int> minOperations(vector<int>& nums) {
        int ma = *max_element(begin(nums), end(nums)) * 2;
        vector<int> A;
        for(int i = 1; i <= ma; i++) if(ok(i)) A.push_back(i);
        for(auto& n : nums) {
            int ri = lower_bound(begin(A), end(A), n) - begin(A), le = ri - 1;
            if(le == -1) n = A[ri] - n;
            else n = min(A[ri] - n, n - A[le]);
        }
        return nums;
    }
};