class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        vector<pair<int, int>> SQ;
        for(int i = 0; i < queries.size(); i++) SQ.push_back({queries[i], i});
        sort(begin(SQ), end(SQ));
        unordered_map<int, int> freq;
        unordered_map<int, vector<int>> mp;
        for(auto log : logs) mp[log[1]].push_back(log[0]);
        vector<int> res(queries.size());
        set<int> times;
        for(auto [k,v] : mp) times.insert(k), times.insert(k + x + 1);
        for(auto q : queries) times.insert(q);
        int j = 0;
        for(auto i : times) {
            if(j == queries.size()) break;
            for(auto s : mp[i]) freq[s] += 1;
            for(auto s : mp[i-x-1]) if(--freq[s] == 0) freq.erase(s);
            if(i == SQ[j].first) {
                res[SQ[j].second] = n - freq.size();
                j += 1;
            }
        }
        return res;
    }
};