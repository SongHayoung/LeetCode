
class Solution {
    int helper(vector<int>& A, unordered_map<int,int>& mp) {
        int res = 0;
        vector<int> vis(A.size());
        for(int i = 0; i < A.size(); i++) {
            int now = mp[i];
            if(A[now] == i) vis[now] = true;
            if(vis[now]) continue;
            if(i) res += 1;
            else res -= 1;
            while(!vis[now]) {
                vis[now] = true;
                now = mp[A[now]];
                res += 1;
            }
        }
        return res;
    }
public:
    int sortArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> p,b;
        for(int i = 0; i < n; i++) {
            p[i] = i;
            b[i] = i - 1;
        }
        b[0] = n - 1;
        return min(helper(nums,p),helper(nums,b));
    }
};