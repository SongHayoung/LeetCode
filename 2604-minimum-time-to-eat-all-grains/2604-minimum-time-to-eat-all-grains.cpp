class Solution {
    bool helper(vector<int>& A, vector<int>& B, int t) {
        int j = 0;
        for(int i = 0; i < A.size() and j < B.size(); i++) {
            int until = A[i];
            if(A[i] >= B[j]) {
                int len = A[i] - B[j];
                if(len > t) return false;
                int x = B[j] + (t - len);
                until = max(until, x);
                until = max(until, (t - len) / 2 + A[i]);
            } else until += t;
            while(j < B.size() and B[j] <= until) j++;
        }
        return j == B.size();
    }
public:
    int minimumTime(vector<int>& A, vector<int>& B) {
        sort(begin(A), end(A));
        sort(begin(B), end(B));
        int l = 0, r = INT_MAX, res = r;
        while(l <= r) {
            int m = l + (r - l) / 2;
            bool ok = helper(A,B,m);
            if(ok) {
                r = m - 1;
                res = m;
            } else l = m + 1;
        }
        return res;
    }
};