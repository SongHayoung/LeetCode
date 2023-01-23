class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> adj(n+1,0), radj(n+1,0);
        for(auto& t : trust) {
            radj[t[0]]++;
            adj[t[1]]++;
        }
        for(int i = 1; i <= n; i++) {
            if(!radj[i] and adj[i] == n - 1)
                return i;
        }
        
        return -1;
    }
};