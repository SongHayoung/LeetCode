class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;
        for(auto n : nums) {
            string s = to_string(n);
            for(auto ch : s) res.push_back(ch-'0');
        }
        return res;
    }
};