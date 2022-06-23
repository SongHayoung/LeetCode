class Solution {
    string parse(vector<vector<char>>& A, int p) {
        int i = 0, j = p;
        int n = A.size(), m = A[0].size();
        string res = "";
        while(i < n and j < m) {
            res.push_back(A[i++][j++]);
        }
        return res;
    }
public:
    string decodeCiphertext(string s, int rows) {
        if(rows == 1) return s;
        int n = s.length();
        vector<vector<char>> A(rows, vector<char>(n / rows));
        for(int i = 0, k = 0; i < rows; i++) {
            for(int j = 0; j < n / rows; j++) {
                A[i][j] = s[k++];
            }
        }
        string res = "";
        for(int i = 0; i < n / rows; i++) {
            res += parse(A, i);
        }
        while(!res.empty() and res.back() == ' ') res.pop_back();
        return res;
    }
};