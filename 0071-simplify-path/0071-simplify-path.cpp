class Solution {
    string parse(string& s, int& p) {
        while(p < s.length() and s[p] == '/') p++;
        string res = "";
        while(p < s.length() and s[p] != '/') {
            res.push_back(s[p++]);
        }
        return res;
    }
public:
    string simplifyPath(string path) {
        vector<string> pwd;
        for(int i; i < path.size();) {
            string now = parse(path,i);
            if(now == "" or now == ".") continue;
            if(now == "..") {
                if(pwd.size()) pwd.pop_back();
            } else pwd.push_back(now);
        }
        string res = "";
        for(auto& p : pwd) res += "/" + p;
        if(res == "") res = "/";
        return res;
    }
};