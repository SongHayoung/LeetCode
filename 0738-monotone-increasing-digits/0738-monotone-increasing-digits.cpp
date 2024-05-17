class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string res = "", s = to_string(n);
        res.push_back(s[0]);
        int x = s.length();
        for(int i = 1; i < x; i++) {
            if(s[i] >= res.back()) {
                res.push_back(s[i]);
            } else {
                char ch = res.back();
                while(res.size() and res.back() == ch) res.pop_back();
                res.push_back(ch);
                string cut = "1";
                while(res.size() < x) {
                    res.push_back('9');
                    cut.push_back('0');
                }
                return stoi(res) - stoi(cut);
            }
        }
        return stoi(res);
    }
};