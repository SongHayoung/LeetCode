class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& p, string s) {
        int m = s.length(), y = m + n, x = m + n;
        vector<int> Y(y * 2, m), X(x * 2, m);
        vector<int> res(m);
        for(int i = m - 1; i >= 0; i--) {
            Y[y] = X[x] = i;
            if(s[i] == 'U') y++;
            else if(s[i] == 'D') y--;
            else if(s[i] == 'L') x++;
            else x--;
            
            res[i] = min({m, Y[y - p[0] - 1], Y[y - p[0] + n], X[x - p[1] - 1], X[x - p[1] + n]}) - i;
        }
        return res;
    }
};