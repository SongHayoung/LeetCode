class Solution {
public:
    int partitionArray(vector<int>& A, int k) {
        sort(begin(A), end(A));
        int n = A.size(), res = 0;

        for(int i = 0, ma = INT_MIN; i < n; i++) {
            if(ma >= A[i]) continue;
            else {
                res++;
                ma = A[i] + k;
            }
        }

        return res;
    }
};