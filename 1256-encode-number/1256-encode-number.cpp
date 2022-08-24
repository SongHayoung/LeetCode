class Solution {
public:
    string encode(int num) {
        if(num == 0) return "";
        int now = 2;
        string res = "0";
        while(num > now) {
            num -= now;
            now *= 2;
            res.push_back('0');
        }
        num -= 1;
        int p = res.length() - 1;
        while(num) {
            if(num & 1) res[p] = '1';
            num /= 2;
            p--;
        }
        return res;
    }
};