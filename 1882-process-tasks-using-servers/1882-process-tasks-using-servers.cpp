
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        vector<int> res(tasks.size());
        queue<int> q;
        map<int,set<int>> free;
        auto addServer = [&](int id) {
            free[servers[id]].insert(id);
        };
        auto deleteServer = [&]() {
            int id = *begin(begin(free)->second);
            begin(free)->second.erase(id);
            if(begin(free)->second.size() == 0) free.erase(begin(free));
            return id;
        };
        for(int i = 0; i < servers.size(); i++) addServer(i);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> use;
        for(int i = 0; i < tasks.size(); i++) {
            q.push(i);
            while(use.size() and use.top().first == i) {
                auto [_,id] = use.top(); use.pop();
                addServer(id);
            }
            while(q.size() and free.size()) {
                auto task = q.front(); q.pop();
                auto server = deleteServer();
                use.push({i + tasks[task], server});
                res[task] = server;
            }
        }
        while(q.size()) {
            int time = use.top().first;
            while(use.size() and use.top().first == time) {
                auto [_,id] = use.top(); use.pop();
                addServer(id);
            }
            while(q.size() and free.size()) {
                auto task = q.front(); q.pop();
                auto server = deleteServer();
                use.push({time + tasks[task], server});
                res[task] = server;
            }
        }
        return res;
    }
};