class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        int res = 2;
        if(a == e and b == f) res = min(res, 0);
        if(c == e and d == f) res = min(res, 0);
        if(a == e or b == f) {
            if(a == e) {
                int mi = min(b,f), ma = max(b,f);
                if(a == c) {
                    if(mi <= d and d <= ma) res = min(res, 2);
                    else res = min(res, 1);
                }
                else res = min(res, 1);
            }
            if(b == f) {
                int mi = min(a,e), ma = max(a,e);
                if(d == b) {
                    if(mi <= c and c <= ma) res = min(res, 2);
                    else res = min(res, 1);
                }
                else res = min(res, 1);
            }
        }

        if(((e+f) & 1) == ((c + d) & 1)) {
            if((c-d) == (e-f)) {
                if((a-c) == (b-d)) {
                    int mi = min(c,e), ma = max(c,e);
                    if(mi <= a and a <= ma) res = min(res, 2);
                    else res = min(res, 1);
                }
                else res = min(res, 1);
            }
            if((c+d) == (e+f)) {
                if((a+b) == (c+d)) {
                    int mi = min(c,e), ma = max(c,e);
                    if(mi <= a and a <= ma) res = min(res, 2);
                    else res = min(res, 1);
                } else res = min(res, 1);
            }
        }
        return res;
    }
};
