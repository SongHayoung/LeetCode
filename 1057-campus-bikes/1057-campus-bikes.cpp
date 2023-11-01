class Solution {
    int getDistance(vector<int>& v1, vector<int>& v2) {
        return abs(v1[0] - v2[0]) + abs(v1[1] - v2[1]);
    }
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int n = workers.size(), m = bikes.size();
        vector<int> res(n, -1);
        priority_queue<array<int,3>, vector<array<int,3>>, greater<array<int,3>>> pq;
        unordered_set<int> taken;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                pq.push({getDistance(workers[i],bikes[j]), i, j});
            }
        }
        while(taken.size() < n) {
            auto [_, worker, bike] = pq.top(); pq.pop();
            if(taken.count(bike)) continue;
            if(res[worker] != -1) continue;
            res[worker] = bike;
            taken.insert(bike);
        }
        return res;
    }
};