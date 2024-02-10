class Solution {
public:
    int countSegments(string s) {
        int res = 0;
        bool fl = 0;
        s.push_back(' ');
        for(auto& ch : s) {
            if(ch == ' ') {
                if(fl) res += 1;
                fl = 0;
            } else fl = 1;
        }
        return res;
    }
};