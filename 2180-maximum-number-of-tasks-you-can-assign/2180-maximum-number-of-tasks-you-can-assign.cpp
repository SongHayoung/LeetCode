class Solution {
    bool helper(vector<int>& A, multiset<int>& ms, int p, int s) {
        int n = ms.size();
        for(int i = n - 1; i >= 0; i--) {
            auto it = prev(end(ms));
            if(*it < A[i]) {
                if(!p) return false;
                it = ms.lower_bound(A[i] - s);
                --p;
                if(it == end(ms)) return false;
            }
            ms.erase(it);
        }
        return true;
    }
public:
    int maxTaskAssign(vector<int>& A, vector<int>& B, int pills, int strength) {
        sort(begin(A), end(A));
        sort(begin(B), end(B));
        int l = 0, r = min(A.size(), B.size()), res = l;
        while(l <= r) {
            int m = l + (r - l) / 2;
            multiset<int> ms(end(B) - m, end(B));
            bool ok = helper(A,ms,pills,strength);
            if(ok) {
                res = m;
                l = m + 1;
            } else r = m - 1;
        }
        return res;
    }
};