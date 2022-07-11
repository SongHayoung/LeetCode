class Solution {
    int tree[6][33];
    int res = 0;
    void dfs(int d, int l, int sum) {
        int nd = d + 1, lc = l * 2 - 1, rc = l * 2;
        sum += tree[d][l];
        if(nd == 6 or (tree[nd][lc] == -1 and tree[nd][rc] == -1)) {
            res += sum;
        } else {
            if(tree[nd][lc] != -1) dfs(nd,lc,sum);
            if(tree[nd][rc] != -1) dfs(nd,rc,sum);
        }
    }
public:
    int pathSum(vector<int>& nums) {
        memset(tree, -1, sizeof tree);
        for(auto& n : nums) {
            int d = n / 100, l = (n / 10) % 10, v = n % 10;
            tree[d][l] = v;
        }
        dfs(1,1,0);
        return res;
    }
};