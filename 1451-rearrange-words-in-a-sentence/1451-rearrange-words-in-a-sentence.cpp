class Solution {
public:
    string arrangeWords(string text) {
        text[0] = tolower(text[0]);
        text.push_back(' ');
        string now = "";
        map<int, vector<string>> mp;
        for(int i = 0; i < text.length(); i++) {
            if(text[i] == ' ') {
                mp[now.length()].push_back(now);
                now = "";
            } else now.push_back(text[i]);
        }
        string res = "";
        for(auto& [_, v] : mp) {
            for(auto& w : v) {
                res += w + " ";
            }
        }
        res.pop_back();
        res[0] = toupper(res[0]);
        return res;
    }
};