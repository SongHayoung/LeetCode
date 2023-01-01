class Solution {
    unordered_map<char, string> mp;
    unordered_map<string, char> rmp;
    string parse(string& s, int& i) {
        string res = "";
        while(i < s.length() and s[i] != ' ') {
            res += s[i++];
        }
        i++;
        return res;
    }
public:
    bool wordPattern(string pattern, string s) {
        int i = 0;
        for(auto& p : pattern) {
            if(i >= s.length())
                return false;
            string match = parse(s,i);
            if(mp.count(p) and mp[p] != match)
                return false;
            if(rmp.count(match) and rmp[match] != p)
                return false;
            rmp[match] = p;
            mp[p] = match;
        }
        return i >= s.length();
    }
};