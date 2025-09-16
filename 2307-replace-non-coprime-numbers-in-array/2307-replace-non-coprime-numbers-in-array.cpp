class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            res.push_back(nums[i]);
            while(res.size() >= 2) {
                int sz = res.size();
                int g = __gcd(res[sz - 1], res[sz - 2]);
                if(g <= 1) break;
                else {
                    int num = res[sz - 1] / g * res[sz - 2];
                    res.pop_back();
                    res.pop_back();
                    res.push_back(num);
                }
            }
        }
        return res;
    }
};