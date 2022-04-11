class Solution {
public:
    int myAtoi(string s) {
        long answer = 0, len;
        bool flag = true;
        for(len = 0; len < s.length() && s[len] == ' '; len++){}

        if(s[len] == '-') {
            flag = false;
            len++;
        } else if(s[len] == '+')
            len++;
        else if('0' > s[len] || s[len] > '9')
            return 0;

        for(; len < s.length() && '0' <= s[len] && s[len] <= '9' && INT_MIN <= answer && answer <= INT_MAX; len++) {
            answer = flag ? (answer<<3) + (answer<<1) + (s[len] & 0b1111) : answer * 10 - (s[len] & 0b1111);
        }

        return answer < INT_MIN ? INT_MIN : answer > INT_MAX ? INT_MAX : answer;
    }
};