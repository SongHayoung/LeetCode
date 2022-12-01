class Solution {
public:
    bool halvesAreAlike(string s) {
        int cnt = 0;
        unordered_set<char> v{'a','e','i','o','u','A','E','I','O','U'};
        for(int i = 0; i < s.length(); i++) {
            if(!v.count(s[i])) continue;
            if(i < s.length() / 2) cnt += 1;
            else cnt -= 1;
        }
        return cnt == 0;
    }
};