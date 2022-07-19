class Solution {
public:
    int maximumScore(int a, int b, int c) {
        if(!b and !c) return 0;
        if(a < b) return maximumScore(b,a,c);
        if(a < c) return maximumScore(c,b,a);
        if(b < c) return maximumScore(a,c,b);
        return 1 + maximumScore(a-1,b-1,c);
    }
};