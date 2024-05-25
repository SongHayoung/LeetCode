class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& A, vector<int>& Q, int x) {
        vector<int> at;
        for(int i = 0; i < A.size(); i++) {
            if(A[i] == x) at.push_back(i);
        }
        vector<int> res;
        for(auto& q : Q) {
            if(q > at.size()) res.push_back(-1);
            else res.push_back(at[q-1]);
        }
        return res;
    }
};
