class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int use = 0, res = 0;
        while(mainTank) {
            mainTank -= 1;
            use += 1;
            if(use % 5 == 0) {
                if(additionalTank) mainTank += 1, additionalTank -= 1;
            }
            res += 10;
        }
        return res;
    }
};