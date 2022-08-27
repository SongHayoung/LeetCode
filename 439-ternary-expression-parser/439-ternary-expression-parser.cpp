class Solution {
    int find(string s) {
        for(int i = 2, now = 1; i < s.length(); i++) {
            if(s[i] == '?') now++;
            else if(s[i] == ':') now--;
            if(now == 0) return i;
        }
        return -1;
    }
public:
    string parseTernary(string expression) {
        if(expression.find('?') == string::npos) return expression;
        int cut = find(expression);
        if(expression[0] == 'T') return parseTernary(expression.substr(2,cut - 2));
        return parseTernary(expression.substr(cut+1));
    }
};