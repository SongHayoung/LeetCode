class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string> b(begin(bannedWords), end(bannedWords));
        int cnt = 0;
        for(auto& m : message) {
            if(b.count(m)) {
                if(++cnt >= 2) break;
            }
        }
        return cnt >= 2;
    }
};
