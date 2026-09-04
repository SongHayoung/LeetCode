class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int res = INT_MAX;

        bool inc = true;
        for(int i = 0; i < n; i++) {
            if(nums[i] != (nums[0] + i) % n) {
                inc = false;
                break;
            }
        }

        if(inc) {
            int k = nums[0];
            res = min(res, min((n - k) % n, k + 2));
        }

        bool dec = true;
        for(int i = 0; i < n; i++) {
            if(nums[i] != (nums[0] - i + n) % n) {
                dec = false;
                break;
            }
        }

        if(dec) {
            int k = (n - 1 - nums[0] + n) % n;
            res = min(res, 1 + min(k, (n - k) % n));
        }

        return res == INT_MAX ? -1 : res;
    }
};