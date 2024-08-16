class Solution {
public:
    int minMoves(vector<vector<int>>& A) {
        vector<int> s1, s2;
        for(int i = 0; i < A.size(); i++) {
            s1.push_back(A[i][0]);
            s2.push_back(A[i][1]);
        }
        sort(begin(s1), end(s1));
        sort(begin(s2), end(s2));
        int res = 0;
        for(int i = 0; i < A.size(); i++) {
            res += abs(i - s1[i]) + abs(i - s2[i]);
        }
        return res;
    }
};