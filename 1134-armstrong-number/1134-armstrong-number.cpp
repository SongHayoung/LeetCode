class Solution {
public:
    bool isArmstrong(int n) {
        int len = to_string(n).length();
        int sum = 0, x = n;
        while(x) {
            sum += pow(x % 10, len);
            x /= 10;
        }
        return sum == n;
    }
};
