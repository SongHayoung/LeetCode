#define all(a) begin(a), end(a)
using namespace std;
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& f, vector<int>& pp) {
        vector<pair<int,int>> p;
        int n = f.size(), m = pp.size();
        for(int i = 0; i < m; i++) {
            p.push_back({pp[i], i});
        }
        sort(all(p));
        sort(all(f));
        vector<int> res(m);
        int i = 0, j = 0, sum = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        while(i < n and j < m) {
            int lo = f[i][0];
            while(!pq.empty() and pq.top() < lo) {
                while(j < m and p[j].first <= pq.top()) {
                    res[p[j++].second] = sum;
                }
                pq.pop();
                sum--;
            }
            while(j < m and p[j].first < lo) res[p[j++].second] = sum;

            while(i < n and f[i][0] == lo) {
                pq.push(f[i++][1]);
                sum++;
            }
        }
        while(!pq.empty() and j < m) {
            while(j < m and p[j].first <= pq.top()) {
                res[p[j++].second] = sum;
            }
            pq.pop();
            sum--;
        }
        return res;
    }
};