class Solution {
    int helper(int a, int b, int c) {
        int res = 0;
        while(a >= c) {
            a -= c;
            res++;
            c++;
            swap(a,b);
        }
        return res;
    }
public:
    int maxHeightOfTriangle(int red, int blue) {
        return max(helper(red,blue,1), helper(blue,red,1));
    }
};