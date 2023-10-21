class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size(), res = nums.back();
        priority_queue<pair<int,int>> pq;
        pq.push({0,n});
        for(int i = n - 1; i >= 0; i--) {
            while(pq.top().second > i + k) {
                pq.pop();
            }
            int sum = max(pq.top().first + nums[i], nums[i]);
            
            while(!pq.empty() and pq.top().first <= sum) pq.pop();
            pq.push({sum, i});
            res = max(res, sum);
        }
        return res;
    }
};