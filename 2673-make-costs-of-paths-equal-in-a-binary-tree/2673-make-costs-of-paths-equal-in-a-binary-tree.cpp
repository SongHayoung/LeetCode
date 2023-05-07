class Solution {
    int res = 0;
    long long dfs(int u, vector<int>& C) {
        int real = u - 1;
        if(C.size() <= real) return -1;
        long long left = dfs(u * 2, C), right = dfs(u * 2 + 1, C);
        if(left == -1 and right == -1) return C[real];
        else if(left == -1 or right == -1) return max(left, right) + C[real];
        else {
            res += abs(left - right);
        }
        return max(left, right) + C[real];
    }
public:
    int minIncrements(int n, vector<int>& cost) {
        res = 0;
        dfs(1,cost);
        return res;
    }
};
