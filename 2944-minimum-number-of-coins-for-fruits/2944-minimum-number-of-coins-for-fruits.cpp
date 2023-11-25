class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> free;
        int now = 0, res = INT_MAX;
        for(int i = 0; i < prices.size(); i++) {
            while(free.size() and free.top().second < i) free.pop();
            int best = now;
            if(free.size()) best = min(best, free.top().first);
            int j = i + 2 + i;
            free.push({best + prices[i], j});
            now = best + prices[i];
            if(j >= prices.size()) res = min(res, best + prices[i]);
        }
        res = min(res, now);
        return res;
    }
};
