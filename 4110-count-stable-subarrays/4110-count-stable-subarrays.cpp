class Solution {
public:
    vector<long long> countStableSubarrays(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<long long> chunks{1}, at(n, 0), st{0}, ed{0};
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < nums[i-1]) chunks.push_back(1), st.push_back(i), ed.push_back(i);
            else chunks.back()++, ed.back() = i;
            at[i] = chunks.size() - 1;
        }
        auto cnt = [&](long long l, long long r) {
            return (r - l + 1) * (r - l + 2) / 2;
        };
        vector<long long> pre{0};
        for(int i = 0; i < chunks.size(); i++) pre.push_back(pre.back() + chunks[i] * (chunks[i] + 1) / 2);
        auto qry = [&](int l, int r) {
            if(l > r) return 0ll;
            return pre[r+1] - pre[l];
        };
        vector<long long> res;
        for(auto& q : queries) {
            long long l = q[0], r = q[1];
            if(at[l] == at[r]) res.push_back(cnt(l,r));
            else {
                res.push_back(qry(at[l] + 1, at[r] - 1) + cnt(l, ed[at[l]]) + cnt(st[at[r]], r));
            }
        }
        return res;
    }
};