class Solution {
    int id;
    vector<int> vis;
    bool dfs(vector<int>& A, int p) {
        if(vis[p]) return vis[p] == id;
        vis[p] = id;
        int n = A.size();
        int v = ((p + A[p]) % n + n) % n;
        if(A[p] * A[v] < 0) return false;
        return dfs(A, v);
    }
public:
    bool circularArrayLoop(vector<int>& nums) {
        vis = vector<int>(nums.size());
        id = 1;
        int n = nums.size();
        for(int i = 0; i < nums.size(); i++) {
            if((nums[i] % n) == 0) {
                vis[i] = -1;
            }
        }
        for(int i = 0; i < nums.size(); i++) if(dfs(nums,i)) {
            return true;
        } else id++;
        return false;
    }
};