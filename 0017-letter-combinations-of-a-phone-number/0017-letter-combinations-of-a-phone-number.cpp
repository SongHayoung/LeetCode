class Solution {
    unordered_map<char, vector<char>> m {
            {'2', {'a','b','c'}},
            {'3', {'d','e','f'}},
            {'4', {'g','h','i'}},
            {'5', {'j','k','l'}},
            {'6', {'m','n','o'}},
            {'7', {'p','q','r','s'}},
            {'8', {'t','u','v'}},
            {'9', {'w','x','y','z'}}
    };
public:
    vector<string> letterCombinations(string digits) {
        if(!digits.length()) return{};
        vector<string> res{};
        dfs(res, digits, 0, "");
        return res;
    }
    
    void dfs(vector<string>& res, string& d, int i, string ss) {
        if(d.length() == i) {
            res.push_back(ss);
            return;
        }
        for(auto& ch : m[d[i]]) {
            ss.push_back(ch);
            dfs(res, d, i + 1, ss);
            ss.pop_back();
        }
    }
};