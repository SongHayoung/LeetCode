class Solution {
public:
    long long largestPerimeter(vector<int>& A) {
        sort(begin(A), end(A));
        long long res = -1, sum = A[0] + A[1];
        for(int i = 2; i < A.size(); i++) {
            if(sum > A[i]) res = max(res, sum + A[i]);
            sum += A[i];
        }
        return res;
    }
};