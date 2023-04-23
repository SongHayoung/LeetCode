class Solution {
public:
    int addMinimum(string word) {
        int res = 0, p = 0;
        string abc = "abc";
        for(auto w : word) {
            while(abc[p] != w) {
                res += 1;
                p = (p + 1) % 3;
            }
            p = (p + 1) % 3;
        }
        while(p != 0) {
            res += 1;
            p = (p + 1) % 3;
        }
        return res;
    }
};