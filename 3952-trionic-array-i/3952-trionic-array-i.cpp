
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        long long n = nums.size();
        vector<array<long long,3>> inc;
        for(int i = 0; i < n - 1; i++) {
            int j = i + 1;
            if(nums[j] <= nums[i]) continue;
            inc.push_back({i,i,nums[i]});
            while(j < n and nums[j] > nums[j-1]) {
                inc.back()[1] = j;
                inc.back()[2] += nums[j];
                j++;
            }
            i = j - 1;
        }
        if(inc.size() != 2) return false;
        auto dec = [&](long long l, long long r) {
            for(int i = l; i < r; i++) {
                if(nums[i] <= nums[i+1]) return false;
            }
            return true;
        };
        return inc[0][0] == 0 and inc[1][1] == n - 1 and dec(inc[0][1], inc[1][0]);
    }
};