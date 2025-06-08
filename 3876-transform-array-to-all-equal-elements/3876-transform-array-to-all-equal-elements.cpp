
class Solution {
    bool ok(vector<int>& A, int op, int target) {
        for(int prv = target, i = 0; i < A.size() and op >= 0; i++) {
            if(prv == A[i]) {
                if(prv == target) continue;
                op--;
                prv = target;
            } else {
                if(prv == -target) op--;
                else prv = -target;
            }
            if(i == A.size() - 1 and prv != target)
                return false;
        }
        return op >= 0;
    }
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        return ok(nums,k,1) or ok(nums,k,-1);
    }
};