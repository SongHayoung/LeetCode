class Solution {
public:
    int minimumSwap(string A, string B) {
        int xy = 0, yx = 0, n = A.length();
        for(int i = 0; i < n; i++) {
            if(A[i] == 'x' and B[i] == 'y') xy++;
            else if(A[i] == 'y' and B[i] == 'x') yx++;
        }
        if(xy % 2 != yx % 2) return -1;
        return xy / 2 + yx / 2 + (xy & 1) * 2;
        
    }
};