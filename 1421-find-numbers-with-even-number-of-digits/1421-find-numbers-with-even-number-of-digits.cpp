class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res = 0;
        for(auto& n : nums) res += ((int)log10(n) & 1);
        return res;
    }
};