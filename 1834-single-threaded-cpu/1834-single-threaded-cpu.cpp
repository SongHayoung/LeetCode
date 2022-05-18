class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<array<int,3>> task;
        for(int i = 0; i < tasks.size(); i++) {
            task.push_back({tasks[i][0], tasks[i][1], i});
        }
        sort(begin(task), end(task));
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int i = 0, time = task[0][0], n = task.size();
        vector<int> res;
        while(i < n) {
            while(i < n and task[i][0] <= time) {
                pq.push({task[i][1], task[i][2]});
                i++;
            }
            if(!pq.empty()) {
                auto [fin, idx] = pq.top(); pq.pop();
                res.push_back(idx);
                time += fin;
            } else time = task[i][0];
            
        }
        while(!pq.empty()) {
            auto [fin, idx] = pq.top(); pq.pop();
            res.push_back(idx);
            time = fin;
        }
        return res;
    }
};