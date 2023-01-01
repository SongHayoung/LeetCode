class Solution {
public:
    bool confusingNumber(int n) {
        int N = n, rev = 0;
        unordered_set<int> bad{2,3,4,5,7};
        while(N) {
            int d = N % 10;
            N /= 10;
            if(bad.count(d)) return false;
            if(d == 6) d = 9;
            else if(d == 9) d = 6;
            rev = rev * 10 + d;
        }
        return n != rev;
    }
};