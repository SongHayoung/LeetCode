class Solution {
public:
    vector<int> rearrangeArray(vector<int>& A) {
        auto B = A;
        sort(begin(B), end(B));
        int l = 0, r = A.size() - 1;
        for(int i = 0; i < A.size(); i++) {
            if(i & 1) A[i] = B[r--];
            else A[i] = B[l++];
        }
        return A;
    }
};