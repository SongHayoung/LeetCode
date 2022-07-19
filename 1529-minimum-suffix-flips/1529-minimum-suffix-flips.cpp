class Solution {
public:
    int minFlips(string target) {
        int now = 0, res = 0;
        for(auto& ch : target) {
            int v = ch & 0b1111;
            if(now == v) continue;
            res++;
            now = !now;
        }
        return res;
    }
};