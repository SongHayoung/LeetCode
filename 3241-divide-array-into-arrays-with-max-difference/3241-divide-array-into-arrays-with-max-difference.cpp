class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& A, int k) {
        int n = A.size();
        if(n % 3) return {};
        sort(begin(A), end(A));
        vector<vector<int>> res;
        for(int i = 0; i < n; i += 3) {
            vector<int> now{A[i], A[i+1], A[i+2]};
            if(now.back() - now.front() > k) return {};
            res.push_back(now);
        }
        return res;
    }
};