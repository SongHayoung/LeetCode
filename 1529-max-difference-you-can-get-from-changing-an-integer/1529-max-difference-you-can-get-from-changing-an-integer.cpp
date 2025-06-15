class Solution {
public:
    int maxDiff(int num) {
        int ma = num, mi = num;
        string u = to_string(num);
        for(char f = '0'; f <= '9'; f++) {
            for(char t = '0'; t <= '9'; t++) {
                if(u[0] == f and t == '0') continue;
                if(f == t) continue;
                string now = u;
                for(int i = 0; i < now.length(); i++) {
                    if(now[i] == f) now[i] = t;
                }
                ma = max(ma, stoi(now));
                mi = min(mi, stoi(now));
            }
        }
        
        return ma - mi;
    }
};