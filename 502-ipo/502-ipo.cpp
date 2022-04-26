class Solution {
public:
    int findMaximizedCapital(int k, int res, vector<int>& p, vector<int>& c) {
        int n = p.size();
        priority_queue<int> pq;
        vector<pair<int,int>> v;
        for(int i = 0; i < n; i++) {
            v.push_back({c[i], p[i]});
        }
        int i = 0;
        sort(begin(v), end(v));
        while(k--) {
            while(i < n and v[i].first <= res) {
                pq.push(v[i++].second);
            }
            if(!pq.empty()) {
                res += pq.top(); pq.pop();
            }
        }
        
        return res;
    }
};