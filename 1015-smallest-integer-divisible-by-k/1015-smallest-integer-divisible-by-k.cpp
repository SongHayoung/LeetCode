class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(!(k & 1)) return -1;
        unordered_set<int> s;
        int res = 1, power = 1;
        while(true) {
            int remainder = power % k;
            if(!remainder) return res;
            if(!s.insert(remainder).second) return -1;
            power = remainder * 10 + 1;
            res++;
        }
        
        return -1;
    }
};