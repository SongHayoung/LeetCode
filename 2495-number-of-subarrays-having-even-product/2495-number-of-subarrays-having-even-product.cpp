class Solution {
public:
    long long evenProduct(vector<int>& nums) {
        long long res = 0;
        vector<int> pos;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] % 2) continue;
            pos.push_back(i);
        }
        pos.push_back(nums.size());
        for(int i = 0; i < pos.size() - 1; i++) {
            res += (pos[i] + 1ll) * (pos[i+1] - pos[i]);
        }
        return res;
    }
};