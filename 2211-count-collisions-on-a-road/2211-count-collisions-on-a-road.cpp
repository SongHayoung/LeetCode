class Solution {
public:
    int countCollisions(string directions) {
        int l = 0, r = 0, s = 0;
        int res = 0;
        for(auto ch : directions) {
            if(ch == 'L') {
                if(r) {
                    res += r + 1;
                    r = 0;
                    l = 0;
                    s = 1;
                } else if(s) {
                    res++;
                    r = 0; l = 0; s = 1;
                } else l++;
            } else if(ch == 'R') {
                l = 0; s = 0; r++;
            } else {
                if(r) {
                    res += r;
                }
                r = 0; l = 0; s = 1;
            }
        }
        return res;
    }
};