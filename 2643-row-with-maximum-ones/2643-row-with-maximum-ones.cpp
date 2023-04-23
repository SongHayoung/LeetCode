class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int c= count(begin(mat[0]), end(mat[0]),1);
        vector<int> res{0,c};
        for(int i = 1; i < mat.size(); i++) {
            int c = count(begin(mat[i]), end(mat[i]), 1);
            if(res[1] < c) res = {i,c};
        }
        return res;
    }
};
