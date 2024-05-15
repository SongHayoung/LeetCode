class Solution {
    bool helper(vector<int>& A, int k, int m) {
        int bit = 0, base = 0;
        for(auto& x : A) {
            if((bit & m) != bit) {
                k--;
                bit &= x;
            } else {
                base |= bit;
                bit = x;
            }
            if(k < 0) return false;
        }
        if(k) return true;
        base |= bit;
        return (base & m) == base;
    }
public:
    int minOrAfterOperations(vector<int>& A, int k) {
        int l = 0, r = INT_MAX, res = INT_MAX;
        while(l <= r) {
            int m = l + (r - l) / 2;
            bool ok = helper(A,k,m);
            if(ok) {
                r = m - 1;
                res = m;
            } else l = m + 1;
        }
        return res;
    }
};