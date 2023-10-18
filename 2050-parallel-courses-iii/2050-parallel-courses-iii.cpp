class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> req(time.begin(), time.end());
        vector<unordered_set<int>> topology(n);
        vector<int> rel(n);
        for(auto& vec: relations) {
            int from = vec[0] - 1, to = vec[1] - 1;
            topology[from].insert(to);
            rel[to]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(!rel[i]) {
                q.push(i);
            }
        }
        
        while(!q.empty()) {
            auto course = q.front(); q.pop();
            for(auto& nxt : topology[course]) {
                if(--rel[nxt] == 0) {
                    q.push(nxt);
                }
                req[nxt] = max(req[nxt], req[course] + time[nxt]);
            }
        }
        
        return *max_element(req.begin(), req.end());
    }
};