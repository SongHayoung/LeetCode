class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        vector<pair<int, int>> A;
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) mp[nums[i]] += cost[i];
        for(auto [k,v] : mp) A.push_back({k,v});
        sort(begin(A), end(A));
        vector<long long> dp(A.size());
        long long now = A[0].second, sum = 0, last = A[0].first;
        for(int i = 1; i < A.size(); i++) {
            long long d = A[i].first - last;
            sum += now * d;
            dp[i] += sum;
            now += A[i].second;
            last = A[i].first;
        }
        
        now = A.back().second, sum = 0, last = A.back().first;
        for(int i = A.size() - 2; i >= 0; i--) {
            long long d = last - A[i].first;
            sum += now * d;
            dp[i] += sum;
            now += A[i].second;
            last = A[i].first;
        }
        
        return *min_element(begin(dp), end(dp));
    }
};