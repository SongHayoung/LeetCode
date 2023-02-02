class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int n = score.size();
        vector<int> ord(n);
        for(int i = 0; i < n; i++) ord[i] = i;
        sort(begin(ord), end(ord), [&](int i, int j) {
            return score[i][k] > score[j][k];
        });
        vector<vector<int>> res(n);
        for(int i = 0; i < n; i++) res[i] = score[ord[i]];
        return res;
    }
};