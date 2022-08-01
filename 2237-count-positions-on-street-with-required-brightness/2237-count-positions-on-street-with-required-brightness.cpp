class Solution {
public:
    int meetRequirement(int n, vector<vector<int>>& lights, vector<int>& requirement) {
        vector<int> psum(n + 1);
        for(auto& light : lights) {
            int mid = light[0], len = light[1];
            int l = max(0,mid-len), r = min(n,mid + len + 1);
            psum[l] += 1;
            psum[r] -= 1;
        }
        int res = 0;
        for(int i = 0; i < n; i++) {
            psum[i] = (i ? psum[i-1] : 0) + psum[i];
            res += (psum[i] >= requirement[i]);
        }
        return res;
    }
};