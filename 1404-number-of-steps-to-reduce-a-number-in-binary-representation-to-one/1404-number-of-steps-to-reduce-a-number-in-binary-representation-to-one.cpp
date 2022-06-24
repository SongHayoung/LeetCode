class Solution {
public:
    int numSteps(string s) {
        int res = 0;
        while(s.length() > 1) {
            if(s.back() == '0') s.pop_back();
            else {
                int carry = 1, n = s.length();
                s.back() = '0';
                for(int i = n - 2; i >= 0 and carry; i--) {
                    if(s[i] == '1') s[i] = '0';
                    else {
                        s[i] = '1';
                        carry = 0;
                    }
                }
                if(carry) s = '1' + s;
            }
            res++;
        }
        return res;
    }
};