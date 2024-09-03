class Solution {
public:
    int getLucky(string s, int k) {
        k--;
        int res = 0;
        for(auto& ch : s) {
            int x = ch - 'a' + 1;
            while(x) {
                res += x % 10;
                x /= 10;
            }
        }
        while(k--) {
            int nres = 0;
            while(res) {
                nres += res % 10;
                res /= 10;
            }
            res = nres;
        }
        return res;
    }
};