class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<set<int>> st(2);
        for(int i = 0; i < students.size(); i++) {
            st[students[i]].insert(i);
        }
        int lst = -1;
        for(auto& s : sandwiches) {
            if(st[s].size() == 0) break;
            auto it = st[s].lower_bound(lst);
            if(it == end(st[s])) it = begin(st[s]);
            lst = *it;
            st[s].erase(it);
        }
        return st[0].size() + st[1].size();
    }
};