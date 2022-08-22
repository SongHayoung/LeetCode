class Solution {
public:
    int maxDiff(int num) {
        int ma = num, mi = num;
        queue<string> q;
        unordered_set<string> vis;
        q.push(to_string(num));
        vis.insert(to_string(num));
        for(int i = 0; i < 1; i++) {
            int sz = q.size();
            while(sz--) {
                auto u = q.front(); q.pop();
                for(char f = '0'; f <= '9'; f++) {
                    for(char t = '0'; t <= '9'; t++) {
                        if(u[0] == f and t == '0') continue;
                        if(f == t) continue;
                        string now = u;
                        for(int i = 0; i < now.length(); i++) {
                            if(now[i] == f) now[i] = t;
                        }
                        if(vis.count(now)) continue;
                        vis.insert(now);
                        q.push(now);
                        ma = max(ma, stoi(now));
                        mi = min(mi, stoi(now));
                    }
                }
            }
        }
        
        return ma - mi;
    }
};