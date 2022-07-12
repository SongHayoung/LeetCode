class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        if(a > b) return numMovesStones(b,a,c);
        if(a > c) return numMovesStones(c,b,a);
        if(b > c) return numMovesStones(a,c,b);
        int l = b - a - 1, r = c - b - 1;
        if(l == 1 or r == 1) return {1, l + r};
        return {(l ? 1 : 0) + (r ? 1 : 0), l + r};
    }
};