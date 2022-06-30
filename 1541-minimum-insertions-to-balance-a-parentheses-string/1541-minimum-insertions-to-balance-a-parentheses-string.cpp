class Solution {
public:
    int minInsertions(string s) {
        int po = 0, o = 0, c = 0, n = s.length(), i = 0;
        while(i < n) {
            if(s[i] == '(') po++;
            else {
                if(i + 1 < n and s[i + 1] == ')') {
                    if(po) {
                        po--;
                    } else o++;
                    i += 1;
                } else {
                    if(po) {
                        po--;
                        c++;
                    } else {
                        c++,o++;
                    }
                }
            }
            i++;
        }
        
        
        return po * 2 + o + c;
    }
};