int po[1<<13], vis[1<<13][100];
class Solution {
public:
    vector<int> concatenatedDivisibility(vector<int>& nums, int mod) {
        memset(vis,0,sizeof vis);
        memset(po,-1,sizeof po);
        sort(begin(nums), end(nums));
        int n = nums.size();
        vector<vector<array<int,3>>> go(1<<n, vector<array<int,3>>(mod, {-1,-1,-1}));
        vis[0][0] = 1, po[0] = 1;
        auto bit = [&](int mask, int u) {
            return (mask >> u) & 1;
        };
        for(int mask = 0; mask < 1<<n; mask++) {
            int p = po[mask];
            for(int rem = 0; rem < mod; rem++) {
                if(!vis[mask][rem]) continue;
                for(int u = n - 1; u >= 0; u--) {
                    if(bit(mask,u)) continue;
                    int rrem = (rem + p * nums[u]) % mod;
                    int mmask = mask | 1<<u;
                    if(po[mmask] == -1) {
                        int len = to_string(nums[u]).length(), pp = p;
                        for(int i = 0; i < len; i++) pp = pp * 10 % mod;
                        po[mmask] = pp;
                    }
                    if(!vis[mmask][rrem]) {
                        vis[mmask][rrem] = 1;
                        go[mmask][rrem] = {mask,rem, u};
                    } else {
                        if(go[mmask][rrem][2] > u) {
                            go[mmask][rrem] = {mask,rem, u};
                        }
                    }
                }
            }
        }
        int mask = (1<<n) - 1, rem = 0;
        if(!vis[mask][rem]) return {};
        vector<int> res;
        for(int i = 0; i < n; i++) {
            auto [mmask, rrem, who] = go[mask][rem];
            res.push_back(nums[who]);
            mask = mmask, rem = rrem;
        }
        return res;
    }
};