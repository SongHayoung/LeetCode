class Solution {
public:
    int openLock(vector<string>& d, string target) {
        unordered_set<string> v(d.begin(), d.end());
        if(v.count("0000")) return -1;
        if(target == "0000") return 0;
        queue<string> q;
        q.push("0000");
        v.insert("0000");
        int res = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto s = q.front(); q.pop();
                for(int i = 0; i < 4; i++) {
                    char nxt = s[i] == '9' ? '0' : s[i] + 1;
                    char prv = s[i] == '0' ? '9' : s[i] - 1;
                    string tmp = s; tmp[i] = nxt;
                    if(!v.count(tmp)) {
                        if(tmp == target) return res + 1;
                        q.push(tmp);
                        v.insert(tmp);
                    }

                    tmp = s; tmp[i] = prv;
                    if(!v.count(tmp)) {
                        if(tmp == target) return res + 1;
                        q.push(tmp);
                        v.insert(tmp);
                    }
                }
            }
            res++;
        }
        return -1;
    }
};