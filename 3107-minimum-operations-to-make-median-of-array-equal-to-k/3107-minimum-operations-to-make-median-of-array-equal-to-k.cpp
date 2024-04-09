class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& A, int k) {
        sort(begin(A), end(A));
        int n = A.size();
        int l2 = A.size() / 2;
        long long res = 0;
        for(int i = 0; i < l2; i++) {
            if(A[i] > k) {
                res += A[i] - k;
                A[i] = k;
            }
        }
        for(int i = l2 + 1; i < A.size(); i++) {
            if(A[i] < k) {
                res += k - A[i];
                A[i] = k;
            }
        }

        return res + abs(k - A[l2]);
    }
};