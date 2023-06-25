class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            int x = to_string(nums[i])[0] - '0';
            for(int j = i + 1; j < nums.size(); j++) {
                int y = nums[j] % 10;
                if(__gcd(x,y) == 1) res += 1;
            }
        }
        return res;
    }
};
