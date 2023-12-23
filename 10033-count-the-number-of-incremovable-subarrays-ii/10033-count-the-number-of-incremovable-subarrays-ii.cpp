class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& A) {
        A.insert(begin(A),-1);
        A.push_back(1e9 + 10);
        long long res = 0, le = 0, ri = A.size() - 1, n = A.size();
        for(int i = 0; i < n - 1; i++) {
            if(A[i] < A[i+1]) le = i+1;
            else break;
            if(i == n - 2) return (n - 2) * (n - 1) / 2;
        }
        while(ri - 1 > le and A[ri-1] > A[le] and (ri < n ? A[ri-1] < A[ri] : true)) ri--;
        while(le) {
            res += (n - ri);
            le -= 1;
            if(le >= 0) {
                while(ri - 1 > le and A[ri-1] > A[le] and (ri < n ? A[ri-1] < A[ri] : true)) ri--;
            }
        }
        res += (n - ri);
        return res;
    }
};
