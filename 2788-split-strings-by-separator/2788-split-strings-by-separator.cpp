
class Solution {
    vector<string> parse(string& s, char ch) {
        vector<string> res;
        string now = "";
        for(auto c : s) {
            if(c == ch) {
                if(now.length()) res.push_back(now);
                now = "";
            } else now.push_back(c);
        }
        if(now.length()) res.push_back(now);
        return res;
    }
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> res;
        for(auto w : words) {
            auto now = parse(w,separator);
            for(auto n : now) res.push_back(n);
        }
        return res;
    }
};