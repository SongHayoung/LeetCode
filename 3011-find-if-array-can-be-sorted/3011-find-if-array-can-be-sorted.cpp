class Solution {
public:
    bool canSortArray(vector<int>& A) {
        vector<int> S;
        while(A.size()) {
            int pc = __builtin_popcount(A.back());
            int ma = INT_MIN, mi = INT_MAX;
            while(A.size() and __builtin_popcount(A.back()) == pc) {
                mi = min(mi, A.back());
                ma = max(ma, A.back());
                A.pop_back();
            }
            S.push_back(ma);
            S.push_back(mi);
        }
        
        for(int i = 0; i < S.size() - 1; i++) {
            if(S[i] < S[i+1]) return false;
        }
        return true;
    }
};