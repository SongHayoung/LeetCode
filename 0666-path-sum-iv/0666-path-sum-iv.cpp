class Solution {
    int tree[5][1<<5], res;
    void dfs(int dep, int p, int sum) {
        sum += tree[dep][p];
        bool fl = true;
        if(tree[dep+1][p*2] != -1) {
            dfs(dep+1,p*2,sum);
            fl = false;
        }
        if(tree[dep+1][p*2+1] != -1) {
            dfs(dep+1,p*2+1,sum);
            fl = false;
        }
        if(fl) res += sum;
    }
public:
    int pathSum(vector<int>& nums) {
        memset(tree,-1,sizeof tree);
        for(auto& x : nums) {
            int d = x / 100 - 1, p = (x / 10) % 10 - 1, v = x % 10;
            tree[d][p] = v;
        }
        res = 0;
        dfs(0,0,0);
        return res;
    }
};