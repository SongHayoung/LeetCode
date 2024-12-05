class Solution {
public:
    bool canChange(string start, string target) {
        if(start.size() != target.size()) return false;
        vector<int> a,b;
        for(int i = 0; i < start.size(); i++) {
            if(start[i] != '_') a.push_back(i);
            if(target[i] != '_') b.push_back(i);
        }
        if(a.size() != b.size()) return false;
        for(int i = 0; i < a.size(); i++) {
            if(start[a[i]] != target[b[i]]) return false;
            if(start[a[i]] == 'L' and a[i] < b[i]) return false;
            if(start[a[i]] == 'R' and a[i] > b[i]) return false;
        }
        return true;
    }
};