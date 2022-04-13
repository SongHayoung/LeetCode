class Solution {
    int parseNum(string& s, int &i) {
        int res = 0;
        while(i < s.length() and isdigit(s[i])) {
            res = res * 10 + (s[i++] & 0b1111);
        }
        return res;
    }
    int parseExpr(string& s, int& i) {
        char op = '+';
        vector<int> nums;
        while(i < s.length() and op != ')') {
            int n = s[i] == '(' ? parseExpr(s,++i) : parseNum(s,i);
            switch(op) {
                case '+': nums.push_back(n); break;
                case '-': nums.push_back(-n); break;
                case '*': nums.back()*=n; break;
                case '/': nums.back()/=n; break;
            }
            op = s[i++];
        }
        int res = 0;
        for(auto& n : nums) res += n;
        return res;
    }
public:
    int calculate(string s) {
        int i = 0;
        return parseExpr(s,i);
    }
};