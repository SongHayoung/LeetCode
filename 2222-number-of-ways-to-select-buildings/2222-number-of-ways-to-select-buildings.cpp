class Solution {
public:
    // "010"
    // "101"
    long long numberOfWays(string s) {
        long long result = 0, n = s.length();
        long long one = 0, zero = 0;
        long long onezero = 0, zeroone = 0;
        
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '0') {
                result += zeroone; // 01 + '0'
                onezero += one; // 1 + '0'
                zero += 1; // '0'
            }
            if(s[i] == '1') {
                result += onezero;
                zeroone += zero;
                one += 1;
            }
        }
    
        
        return result;
    }
};