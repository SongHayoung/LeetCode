class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> res;
        for(int i = 0; i < s.size() - 1; i++) {
            if(s[i] == '+' and s[i+1] == '+') {
                string ss = s;
                ss[i] = ss[i+1] = '-';
                res.push_back(ss);
            }
        }
        return res;
    }
};