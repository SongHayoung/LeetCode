class Solution {
public:
    string strWithout3a3b(int a, int b) {
        if(b == 0) return string(a,'a');
        if(a ==0) return string(b, 'b');
        string res(a + b, '#');
        int i = 0;
        while(a != b and a and b) {
            if(a > b) {
                res[i] = res[i + 1] = 'a';
                res[i + 2] = 'b';
                a -= 2;
                b -= 1;
            } else {
                res[i] = res[i + 1] = 'b';
                res[i + 2] = 'a';
                a -= 1;
                b -= 2;
            }
            i += 3;
        }
        
        while(a and b) {
            if(a and b) {
                res[i] = 'a';
                res[i+1] = 'b';
                i += 2;
                a -=1, b -= 1;
            } else if(a) {
                res[i] = 'a';
                a-=1;
                i += 1;
            } else {
                res[i] = 'b';
                b -= 1;
                i += 1;
            }
        }
        
        if(a == 2) res[i] = res[i + 1] = 'a';
        else if(a == 1) res[i] = 'a';
        else if(b == 2) res[i] = res[i + 1] = 'b';
        else if(b == 1) res[i] = 'b';
        
        return res;
    }
};