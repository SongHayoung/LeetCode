class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            int g = nums[i];
            if(g == k) res += 1;
            for(int j = i + 1; j < nums.size() and g % k == 0; j++) {
                g = __gcd(g,nums[j]);
                if(g == k) res += 1;
            }
        }
        return res;
    }
};