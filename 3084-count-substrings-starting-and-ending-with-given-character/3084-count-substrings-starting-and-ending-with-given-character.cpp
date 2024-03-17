class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long cnt = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == c) cnt++;
        }
        return cnt * (cnt + 1) / 2;
    }
};
