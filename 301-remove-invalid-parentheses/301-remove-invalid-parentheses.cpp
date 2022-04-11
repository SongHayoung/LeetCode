class Solution {
    bool verify(string& str) {
        int counter = 0;
        for(auto ch : str) {
            if(ch == '(') counter++;
            else if(ch == ')') counter--;
            if(counter < 0) return false;
        }
        return counter == 0;
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        int len = s.length(), st = 0;
        vector<string> res;
        unordered_set<string> vis;
        queue<pair<string,int>> q;
        while(st < len and s[st] == ')') st++;
        q.push({"",st});
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto [str, index] = q.front(); q.pop();
                if(index == len) {
                    if(verify(str)) {
                        if(res.empty() or res.back().length() == str.length()) {
                            res.push_back(str);
                        } else if(!res.empty() and res.back().length() < str.length()) {
                            res.clear();
                            res.push_back(str);
                        }
                    }
                } else {
                    if((s[index] == ')' or s[index] == '(') and vis.insert(str).second) {
                        q.push({str, index + 1});
                    }
                    if(vis.insert(str + s[index]).second) {
                        q.push({str + s[index], index + 1});
                    }
                }
            }
            vis.clear();
        }
        return res;
    }
};