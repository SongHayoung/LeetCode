class Solution {
public:
    int numberOfChild(int n, int k) {
        int res = 0, pos = 1;
        while(k) {
            if(0 <= res + pos and res + pos < n) {
                res += pos;
                k--;
            } else pos = -pos;
        }
        return res;
    }
};