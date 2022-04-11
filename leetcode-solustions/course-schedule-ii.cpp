class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        unordered_map<int, int> cnt;
        unordered_map<int, list<int>> course;
        int chk = 0;
        for(auto& p : prerequisites) {
            course[p.back()].push_back(p.front());
            cnt[p.front()]++;
        }
        for(int i = 0; i < numCourses; i++) {
            if(!cnt.count(i)) res.push_back(i);
        }
        while(!cnt.empty()) {
            int sz = res.size();
            if(sz == chk) return {};
            for(;chk < sz; chk++) {
                for(auto& c : course[res[chk]]) {
                    if(!--cnt[c]) {
                        res.push_back(c);
                        cnt.erase(c);
                    }
                }
            }
        }

        return res;
    }
};
