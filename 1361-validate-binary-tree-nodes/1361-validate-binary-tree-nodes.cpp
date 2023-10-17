
class Solution {
    int dfs(int u, vector<int>& l, vector<int>& r) {
        int res = 1;
        if(l[u] != -1) res += dfs(l[u], l, r);
        if(r[u] != -1) res += dfs(r[u], l, r);
        return res;
    }
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int par[10001];
        memset(par, -1, sizeof par);
        for(int i = 0; i < n; i++) {
            int l = leftChild[i], r = rightChild[i];
            if(l != -1 and par[l] != -1) return false;  //more then two parent
            if(r != -1 and par[r] != -1) return false;
            if(l != -1) par[l] = i;
            if(r != -1) par[r] = i;
        }
        int root = -1;
        for(int i = 0; i < n and root == -1; i++) {
            if (par[i] == -1) root = i;
        }
        if(root == -1) return false;    //cycle

        return dfs(root, leftChild, rightChild) == n;   // only one tree
    }
};