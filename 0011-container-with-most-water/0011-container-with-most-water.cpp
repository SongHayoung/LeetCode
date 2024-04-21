class Solution {
public:
    int maxArea(vector<int>& A) {
        int res = 0, l = 0, r = A.size() - 1;
        while(l < r) {
            int w = r - l ;
            int h = min(A[l], A[r]);
            res = max(res, w * h);
            if(h == A[l]) l++;
            else r--;
        }
        return res;
    }
};