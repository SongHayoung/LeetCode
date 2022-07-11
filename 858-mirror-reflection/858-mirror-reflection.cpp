class Solution {
public:
    int mirrorReflection(int p, int q) {
        if(p == q) return 1;
        int r1 = 1, r2 = 2, r3 = 0;
        bool flip = true;
        int sum = q;
        while(sum != p) {
            sum += q;
            if(sum > p) {
                flip = !flip;
                sum -= p;
            }
            swap(r1,r2);
        }
        return flip ? r1 : r3;
    }
};