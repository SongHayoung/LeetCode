class Solution {
public:
    int minChanges(int n, int k) {
        int res = 0;
        while(n or k) {
            bool a = n & 1, b = k & 1;
            n /= 2, k /= 2;
            if(a == b) continue;
            if(b == 1) return -1;
            res++;
        }
        return res;
    }
};