class Solution {
public:
    int distMoney(int money, int children) {
        if(money < children) return -1;
        money -= children;
        int res = 0;
        for(int i = 0; i < children; i++) {
            if(money - 7 >= 0) {
                money -= 7;
                res += 1;
            } else {
                if(money == 3) {
                    if(i + 1 == children) res -= 1;
                }
                money = 0;
            }
        }
        if(money) res -= 1;
        return max(0,res);
    }
};