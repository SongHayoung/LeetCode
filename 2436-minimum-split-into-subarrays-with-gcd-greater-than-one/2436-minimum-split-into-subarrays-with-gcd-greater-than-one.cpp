class Solution {
public:
    int minimumSplits(vector<int>& A) {
        int res = 1, g = A[0];
        for(int i = 1; i < A.size(); i++) {
            int gg = __gcd(g,A[i]);
            if(gg == 1) g = A[i], res += 1;
            else g = gg;
        }
        return res;
    }
};