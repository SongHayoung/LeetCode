class Solution {
public:
    string kthLuckyNumber(int k) {
        k -= 1;
        int n = 1, po = 2, x = 0;
        while(x + po <= k) {
            x += po;
            n += 1;
            po *= 2;
        }
        k -= x;
        string res(n,'4');
        for(int i = n - 1, j = 0; i >= 0; i--,j++) {
            if((k >> j) & 1) res[i] = '7';
        }
        return res;
    }
};