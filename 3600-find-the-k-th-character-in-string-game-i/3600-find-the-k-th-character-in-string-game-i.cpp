class Solution {
public:
    char kthCharacter(long long k) {
        string s = "a";
        int pos = 0;
        while(s.length() <= k) {
            string ss = s;
            for(auto& ch : ss) ch++;
            s = s + ss;
        }
        return s[k-1];
    }
};