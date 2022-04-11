class Solution {
public:
    int lastRemaining(int n) {
        int l = 1, r = n, jump = 1, toLeft = 1;
        while(l != r) {
            if(toLeft) {
                toLeft = 0;
                
                l = l + jump;
                jump<<=1;
                r = l + (r - l) / jump * jump;
            } else {
                toLeft = 1;
                
                r = r - jump;
                jump <<= 1;
                l = r - (r - l) / jump * jump;
            }
        }
        
        return l;
    }
};