class Solution {
    long long parseDigit(string& s, int& p) {
        long long res = 0;
        while(p < s.length() and isdigit(s[p])) res = res * 10 + s[p++] - '0';
        return res;
    }
    map<string, function<long long(long long, long long)>> ops;
    long long helper(string& s, int& p) {
        if(s[p] == '-') return -parseDigit(s,++p);
        if(isdigit(s[p])) return parseDigit(s,p);
        auto op = ops[{s[p],s[p+1],s[p+2]}];
        p += 4;
        long long a = helper(s,p);
        p += 1;
        long long b = helper(s,p);
        p += 1;
        return op(a,b);
    }
public:
    long long evaluateExpression(string expression) {
        int p = 0;
        ops["add"] = [](long long a, long long b) -> long long {
            return a + b;
        };
        ops["sub"] = [](long long a, long long b) -> long long {
            return a - b;
        };
        ops["mul"] = [](long long a, long long b) -> long long {
            return a * b;
        };
        ops["div"] = [](long long a, long long b) -> long long {
            return a / b;
        };
        return helper(expression,p);
    }
};