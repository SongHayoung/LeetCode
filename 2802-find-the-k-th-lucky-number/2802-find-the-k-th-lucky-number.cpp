class Solution {
public:
    string kthLuckyNumber(int k) {
        string res = "";
        long long pre = 0, now = 2;
        while(pre < k) {
            res.push_back(' ');
            pre += now;
            now *= 2;
        }
        now /= 2;
        k -= (pre - now);
        now /= 2;
        for(int i = 0; i < res.size(); i++) {
            if(k > now) {
                res[i] = '7';
                k -= now;
            } else res[i] = '4';
            now /= 2;
        }
        return res;
    }
};