class Solution {
    int uf[101010];
    int find(int u) {
        return uf[u] == u ? u : uf[u] = find(uf[u]);
    }
    void uni(int u, int v) {
        int pu = find(u), pv = find(v);
        uf[pu] = uf[pv] = min(pu,pv);
    }
public:
    int countComponents(vector<int>& nums, int threshold) {
        int res = 0;
        for(int i = 0; i < nums.size(); i++) uf[i] = i;
        vector<int> cover(threshold + 1, -1);
        for(int i = 0; i < nums.size(); i++) {
            for(int j = nums[i]; j <= threshold; j += nums[i]) {
                if(cover[j] == -1) cover[j] = i;
                else {
                    uni(cover[j], i);
                    if(j == nums[i]) break;
                }
            }
        }
        for(int i = 0; i < nums.size(); i++) if(find(i) == i) res++;
        return res;
    }
};