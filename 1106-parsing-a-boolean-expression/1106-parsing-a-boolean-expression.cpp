class Solution {
    bool evalAnd(string& exp, int& p) {
        p += 2;
        auto res = true;
        res &= eval(exp, p);
        while(exp[p] != ')') {
            p++;
            res &= eval(exp, p);
        }
        p++;
        return res;
    }
    bool evalOr(string& exp, int& p) {
        p += 2;
        auto res = false;
        res |= eval(exp, p);
        while(exp[p] != ')') {
            p++;
            res |= eval(exp, p);
        }
        p++;
        return res;
    }
    bool evalNot(string& exp, int& p) {
        p += 2;
        auto res = eval(exp, p);
        p++;
        return !res;
    }
    bool eval(string& exp, int& p) {
        if(exp[p] == 't') {
            p++;
            return true;
        } else if(exp[p] == 'f') {
            p++;
            return false;
        } else if(exp[p] == '&') {
            return evalAnd(exp, p);
        } else if(exp[p] == '|') {
            return evalOr(exp, p);
        } else return evalNot(exp, p);
    }
public:
    bool parseBoolExpr(string expression) {
        int pos = 0;
        return eval(expression, pos);
    }
};