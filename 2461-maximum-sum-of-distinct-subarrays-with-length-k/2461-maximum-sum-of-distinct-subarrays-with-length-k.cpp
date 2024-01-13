class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        // [1,2,3,4,5,6,7] , when k = 4
        //      ^ ^ ^
        //  sum : 10 - 1 + 5 = 14
        //  distinct elem [4], {{2,1},{3,1},{4,1},{5,1}} 
        //  (n - k)th index;
        //  nums.size() < k
        
        long long bestSum = 0, sum = 0;
        unordered_map<int,int> freq;
        
        auto add = [&](int idx) {
            sum += nums[idx];
            freq[nums[idx]] += 1;
        };
        auto del = [&](int idx) {
            sum -= nums[idx];
            if(--freq[nums[idx]] == 0) {
                freq.erase(nums[idx]);
            }
        };
        auto update = [&]() {
            if(freq.size() == k) {
                bestSum = max(bestSum, sum);
            }
        };
        int right = 0, left = 0;
        while(right < k) add(right++);
        update();
        for(;right < nums.size(); right++, left++) {
            add(right);
            del(left);
            update();
        }
        
        return bestSum;
    }
};