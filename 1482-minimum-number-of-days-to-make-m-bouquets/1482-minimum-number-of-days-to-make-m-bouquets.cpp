class Solution {
    bool helper(vector<int>& A, int t, int c, int d) {
        for(int i = 0, cnt = 0; i < A.size() and t; i++) {
            if(A[i] <= d) cnt++;
            else cnt = 0;
            if(cnt == c) {
                t--;
                cnt = 0;
            }
        }
        return t == 0;
    }
public:
    int minDays(vector<int>& A, int m, int k) {
        int n = A.size();
        if(1ll * m * k > n) return -1;
        int l = 1, r = 1e9, res = 1e9;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            bool ok = helper(A,m,k,mid);
            if(ok) {
                res = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        return res;
    }
};