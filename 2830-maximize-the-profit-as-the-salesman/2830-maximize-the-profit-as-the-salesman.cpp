class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        int res = 0, ma = 0;
        sort(begin(offers), end(offers));
        for(int i = 0; i < offers.size(); i++) {
            int l = offers[i][0], r = offers[i][1], c = offers[i][2];
            while(q.size() and q.top().first < l) {
                ma = max(ma, q.top().second);
                q.pop();
            }
            res = max(res, ma + c);
            q.push({r,ma + c});
        }
        while(q.size()) {
            res = max(res, q.top().second); q.pop();
        }
        return res;
    }
};
