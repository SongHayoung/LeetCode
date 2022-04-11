class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> num;
        for(int i = 0; i <= nums.size(); i++)
            num.insert(i);
        for(auto& n : nums)
            num.erase(n);

        return *lower_bound(begin(num), end(num), 0);
    }
};