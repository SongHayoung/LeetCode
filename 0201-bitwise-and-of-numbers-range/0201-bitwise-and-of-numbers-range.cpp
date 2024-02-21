class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(!left or left == right) return left;
        int lgl = log2(left), lgr = log2(right);
        
        if(lgl != lgr) return 0;
        
        int res = 0, i = lgl;
        
        while(i >= 0) {
            int L = left & (1<<i), R = right & (1<<i);
            if(R and !L) return res;
            if(L == R) res |= L;
            i--;
        }
        
        return res;
    }
};