class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == key) {
                int st = max(i - k, res.empty() ? 0 : res.back() + 1);
                int ed = min((int)nums.size() - 1, i + k);
                for(int j = st; j <= ed; j++) {
                    res.push_back(j);
                }
            }
        }
        return res;
    }
};