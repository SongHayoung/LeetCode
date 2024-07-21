
class Solution {
public:
    int minChanges(vector<int>& A, int k) {
        vector<int> pre(k + 100);
        int n = A.size();
        for(int i = 0; i < n / 2; i++) {
            int a = A[i], b = A[n-i-1];
            if(a < b) swap(a,b);
            int x = k - a, y = b;
            if(x < y) swap(x,y);
            pre[0] += 1;
            pre[a-b] -= 1;
            pre[a-b+1] += 1;
            pre[a-b+x+1] += 1;
        }
        int res = pre[0];
        for(int i = 1; i <= k; i++) {
            pre[i] += pre[i-1];
            res = min(res, pre[i]);
        }
        return res;
    }
};
