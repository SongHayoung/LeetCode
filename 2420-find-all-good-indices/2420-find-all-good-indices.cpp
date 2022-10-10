class Solution {
public:
    vector<int> goodIndices(vector<int>& A, int k) {
        int n = A.size();
        vector<int> inc(n,1), dec(n,1);
        for(int i = 1; i < n; i++) if(A[i-1] >= A[i]) dec[i] = dec[i-1] + 1;
        for(int i = n - 2; i >= 0; i--) if(A[i+1] >= A[i]) inc[i] = inc[i+1] + 1;
        vector<int> res;
        for(int i = k; i < n - k; i++) {
            if(inc[i+1] >= k and dec[i-1] >= k) res.push_back(i);
        }
        return res;
    }
};
