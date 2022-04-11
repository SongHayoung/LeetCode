class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> children;
        for(int i = 0; i < ppid.size(); i++) {
            children[ppid[i]].push_back(i);
        }
        vector<int> res{kill};
        queue<int> q;
        q.push(kill);
        while(!q.empty()) {
            auto parent = q.front(); q.pop();
            for(auto child : children[parent]) {
                res.push_back(pid[child]);
                q.push(pid[child]);
            }
        }
        return res;
    }
};