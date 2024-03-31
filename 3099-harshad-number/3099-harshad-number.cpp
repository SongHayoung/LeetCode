class Solution {
    int helper(int x) {
        int res = 0;
        while(x) {
            res += x % 10;
            x /= 10;
        }
        return res;
    }
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sum = helper(x);
        if(x % sum == 0) return sum;
        return -1;
    }
};