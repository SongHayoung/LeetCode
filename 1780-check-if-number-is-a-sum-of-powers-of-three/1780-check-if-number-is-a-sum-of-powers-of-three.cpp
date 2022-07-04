class Solution {
public:
    bool checkPowersOfThree(int n) {
        int lg3 = log(n) / log(3);
        while(n) {
            int p = pow(3,lg3);
            if(n >= p) {
                n -= p;
                if(n >= p) return false;
            }
            lg3--;
        }
        return true;
    }
};