class Solution {
public:
    bool checkRecord(string s) {
        int A = 0, L = 0;
        for(int i = 0; i < s.length() and A < 2 and L < 3; i++) {
            if(s[i] == 'A') {
                L = 0;
                A++;
            } else if(s[i] == 'L') {
                L++;
            } else {
                L = 0;
            }
        }
        return A < 2 and L < 3;
    }
};