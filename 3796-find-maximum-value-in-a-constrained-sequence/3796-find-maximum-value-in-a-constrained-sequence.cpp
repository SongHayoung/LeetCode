
class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
        vector<int> lim(n,INT_MAX);
        for(auto& r : restrictions) lim[r[0]] = min(lim[r[0]], r[1]);
        lim[0] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>> q;
        for(int i = 0; i < n; i++) q.push({lim[i], i});
        while(q.size()) {
            auto [val, idx] = q.top(); q.pop();
            if(lim[idx] != val) continue;
            if(idx) {
                int ma = lim[idx] + diff[idx-1];
                if(lim[idx-1] > ma) {
                    lim[idx-1] = ma;
                    q.push({lim[idx-1],idx-1});
                }
            }
            if(idx + 1 < n) {
                int ma = lim[idx] + diff[idx];
                if(lim[idx+1] > ma) {
                    lim[idx+1] = ma;
                    q.push({lim[idx+1],idx+1});
                }
            }
        }
        return *max_element(begin(lim), end(lim));
    }
};