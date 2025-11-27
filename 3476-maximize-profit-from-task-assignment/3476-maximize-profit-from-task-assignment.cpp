class Solution {
public:
    long long maxProfit(vector<int>& workers, vector<vector<int>>& tasks) {
        unordered_map<long long, long long> w;
        for(auto& worker : workers) w[worker]++;
        unordered_map<long long, vector<long long>> t;
        for(auto& task : tasks) t[task[0]].push_back(task[1]);
        long long res = 0, additional = 0;
        for(auto& [k,v] : t) {
            sort(begin(v), end(v));
            int cnt = w.count(k) ? w[k] : 0;
            while(v.size() and cnt) {
                cnt--;
                res += v.back(); v.pop_back();
            }
            if(v.size()) additional = max(additional, v.back());
        }
        return res + additional;
    }
};