class Solution {
    vector<int> g;
    int getDistance(vector<int>& p1, vector<int>& p2) {
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }
    int find(int n) {
        return g[n] == n ? n : g[n] = find(g[n]);
    }
    void uni(int a, int b) {
        int pa = find(a), pb = find(b);
        g[pa] = g[pb] = min(pa,pb);
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int cost = 0, n = points.size();
        priority_queue<array<int,3>,vector<array<int,3>>, greater<array<int,3>>> pq;
        g = vector<int>(n);
        
        for(int i = 0; i < points.size(); i++) {
            g[i] = i;
            for(int j = i + 1; j < points.size(); j++) {
                pq.push({getDistance(points[i], points[j]), i, j});
            }
        }
        
        while(!pq.empty()) {
            auto [c, f, t] = pq.top(); pq.pop();
            if(find(f) == find(t)) continue;
            cost += c;
            uni(f,t);
        }
        return cost;
    }
};