class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        reverse(begin(m), end(m));
        for(int i = 0; i < m.size(); i++)
            for(int j = i + 1; j < m.size(); j++)
                swap(m[i][j],m[j][i]);
    }
};
