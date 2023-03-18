class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long res = 0;
        vector<int> mark(nums.size());
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> q;
        for(int i = 0; i < nums.size(); i++) q.push({nums[i], i});
        while(q.size()) {
            while(q.size() and mark[q.top().second]) q.pop();
            if(q.empty()) break;
            auto [x, idx] = q.top(); q.pop();
            mark[idx] = true;
            res += x;
            if(idx - 1 >= 0) mark[idx-1] = true;
            if(idx + 1 < nums.size()) mark[idx+1] = true;
        }
        return res;
    }
};
