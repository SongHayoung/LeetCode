class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        stringstream ss;
        string key = "";
        unordered_map<string, string> m;
        bool flag = false;
        for(auto p : knowledge) {
            m[p[0]] = p[1];
        }
        for(int i = 0; i < s.length(); i++) {
            if(flag) {
                if(s[i] == ')') {
                    if(m.count(key)) {
                        ss << m[key];
                    } else {
                        ss << '?';
                    }
                    flag = false;
                    key = "";
                } else {
                    key += s[i];
                }
            } else {
                if(s[i] == '(') {
                    flag = true;
                } else {
                    ss << s[i];
                }
            }
        }
        return ss.str();
    }
};
