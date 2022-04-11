class Solution {
    pair<int, int> normalize(string s) {
        int x = 0, v = 0;
        int d = 0;
        int sign = s[0] == '-' ? -1 : 1;
        for(int i = s[0] == '-' ? 1 : 0; i < s.length(); i++) {
            if(isdigit(s[i])) d = d*10 + (s[i]&0b1111);
            else if(s[i] == 'x') continue;
            else if(s[i] == '-') {
                bool isX = s[i-1] == 'x';
                if(isX) x += max(d, (i >= 2 and s[i-2] == '0') ? 0 : 1)*sign;
                else v += d * sign;
                sign = -1;
                d = 0;
            } else if(s[i] == '+') {
                bool isX = s[i-1] == 'x';
                if(isX) x += max(d, (i >= 2 and s[i-2] == '0') ? 0 : 1)*sign;
                else v += d * sign;
                sign = 1;
                d = 0;
            }
        }
        bool isX = s.back() == 'x';
        if(isX) x += max(d, (s.length() >= 2 and s[s.length() -2] == '0') ? 0 : 1)*sign;
        else v += d * sign;
        return {x,v};
    }
public:
    string solveEquation(string equation) {
        auto pos = equation.find('=');
        auto [lx, lv] = normalize(equation.substr(0,pos));
        auto [rx, rv] = normalize(equation.substr(pos+1));
        rv -= lv;
        lx -= rx;
        if(lx == 0 and rv == 0) return "Infinite solutions";
        if(lx == 0 and rv != 0) return "No solution";
        if(rv == 0) return "x=0";
        return "x=" + to_string(rv/lx);
    }
};