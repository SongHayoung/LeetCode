class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        do {
            slow = convert(slow);
            fast = convert(convert(fast));
        }while(slow != fast);
        return slow == 1;
    }
    int convert(int n) {
        int res = 0, tmp;
        while(n) {
            tmp = n % 10;
            res += tmp * tmp;
            n /= 10;
        }
        return res;
    }
};