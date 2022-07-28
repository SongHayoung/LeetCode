class Solution {
public:
    int minimumRefill(vector<int>& A, int capacityA, int capacityB) {
        int res = 0, a = capacityA, b = capacityB, l = 0, r = A.size() - 1;
        while(l <= r) {
            if(l == r) {
                int ma = max(a,b);
                if(ma < A[l]) res++;
            } else {
                if(a >= A[l]) a -= A[l];
                else {
                    res++; a = capacityA - A[l];
                }
                if(b >= A[r]) b -= A[r];
                else {
                    res++; b = capacityB - A[r];
                }
            }
            l++,r--;
        }
        return res;
        
    }
};