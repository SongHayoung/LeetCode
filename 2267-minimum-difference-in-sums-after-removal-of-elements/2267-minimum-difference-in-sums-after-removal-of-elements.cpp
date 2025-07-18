class Solution {
    long long dp[100001];
public:
    long long minimumDifference(vector<int>& nums) {
        long long n = nums.size()/3, lsum = 0, rsum = 0, res;
        priority_queue<int> lq;
        priority_queue<int, vector<int>, greater<int>> rq;
        for(int i = 0; i < n; i++) {
            lsum += nums[i];
            lq.push(nums[i]);
        }
        for(int i = 2*n; i < 3*n; i++) {
            rsum += nums[i];
            rq.push(nums[i]);
        }
        dp[0]= lsum;
        for(int i = n; i < 2*n; i++) {
            if(lq.top() > nums[i]) {
                lsum = lsum + nums[i] - lq.top();
                lq.pop();
                lq.push(nums[i]);
            }
            dp[i - n + 1] = lsum;
        }
        res = dp[n]-rsum;
        for(int i = 2*n-1; i >= n; i--) {
            if(rq.top() < nums[i]) {
                rsum = rsum + nums[i] - rq.top();
                rq.pop();
                rq.push(nums[i]);
            }
            res = min(res, dp[i-n] - rsum);
        }

        return res;
    }
};