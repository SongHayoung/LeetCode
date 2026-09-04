
class Solution {
public:
    int minAllOneMultiple(int k) {
        unordered_set<int> seen;
        int rem = 1, res = 2, val = 10 % k;
        while(1) {
            rem = (rem + val) % k;
            if(rem == 0) return res;
            if(seen.count(rem)) return -1;
            seen.insert(rem);
            val = (val * 10) % k;
            res++;
        }
        return -1;
    }
};