class Solution {
public:
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        priority_queue<pair<int, int>> left, right;
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pick, put;
        int res = 0, free = 0;
        for(int i = 0; i < k; i++) left.push({time[i][0] + time[i][2], i});
        while (n or put.size() or right.size()) {
            if (right.empty() and (put.empty() or put.top().first > free) and (!n or left.empty() and (pick.empty() or pick.top().first > free))) {
                int now = INT_MAX;
                if (n and pick.size()) now = min(now, pick.top().first);
                if (put.size()) now = min(now, put.top().first);
                free = now;
            }
            while (pick.size() and pick.top().first <= free) {
                auto [_, i] = pick.top(); pick.pop();
                left.push({time[i][0]+time[i][2], i});
            }
            while (put.size() && put.top().first <= free) {
                auto [_, i] = put.top(); put.pop();
                right.push({time[i][0] + time[i][2], i});
            }
            if (right.size()) {
                auto [_, i] = right.top(); right.pop();
                free += time[i][2];
                if (n) pick.push({free + time[i][3], i});
                else res = max(res, free);
            } else {
                auto [_, i] = left.top(); left.pop();
                free += time[i][0];
                put.push({free + time[i][1], i});
                --n;
            }
        }
        return res;
    }
};