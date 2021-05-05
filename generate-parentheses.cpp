class Solution {
    bool valid(string& s) {
        int st = 0;
        for(auto& c: s) {
            switch (c) {
                case '(' : st++; break;
                case ')' : st--; break;
            }
            if(st < 0) return false;
        }
        return st == 0;
    }
public:
    vector<string> generateParenthesis(int n) {
        stringstream ss;
        for(int i = 0; i < n; i++) ss << '(';
        for(int i = 0; i < n; i++) ss << ')';
        string s = ss.str();
        vector<string> res;
        do if(valid(s)){
            res.push_back(s);
        } while(next_permutation(begin(s), end(s)));
        return res;
    }
};
