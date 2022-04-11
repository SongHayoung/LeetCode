class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> ch;
        unordered_set<char> taken;
        for(int i =0; i < s.length(); i++) {
            if(ch.count(s[i]) and ch[s[i]] != t[i]) return false;
            else if(!ch.count(s[i])) {
                if(taken.count(t[i])) return false;
                taken.insert(t[i]);
                ch[s[i]] = t[i];
            }
        }
        return true;
    }
};