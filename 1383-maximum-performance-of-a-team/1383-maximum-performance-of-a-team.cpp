class Solution {
public:
    int maxPerformance(int n, vector<int>& sp, vector<int>& ef, int k) {
        long long res = 0, sum = 0, mod = 1e9 + 7;
        vector<pair<int, int>> A;
        priority_queue<int> pq;
        for(int i = 0; i < n; i++)
            A.push_back({ef[i], sp[i]});
        sort(rbegin(A), rend(A));
        
        for(auto& [e, s] : A) {
            sum += s;
            pq.push(-s);
            if(pq.size() > k) {
                sum += pq.top(); pq.pop();
            }
            
            res = max(res, sum * e);
        }
        
        return res % mod;
    }
};