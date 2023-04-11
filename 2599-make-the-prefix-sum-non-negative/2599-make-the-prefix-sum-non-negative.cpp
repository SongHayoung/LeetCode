class Solution {
public:
    int makePrefSumNonNegative(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> q;
        long long res = 0, sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(nums[i] <= 0) q.push(nums[i]);
            while(sum < 0) {
                sum -= q.top(); q.pop(); res += 1;
            }
        }
        return res;
    }
};