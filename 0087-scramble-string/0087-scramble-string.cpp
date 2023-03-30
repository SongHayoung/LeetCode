class Solution {
    unordered_map<string, bool> v;
public:
    bool isScramble(string s1, string s2) {
        if(s1.length() == 1 || s1 == s2) return s1 == s2;
        string key = s1 + "#" + s2;
        if(v.count(key)) return v[key];
        
        v[key] = false;
        
        int chars[26]{0};
        
        for(auto& ch : s1) chars[ch-'a']++;
        for(auto& ch : s2) chars[ch-'a']--;
        for(auto& n : chars) if(n) return v[key];
        
        stringstream s1left, s2leftss;
        int len = s1.length();
        for(int i = 0; i < len - 1 and !v[key]; i++) {
            s1left<<s1[i];
            s2leftss<<s2[i];
            string s1right = s1.substr(i + 1);
            string s2left = s2.substr(0, len - i - 1);
            string s2right = s2.substr(len - i - 1);
            v[key] |= (isScramble(s1left.str(), s2right) and isScramble(s1right, s2left));
            s2right = s2.substr(i + 1);
            v[key] |= (isScramble(s1left.str(), s2leftss.str()) and isScramble(s1right, s2right));
        }
        return v[key];
    }
};