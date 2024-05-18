class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& B, vector<int>& A) {
        multiset<int> ms;
        int n = A.size(), res = 0;
        for(auto& x : B) ms.insert(x);
        vector<int> match(n);
        {
            for(int i = n - 1, best = INT_MAX; i >= 0; i--) {
                best = min(best, A[i]);
                auto it = ms.upper_bound(best);
                if(it != begin(ms)) {
                    --it;
                    match[i] = *it;
                    ms.erase(it);
                }
            }
            res = B.size() - ms.size();
        }
        for(int i = 0, best = INT_MAX; i < n; i++) {
            best = min(best, A[i]);
            if(match[i]) {
                ms.insert(match[i]);
            }
            auto it = ms.upper_bound(best);
            if(it != begin(ms)) {
                --it;
                ms.erase(it);
            }
            res = max(res, (int)(B.size() - ms.size()));
        }
        return res;
    }
};