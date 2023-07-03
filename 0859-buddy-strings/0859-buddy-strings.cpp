class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.length() != goal.length()) return false;
        vector<int> bad;
        unordered_set<char> us;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] != goal[i]) {
                bad.push_back(i);
                if(bad.size() > 2) return false;
            } else us.insert(s[i]);
        }
        if(bad.size() == 0) return us.size() != s.length();
        if(bad.size() != 2) return false;
        swap(s[bad[0]], s[bad[1]]);
        return s == goal;
    }
};