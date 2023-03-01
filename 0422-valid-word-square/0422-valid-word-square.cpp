class Solution {
public:
    bool validWordSquare(vector<string>& s) {
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(s[i].size() > n) return false;
            for(int j = 0; j < s[i].size(); j++) {
                if(s[i][j] != s[j][i]) return false;
            }
        }
        return true;
    }
};