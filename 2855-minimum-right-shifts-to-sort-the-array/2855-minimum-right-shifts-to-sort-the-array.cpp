class Solution {
    bool ok(vector<int>& A, int p) {
        int n = A.size();
        for(int i = 1; i < A.size(); i++) {
            if(A[(p + i) % n] > A[(p + i - 1 + n) % n]) continue;
            return false;
        }
        return true;
    }
public:
    int minimumRightShifts(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            if(ok(nums,(nums.size() - i) % nums.size())) return i;
        }
        return -1;
    }
};


