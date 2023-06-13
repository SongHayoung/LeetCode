class Solution {
public:
    int equalPairs(vector<vector<int>>& A) {
        unordered_map<string,int> mp;
        int n = A.size(), m = A[0].size();
        for(int i = 0; i < n; i++) {
            string now = "";
            for(int j = 0; j < m; j++) {
                now += to_string(A[i][j]) + "#";
            }
            mp[now]++;
        }
        int res = 0;
        for(int i = 0; i < m; i++) {
            string now = "";
            for(int j = 0; j < n; j++) {
                now += to_string(A[j][i]) + "#";
            }
            res += mp[now];
        }
        return res;
    }
};