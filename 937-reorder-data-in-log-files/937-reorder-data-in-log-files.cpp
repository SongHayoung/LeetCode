class Solution {
    bool alldigit(string s) {
        int i = 0, n = s.length();
        while(i < n and s[i] != ' ') i++;
        i++;
        while(i < n) {
            if(s[i] != ' ' and !isdigit(s[i])) return false;
            i++;
        }
        return true;
    }
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> digits;
        vector<pair<string, string>> letters;
        for(auto& log : logs) {
            if(alldigit(log)) digits.push_back(log);
            else {
                auto div = log.find(' ');
                letters.push_back({log.substr(0,div), log.substr(div)});
            }
        }
        sort(begin(letters), end(letters), [](auto a, auto b) {
           if(a.second == b.second) return a.first < b.first;
            return a.second < b.second;
        });
        vector<string> res;
        for(auto& [id, v] : letters) res.push_back(id + v);
        for(auto& d : digits) res.push_back(d);
        return res;
    }
};