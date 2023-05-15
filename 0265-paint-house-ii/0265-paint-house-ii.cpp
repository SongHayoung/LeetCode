class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int colors = costs[0].size();
        vector<int> h(colors,0);
        for(auto& cost : costs) {
            priority_queue<pair<int,int>> pq;
            
            for(int i = 0; i < colors; i++) {
                pq.push({h[i], i});
                if(pq.size() > 2) pq.pop();
            }
            
            auto ma = pq.top(); pq.pop();
            auto mi = pq.top(); pq.pop();
            
            for(int i = 0; i < colors; i++) {
                h[i] = cost[i] + (i == mi.second ? ma.first : mi.first);
            }
        }
        return *min_element(begin(h), end(h));
    }
};