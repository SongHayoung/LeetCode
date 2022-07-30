class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& A) {
        int n = A.size(), ma = -1;
        vector<int> lpsum(n), rpsum(n), res;
        for(int i = 0; i < n; i++) {
            lpsum[i] = (i ? lpsum[i-1] : 0) + (A[i] == 0);
        }
        for(int i = n - 1; i >= 0; i--) {
            rpsum[i] = (i + 1 < n ? rpsum[i+1] : 0) + (A[i] == 1);
        }
        for(int i = -1; i < n; i++) {
            int sum = (i >= 0 ? lpsum[i] : 0) + (i + 1 < n ? rpsum[i+1] : 0);
            if(sum == ma) res.push_back(i+1);
            else if(sum > ma) {
                ma = sum;
                res.clear();
                res.push_back(i+1);
            }
        }
        return res;
    }
};