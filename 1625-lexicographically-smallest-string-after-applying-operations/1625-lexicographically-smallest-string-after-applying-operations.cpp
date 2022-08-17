class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> us;
        queue<string> q;
        string res = s;
        q.push(s);
        while(!q.empty()) {
            auto now = q.front(); q.pop();
            auto rotate = now.substr(now.length() - b) + now.substr(0,now.length() - b);
            if(!us.count(rotate)) {
                us.insert(rotate);
                q.push(rotate);
                res = min(res, rotate);
            }
            for(int i = 1; i < now.length(); i += 2) {
                now[i] = (now[i] - '0' + a) % 10 + '0';
            }
            if(!us.count(now)) {
                us.insert(now);
                q.push(now);
                res = min(res, now);
            }
        }
        return res;
    }
};