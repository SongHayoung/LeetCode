class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int> A(n);
        int p = 0, turn = 1;
        while(true) {
            if(A[p]) break;
            A[p] = 1;
            p = (p + turn * k) % n;
            turn += 1;
        }
        vector<int> res;
        
        for(int i = 0; i < n; i++) {
            if(!A[i]) res.push_back(i+1);
        }
        return res;
    }
};