class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> sell;
        priority_queue<pair<int,int>> buy;
        for(auto& o : orders) {
            int p = o[0], a = o[1], t = o[2];
            if(t == 0) {
                while(!sell.empty() and sell.top().first <= p and a) {
                    auto [sp, sa] = sell.top(); sell.pop();
                    auto b = min(a, sa);
                    a -= b;
                    sa -= b;
                    if(sa) sell.push({sp, sa});
                }
                if(a) buy.push({p,a});
            } else if(t == 1) {
                while(!buy.empty() and buy.top().first >= p and a) {
                    auto [bp, ba] = buy.top(); buy.pop();
                    auto b = min(a, ba);
                    a -= b;
                    ba -= b;
                    if(ba) buy.push({bp, ba});
                }
                if(a) sell.push({p,a});
            }
        }
        long res = 0, mod = 1e9 + 7;
        while(!buy.empty()) {
            auto [_, a] = buy.top(); buy.pop(); 
            res = (res + a) % mod;
        }
        while(!sell.empty()) {
            auto [_, a] = sell.top(); sell.pop();
            res = (res + a) % mod;
        }
        return res;
    }
};