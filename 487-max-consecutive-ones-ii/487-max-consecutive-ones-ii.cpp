class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& A) {
        int start = 0, res = 0, n = A.size(), cur = 0, prv = 0;
        for(int i = 0; i < n; i++) {
            if(A[i]) {
                if(!cur) start = i;
                res = max(res, ++cur + (start > 0) + prv);
            } else {
                res = max(res, cur + 1);
                prv = cur;
                cur = 0;
            }
        }
        return res;
    }
};