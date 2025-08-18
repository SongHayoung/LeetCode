class Solution {
    bool op(double a, double b, double c, double d) {
        if(op(a+b,c,d) || op(a-b,c,d) || op(a*b,c,d) || op(a/b,c,d)) return true;
        if(op(a,b+c,d) || op(a,b-c,d) || op(a,b*c,d) || op(a,b/c,d)) return true;
        if(op(a,b,c+d) || op(a,b,c-d) || op(a,b,c*d) || op(a,b,c/d)) return true;
        return false;
    }
    bool op(double a, double b, double c) {
        if(op(a+b,c) || op(a-b,c) || op(a*b,c) || b&&op(a/b,c)) return true;
        if(op(a,b+c) || op(a,b-c) || op(a,b*c) || c&&op(a,b/c)) return true;
        return false;
    }
    bool op(double a, double b) {
        return judge(a + b) || judge(a - b) || judge(a * b) || b&&judge(a / b);
    }
    bool judge(double a) {
        return abs(a - 24.0) < 0.1;
    }
public:
    bool judgePoint24(vector<int>& c) {
        sort(c.begin(), c.end());
        do {
            if(op(c[0],c[1],c[2],c[3])) return true;
        }while(next_permutation(begin(c), end(c)));

        return false;
    }
};