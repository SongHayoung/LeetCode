class Solution {
    vector<string> res;
    unordered_map<char, char> strobogrammatic {
        {'0','0'},{'1','1'},{'6','9'},{'8','8'},{'9','6'}
    };
    string makeString(string& ans, string additional) {
        string res = ans + additional;
        for(int i = ans.length() - 1; i >= 0; i--) {
            res += strobogrammatic[ans[i]];
        }
        return res;
    }
    void backTracking(string& ans, int n) {
        if(ans.length() == (n/2)) {
            if(n&1) {
                res.push_back(makeString(ans,"0"));
                res.push_back(makeString(ans,"1"));
                res.push_back(makeString(ans,"8"));
            } else {
                res.push_back(makeString(ans,""));
            }
            return;
        }
        for(auto [key, _]: strobogrammatic) {
            if(ans.length() == 0 and key == '0') continue;
            ans += key;
            backTracking(ans, n);
            ans.pop_back();
        }
        return;
    }
public:
    vector<string> findStrobogrammatic(int n) {
        string tmp = "";
        backTracking(tmp, n);
        return res;
    }
};