class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> S{nums[0], nums[1]};
        for(int i = 2; i < nums.size(); i++) {
            S.push_back(nums[i]);
            sort(rbegin(S), rend(S));
            S.pop_back();
        }
        return (S[0] - 1) * (S[1] - 1);
    }
};