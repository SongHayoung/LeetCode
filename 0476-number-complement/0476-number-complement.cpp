class Solution {
public:
    int findComplement(int num) {
        long long res = 0, po = 1;
        while(num) {
            if(num % 2 == 0) res += po;
            num /= 2;
            po *= 2;
        }
        return res;
    }
};