class Solution {
public:
    vector<int> maxNumber(vector<int>& A, vector<int>& B, int k) {
        int n = A.size(), m = B.size();
        if(n > m) return maxNumber(B, A, k);
        
        vector<int> res;
        for(int i = max(k - m, 0); i <= n; i++) {
            if((k - i) < 0) break;
            res = max(res, merge(pick(A, i), pick(B, k - i)));
        }
        return res;
    }
    deque<int> pick(vector<int>& A, int pick) {
        deque<int> res;
        int n = A.size(), remove = n - pick;
        for(int i = 0; i < n; i++) {
            while(remove and !res.empty() and res.back() < A[i]) {
                remove--;
                res.pop_back();
            }
            res.push_back(A[i]);
        }
        res.resize(pick);
        
        return res;
    }
    
    vector<int> merge(deque<int> A, deque<int> B) {
        vector<int> res;
        while(!A.empty() or !B.empty()) {
            deque<int>& best = A > B ? A : B;
            res.push_back(best[0]);
            best.pop_front();
        }
        return res;
    }
};