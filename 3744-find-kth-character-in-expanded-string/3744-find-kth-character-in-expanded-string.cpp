class Solution {
public:
    char kthCharacter(string s, long long k) {
        s.push_back(' ');
        string chk = "";
        k++;
        for(auto& ch : s) {
            if(ch == ' ') {
                long long len = chk.length();
                long long tlen = len * (len + 1) / 2;
                if(tlen < k) {
                    k -= tlen;
                    if(k == 1) return ' ';
                    k -= 1;
                } else {
                    long long now = 1;
                    for(auto& ch : chk) {
                        if(k <= now) return ch;
                        k -= now;
                        now++;
                    }
                }
                chk = "";
            } else chk.push_back(ch);
        }
        return '#';
    }
};