class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        int ma = 0, m = mat[0].size();
        vector<int> ho(m,0), ve(m,0), dia(m,0), anti(m,0);
        for(auto& row : mat) {
            for(int i = 0, j = m - 1; i < m; i++, j--) {
                if(i == 0) ho[i] = row[i];
                else ho[i] = row[i] ? ho[i-1] + 1 : 0;
                
                ve[i] = row[i] ? ve[i] + 1 : 0;
                
                if(j) dia[j] = row[j] ? dia[j-1] + 1 : 0;
                else dia[j] = row[j];
                
                if(i != m - 1) anti[i] = row[i] ? anti[i + 1] + 1 : 0;
                else anti[i] = row[i];
                
                ma = max({ma, ho[i], ve[i], dia[j], anti[i]});
            }
        }
        return ma;
    }
};