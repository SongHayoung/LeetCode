class Solution {
public:
    vector<int> getStrongest(vector<int>& A, int k) {
        sort(begin(A), end(A));
        int n = A.size(), l = 0, r = n - 1, med = A[(n-1)/2];
        vector<int> res;
        while(res.size() < k) {
            
            int left = abs(A[l] - med), right = abs(A[r] - med);
            if(left <= right) {
                res.push_back(A[r--]);
            } else if(left > right) {
                res.push_back(A[l++]);
            }
        }
        return res;
    }
};