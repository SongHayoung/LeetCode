class Solution {
    int bitOp(int a, int b) {
        int i = 0, res = 0;
        while(a != 0 or b != 0) {
            int bi = b & 1 ? !(a & 1) : (a & 1);
            res += bi * (1<<i);
            i++;
            a>>=1; b>>=1;
        }
        return res;
    }
public:
    int flipLights(int n, int presses) {
        int bits = (1<<min(n, 3)) - 1;
        int odd = bits & 5, even = bits & 6, over = bits, optional = 1;
        unordered_set<int> res;
        res.insert(bits);
        presses = min(presses, 3);
        while(presses--) {
            unordered_set<int> flip;
            for(auto& bi : res) {
                flip.insert(bitOp(bi,odd));
                flip.insert(bitOp(bi,even));
                flip.insert(bitOp(bi,over));
                if(n >= 3) flip.insert(bitOp(bi,optional));
            }

            swap(res, flip);
        }

        return res.size();
    }
};