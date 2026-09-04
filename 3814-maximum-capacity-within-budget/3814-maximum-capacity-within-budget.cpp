class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
--budget;
        deque<pair<int,int>> dq;
        vector<pair<int,int>> S;
        for(int i = 0; i < costs.size(); i++) S.push_back({costs[i], capacity[i]});
        sort(begin(S), end(S));
        int res = 0;
        while(S.size()) {
            auto [c,cap] = S.back(); S.pop_back();
            if(c > budget) continue;
            if(dq.size() and dq[0].first + c <= budget) {
                auto it = prev(lower_bound(begin(dq), end(dq), pair<int,int>{budget - c + 1, -1}));
                res = max(res, cap + it->second);
            } else res = max(res, cap);
            while(dq.size() and dq[0].second <= cap) dq.pop_front();
            dq.push_front({c,cap});
        }
        return res;
    }
};
