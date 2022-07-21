class Solution {
    pair<int, int> parse(int& i, string& exp) {
        int a = 0, b = 0;
        bool neg = exp[i] == '-';
        if(!isdigit(exp[i])) i++;
        while(i < exp.length() and isdigit(exp[i])) {
            a = a * 10 + (exp[i++] & 0b1111);
        }
        i++;
        while(i < exp.length() and isdigit(exp[i])) {
            b = b * 10 + (exp[i++] & 0b1111);
        }
        return {neg ? -a : a , b};
    }
    string helper(string exp) {
        int a = 0, b = 1, i = 0;
        while(i < exp.length()) {
            auto [aa, bb] = parse(i, exp);
            
            int lcm = b / gcd(b,bb) * bb;
            
            a = lcm / b * a + lcm / bb * aa;
            
            b = lcm;
            
            int g = __gcd(a,b);
            a /= g;
            b /= g;
            if(b < 0) {
                b = -b;
                a = -a;
            }
        }
        if(a == 0) return "0";
        if(b == 1) return to_string(a);
        return to_string(a) + "/" + to_string(b);
    }
public:
    string fractionAddition(string expression) {
        string res = helper(expression);
        if(res == "0") return "0/1";
        if(res.find('/') == string::npos) return res + "/1";
        return res;
    }
};