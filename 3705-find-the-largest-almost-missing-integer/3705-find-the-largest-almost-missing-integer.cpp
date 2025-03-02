class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,vector<int>> ord;
        for(int i = 0; i < n; i++) ord[nums[i]].push_back(i);
        unordered_map<int,int> freq;
        for(auto& [x, pos] : ord) {
            int cnt = 0, m = pos.size();
            for(int i = 0; i < m; i++) {
                int le = max(pos[i] - k + 1, 0), ri = min(n - k, pos[i]);
                if(i) le = max(le, pos[i-1] + 1);
                cnt += max(0, ri - le + 1);
            }
            
            freq[x] = cnt;
        }
        int res = -1;
        for(auto& [k,v] : freq) if(v == 1) res = max(res, k);
        return res;
    }
};