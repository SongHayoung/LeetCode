class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& arr, vector<int>& query) {
        int qsz = query.size(), asz = arr.size(), i = 0;
        vector<pair<int, int>> q(qsz);
        vector<int> res(qsz, -1);
        for(int i = 0; i < qsz; i++) q[i] = {query[i], i};
        sort(begin(arr), end(arr));
        sort(begin(q), end(q));
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        map<int, int> m;
        for(auto& p : q) {
            for(; i < asz && arr[i][0] <= p.first; i++) {
                pq.push({arr[i].back(), arr[i].back() - arr[i].front() + 1});
                m[arr[i].back() - arr[i].front() + 1]++;
            }
            while(!pq.empty() && pq.top().first < p.first) {
                if(m[pq.top().second] == 1) m.erase(pq.top().second);
                else --m[pq.top().second];
                pq.pop();
            }
            if(!m.empty()) res[p.second] = m.begin()->first;
        }

        return res;
    }
};
