class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        unordered_map<int, vector<int>> m;
        vector<pair<int, int>> v(n + 1, {0, 0});
        queue<pair<int, int>> q;
        for(auto& e : edges) {
            m[e[0]].push_back(e[1]);
            m[e[1]].push_back(e[0]);
        }

        q.push({1,0});
        v[1] = {1, 0}; // node 1 visited once, at time 0
        while(true) {
            auto [node, arrive] = q.front();
            q.pop();
            bool needWait = (arrive / change) & 1; // arrive / change is odd means we have to wait
            int waitTime = needWait ? ((arrive / change) + 1) * change - arrive : 0;
            int nextTime = arrive + waitTime + time;
            for(auto& nxt : m[node]) {
                if(v[nxt].first < 2 and v[nxt].second != nextTime) { //check how many next node visited most 2 time, more is not necessary
                    q.push({nxt, arrive + waitTime + time});
                    v[nxt].first += 1;
                    v[nxt].second = nextTime;
                    if(nxt == n and v[nxt].first == 2) {
                        return nextTime;
                    }
                }
            }
        }

        return -1;
    }
};