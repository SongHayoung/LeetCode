class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& A, int k) {
        int res = 0, n = A.size();
        for(int i = 0; i < k - 1; i++) A.push_back(A[i]);
        int l = 0, r = 0;
        while(l < n) {
            int fl = A[l];
            while(r < A.size() and A[r] == fl) {
                r++;
                fl = !fl;
            }
            res += max(0,(r - l + 1) - k);
            l = r;
        }
        return res;
    }
};
