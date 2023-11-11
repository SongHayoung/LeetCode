
class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        long long n = values.size(), m = values[0].size();
        long long res = 0, day = n * m;
        priority_queue<array<long long, 3>> q;
        for(int i = 0; i < n; i++) q.push({values[i][0],i,0});
        while(q.size()) {
            auto [val, y,x] = q.top(); q.pop();
            res += val * day;
            day -= 1;
            if(x + 1 < m) q.push({values[y][x+1],y,x+1});
        }
        return res;
    }
};

