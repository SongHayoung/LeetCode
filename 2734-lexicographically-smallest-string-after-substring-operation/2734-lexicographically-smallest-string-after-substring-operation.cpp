class Solution {
public:
    string smallestString(string s) {
        bool ok = false;
        for(int i = 0; i < s.length() and !ok; i++) {
            if(s[i] == 'a') continue;
            for(int j = i; j < s.length() and s[j] != 'a'; j++) {
                s[j] -= 1;
            }
            ok = true;
        }
        if(!ok) s.back() = 'z';
        return s;
    }
};
