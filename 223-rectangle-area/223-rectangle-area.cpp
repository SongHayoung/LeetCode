class Solution {
public:
    int computeArea(int a, int b, int c, int d, int e, int f, int g, int h) {
        int l = max(a,e), r = max(min(c,g),l);
        int B = max(b,f), t = max(min(d,h),B);
        return (c-a)*(d-b) - (r-l)*(t-B) + (g-e)*(h-f);
    }
};
