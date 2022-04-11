class Solution {
public:
    int integerReplacement(int n) {
        queue<pair<long, int>> q;
        q.push({n, 0});
        while(q.front().first != 1) {
            pair<long, int> p = q.front();
            q.pop();
            if(p.first & 1) {
                q.push({p.first + 1, p.second + 1});
                q.push({p.first - 1, p.second + 1});
            } else {
                q.push({p.first>>1, p.second + 1});
            }
        }
        return q.front().second;
    }
};