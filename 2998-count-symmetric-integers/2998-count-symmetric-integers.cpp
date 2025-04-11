class Solution {
    bool ok(string s) {
        if(s.length() % 2) return false;
        int l = 0, r = s.length() - 1;
        int lsum = 0, rsum = 0;
        while(l < r) {
            lsum += s[l] - '0';
            rsum += s[r] - '0';
            l += 1, r -= 1;
        }
        return lsum == rsum;
    }
public:
    int countSymmetricIntegers(int low, int high) {
        int res = 0;
        for(int i = low; i <= high; i++) {
            string s = to_string(i);
            if(ok(s)) res += 1;
        }
        return res;
    }
};

