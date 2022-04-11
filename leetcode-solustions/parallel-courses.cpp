class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<list<int>> course(n + 1, list<int>());
        vector<set<int>> require(n + 1, set<int>());
        unordered_set<int> need;
        queue<int> q;
        int semester = 0;
        for(auto relation : relations) {
            course[relation[0]].push_back(relation[1]);
            require[relation[1]].insert(relation[0]);
        }
        
        for(int i = 1; i <= n; i++) {
            need.insert(i);
            if(require[i].empty()) {
                q.push(i);
            }
        }
        
        while (!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                int study = q.front();
                q.pop();
                need.erase(study);
                for(auto next : course[study]) {
                    require[next].erase(study);
                }
            }
            
            for(auto haveTo : need) {
                if(require[haveTo].empty()) {
                    q.push(haveTo);
                }
            }
            semester++;
        }

        return need.empty() ? semester : -1;
    }
};
