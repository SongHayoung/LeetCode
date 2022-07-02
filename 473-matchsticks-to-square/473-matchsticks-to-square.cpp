class Solution {
    int sumMask(vector<int>& A, int mask) {
        int res = 0;
        for(int i = 0; i < A.size(); i++) {
            if(mask & (1<<i)) res += A[i];
        }
        return res;
    }
    bool knapsack(vector<int>& A, int mask, int target) {
        unordered_set<int> dp{0};
        
        for(int i = 0; i < A.size(); i++) {
            if(!(mask & (1<<i))) continue;
            unordered_set<int> dpp;
            for(auto& d : dp) {
                dpp.insert(d);
                dpp.insert(d + A[i]);
            }
            swap(dp, dpp);
        }
        
        return dp.count(target);
    }
public:
    bool makesquare(vector<int>& A) {
        long long sum = accumulate(begin(A), end(A), 0ll);
        if(sum % 4) return false;
        long long len = sum / 4, n = A.size();
        for(int sub = 1; sub < 1<<n; sub++) {
            if(sumMask(A,sub) != len * 2) continue;
            int sub2 = ~sub & ((1<<n) - 1);
            if(knapsack(A, sub, len) and knapsack(A, sub2, len))
                return true;
        }
        return false;
    }
};