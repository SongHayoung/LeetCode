class Solution {
public:
    vector<int> numberGame(vector<int>& A) {
        vector<int> res;
        sort(begin(A), end(A));
        for(int i = 0; i < A.size(); i+=2) {
            res.push_back(A[i+1]);
            res.push_back(A[i]);
        }
        return res;
    }
};