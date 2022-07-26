class Solution {
public:
    bool isTransformable(string s, string t) {
        queue<int> q[10];
        int n = s.length();
        for(int i = 0; i < n; i++) {
            q[s[i]-'0'].push(i);
        }
        for(int i = 0; i < n; i++) {
            int idx = t[i] - '0';
            if(q[idx].empty()) return false;
            for(int i = 0; i < idx; i++) {
                if(q[i].empty()) continue;
                if(q[i].front() < q[idx].front()) return false;
            }
            q[idx].pop();
        }
        return true;
    }
};