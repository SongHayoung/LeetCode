class Solution {
    int dfs(int u, int ma, unordered_set<int>& us, bool fl) {
        if(u > ma) return 0;
        if(us.count(u)) fl = !fl;
        int res = fl;
        res += dfs(u * 2, ma, us, fl);
        res += dfs(u * 2 + 1, ma, us, fl);
        return res;
    }
public:
    int numberOfNodes(int n, vector<int>& Q) {
        unordered_set<int> us;
        for(auto q : Q) {
            if(us.count(q)) us.erase(q);
            else us.insert(q);
        }
        return dfs(1,n,us,false);
    }
};