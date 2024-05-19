class Solution {
public:
    bool canSortArray(vector<int>& A) {
        vector<int> S;
        while(A.size()) {
            int pc = __builtin_popcount(A.back());
            vector<int> X;
            while(A.size() and __builtin_popcount(A.back()) == pc) {
                X.push_back(A.back()); A.pop_back();
            }
            sort(begin(X), end(X));
            while(X.size()) {
                S.push_back(X.back()); X.pop_back();
            }
        }
        
        for(int i = 0; i < S.size() - 1; i++) {
            if(S[i] < S[i+1]) return false;
        }
        return true;
    }
};