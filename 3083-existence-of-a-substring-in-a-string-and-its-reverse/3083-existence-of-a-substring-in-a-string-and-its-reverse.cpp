class Solution {
public:
    bool isSubstringPresent(string s) {
        unordered_set<string> us;
        for(int i = 0; i < s.length() - 1; i++) {
            string now = "";
            now.push_back(s[i]);
            now.push_back(s[i+1]);
            us.insert(now);
        }
        reverse(begin(s), end(s));
        for(int i = 0; i < s.length() - 1; i++) {
            string now = "";
            now.push_back(s[i]);
            now.push_back(s[i+1]);
            if(us.count(now)) return true;
        }
        return false;
    }
};


