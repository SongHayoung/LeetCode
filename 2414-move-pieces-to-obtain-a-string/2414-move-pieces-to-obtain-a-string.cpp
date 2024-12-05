class Solution {
public:
    bool canChange(string start, string target) {
        if(start.size() != target.size()) return false;
        deque<int> a,b;
        for(int i = 0; i < start.size(); i++) {
            if(start[i] != '_') a.push_back(i);
            if(target[i] != '_') b.push_back(i);
            if(a.size() and b.size()) {
                if(start[a[0]] != target[b[0]]) return false;
                if(start[a[0]] == 'L' and a[0] < b[0]) return false;
                if(start[a[0]] == 'R' and a[0] > b[0]) return false;
                a.pop_front(), b.pop_front();
            }
        }
        return a.size() == 0 and b.size() == 0;
    }
};