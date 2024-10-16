class Solution {
public:
    string longestDiverseString(int a, int b, int c, char ca = 'a', char cb = 'b', char cc = 'c') {
        if(a < b)
            return longestDiverseString(b,a,c,cb,ca,cc);
        if(b < c)
            return longestDiverseString(a,c,b,ca,cc,cb);
        if(b == 0)
            return string(min(a,2),ca);
        
        int aa = min(a,2), bb = a - aa >= b ? 1 : 0;
        return string(aa,ca) + string(bb,cb) + longestDiverseString(a-aa,b-bb,c,ca,cb,cc);
    }
};