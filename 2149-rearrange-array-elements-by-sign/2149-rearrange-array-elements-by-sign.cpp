class Solution {
public:
    vector<int> rearrangeArray(vector<int>& A) {
        vector<int> neg, pos;
        int n = A.size();
        for(auto& a : A) {
            if(a < 0) neg.push_back(a);
            else pos.push_back(a);
        }
        for(int i = 0, j = 0; i < n; i += 2, j++) {
            A[i] = pos[j];
        }
        for(int i = 1, j = 0; i < n; i += 2, j++) {
            A[i] = neg[j];
        }
        return A;
    }
};