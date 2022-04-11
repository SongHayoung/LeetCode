class Solution {
public:
    int minOperations(string s) {
        bool type1 = false, type2 = true;
        int diff1 = 0, diff2 = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '0') {
                if(type1)
                    diff1++;
                if(type2)
                    diff2++;
            } else {
                if(!type1)
                    diff1++;
                if(!type2)
                    diff2++;
            }
            type1 ^= true;
            type2 ^= true;
        }
        return min(diff1, diff2);
    }
};
