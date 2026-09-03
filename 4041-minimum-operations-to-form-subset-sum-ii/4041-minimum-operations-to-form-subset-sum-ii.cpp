
class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {
        vector<long long> dp(sum + 1, INT_MAX);
        dp[0] = 0;
        for(auto& n : nums) {
            unordered_map<int,int> cost;
            queue<int> q;
            auto push = [&](int val, int c) {
                if(val > sum) return;
                if(cost.count(val)) return;
                cost[val] = c;
                q.push(val);
            };
            int c = 0;
            while(n) {
                push(n,c);
                n /= 2, c++;
            }
            while(q.size()) {
                auto n = q.front(); q.pop();
                push(n * 2, cost[n]+1);
            }
            for(int s = sum; s; s--) {
                for(auto& [k,v] : cost) {
                    if(s < k) continue;
                    dp[s] = min(dp[s], dp[s-k] + v);
                }
            }
        }
        return dp[sum] == INT_MAX ? -1 : dp[sum];
    }
};
