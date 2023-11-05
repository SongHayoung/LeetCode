class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> ind(n);
        for(auto e : edges) {
            int u = e[0], v = e[1];
            ind[v] += 1;
        }
        int root = -1;
        for(int i = 0; i < n; i++) {
            if(ind[i]) continue;
            if(root == -1) root = i;
            else return -1;
        }
        return root;
    }
};