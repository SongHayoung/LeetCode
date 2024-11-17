class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        long long res = INT_MAX, sum = 0;
        deque<pair<long long,long long>> dq{{0,-1}};
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while(dq.size() and dq.back().first >= sum) dq.pop_back();
            dq.push_back({sum,i});
            while(dq.size() > 1 and dq.back().first - dq.front().first >= k) {
                res = min(res, dq.back().second - dq.front().second);
                dq.pop_front();
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};