class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(!amount)
            return 0;
        queue<pair<long, int>> q;
        bool v[10001] = {false, };
        v[0] = true;
        q.push({0, 0});

        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            for(auto coin : coins) {
                if(p.first + coin <= amount && !v[p.first + coin]) {
                    v[p.first + coin] = true;
                    q.push({p.first + coin, p.second + 1});
                    if(p.first + coin == amount)
                        return p.second + 1;
                }
            }
        }
        return -1;
    }
};
