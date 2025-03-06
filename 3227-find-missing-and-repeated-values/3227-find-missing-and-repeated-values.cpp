class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& A) {
        unordered_set<int> us;
        unordered_map<int, int> mp;
        int n = A.size();
        vector<int> res{0,0};
        for(int i = 1; i <= n * n; i++) us.insert(i);
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
            mp[A[i][j]] += 1;
            if(mp[A[i][j]] == 2) res[0] = A[i][j];
            us.erase(A[i][j]);
        }
        res[1] = *begin(us);
        return res;
    }
};

