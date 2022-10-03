class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int res(0), mx(0);
        for(int i = 1; i < s.length(); i++) {
            if(s[i] == s[i - 1]) {
                if(mx) res += min(mx, cost[i]);
                else res += min(cost[i - 1], cost[i]), mx = max(cost[i], cost[i - 1]);
                mx = max(cost[i], mx);
            } else mx = 0;
        }
        return res;
    }
};