class Solution {
public:
    int jump(vector<int>& station) {
        deque<pair<int,int>> cost{{1,station[0]}};
        int n = station.size();
        if(cost[0].second >= n - 1) return n != 1;
        for(int i = 1; i < n; i++) {
            while(cost.size() and cost[0].second < i) cost.pop_front();
            if(cost.size() == 0) return -1;
            int until = i + station[i], weight = cost[0].first + 1;
            if(until >= n - 1) return weight;
            if(cost.back().second < until) cost.push_back({weight, until});
        }
        return 0;
    }
};