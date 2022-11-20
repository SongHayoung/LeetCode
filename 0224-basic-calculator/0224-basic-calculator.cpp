class Solution {
    int parse(string& s, int& i) {
        int res = 0;
        while(i < s.length() and isdigit(s[i])) {
            res = res * 10 + (s[i++] & 0b1111);
        }
        return res;
    }
    int solution(string& s, int& i) {
        int res = 0, sign = 1;
        while(i < s.length() and s[i] != ')') {
            if(s[i] == ' ') i++;
            else if(s[i] == '(') res += solution(s,++i) * sign;
            else if(s[i] == '-') {
                sign = -1; i++;
            } else if(s[i] == '+') {
                sign = 1; i++;
            } else {
                res += parse(s,i) * sign;
            }
        }
        i++;
        return res;
    }
public:
    int calculate(string s) {
        int i = 0;
        return solution(s,i);
    }
};