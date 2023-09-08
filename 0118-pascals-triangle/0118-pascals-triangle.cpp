class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 1) return {{1}};
        vector<vector<int>> res = {{1},{1,1}};
        numRows -= 2;
        while(numRows--) {
            vector<int> row;
            row.push_back(1);
            for(int i = 0; i < res.back().size() - 1; i++) {
                row.push_back(res.back()[i] + res.back()[i+1]);
            }
            row.push_back(1);
            res.push_back(row);
        }
        return res;
    }
};