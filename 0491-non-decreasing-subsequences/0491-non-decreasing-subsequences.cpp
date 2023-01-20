class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        for(int i = 0; i < n - 1; i++) {
            vector<vector<int>> cur;
            cur.push_back({nums[i]});
            auto sorting = [](const vector<int>& a, const vector<int>& b) {return a.back() == b.back() ? a.size() < b.size() : a.back() < b.back(); };
            for(int j = i + 1; j < n; j++) {
                int sz = cur.size();
                for(int k = 0; k < sz and cur[k].back() <= nums[j]; k++) {
                    vector<int> NEW(cur[k].begin(), cur[k].end());
                    NEW.push_back(nums[j]);
                    cur.push_back(NEW);
                }
                sort(cur.begin(), cur.end(), sorting);
            }
            res.insert(res.end(), cur.begin() + 1, cur.end());
        }
        set<vector<int>> filter(res.begin(), res.end());
        return vector<vector<int>> (filter.begin(),filter.end());
    }
};