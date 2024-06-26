class Solution {
public:
    string betterCompression(string s) {
        map<char,long long> ord;
        for(int i = 0; i < s.length();) {
            char ch = s[i];
            i++;
            long long now = 0;
            while(i < s.length() and isdigit(s[i])) {
                now = now * 10 + s[i] - '0';
                i++;
            }
            if(now == 0) now = 1;
            ord[ch] += now;
        }
        string res = "";
        for(auto& [k,v] : ord) {
            res.push_back(k);
            res += to_string(v);
        }
        return res;
    }
};