class Solution {
    int nextVal(string& s, int& pos) {
        int res = 0;
        ++pos;
        for(; pos < s.length(); pos++) {
            if(s[pos] == ' ') continue;
            switch (s[pos]) {
                case '+' :
                case '-' :
                case '*' :
                case '/' : --pos; return res;
                default: res = (res<<3) + (res<<1) + (s[pos]&0b1111);
            }
        }
        return res;
    }
public:
    int calculate(string s) {
        list<char> op;
        list<int> num;
        int val = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ' ') continue;
            switch (s[i]) {
                case '+' :
                case '-' : num.push_back(val); op.push_back(s[i]); val = 0; break;
                case '*' : 
                case '/' : val = s[i] == '*' ? val * nextVal(s, i) : val / nextVal(s, i); break;
                default : val = (val<<3) + (val<<1) + (s[i]&0b1111);
            }
        }
        num.push_back(val);
        while(op.size()) {
            int n1 = num.front(); num.pop_front();
            int n2 = num.front(); num.pop_front();
            int res = op.front() == '+' ? n1 + n2 : n1 - n2; op.pop_front();
            num.push_front(res);
        }

        return num.front();
    }
};
