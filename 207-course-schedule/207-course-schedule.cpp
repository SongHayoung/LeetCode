class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vs(numCourses, 0);
        vector<list<int>> vl(numCourses, list<int>());
        queue<int> q;
        int cnt = 0;
        for(auto& p : prerequisites) {
            vs[p.front()]++;
            vl[p.back()].push_back(p.front());
        }
        for(int i = 0 ; i < numCourses; i++) {
            if(!vs[i])
                q.push(i), cnt++;
        }
        while(q.size()) {
            int c = q.front();
            q.pop();
            for(auto req : vl[c]) {
                if(!--vs[req])
                    q.push(req), cnt++;
            }
        }
        
        return cnt == numCourses;
    }
};