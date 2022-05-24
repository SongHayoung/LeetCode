class Solution {
public:
    bool isSelfCrossing(vector<int>& distance) {
        int b = 0, c = 0, d = 0, e = 0, f = 0;
        for(auto& a : distance) {
            if(d > 0 and a >= c and b <= d) return true;
            if(e > 0 and d == b and e + a >= c) return true;
            if(f > 0 and f + b >= d and b <= d and e + a >= c and e <= c) return true;
            
            f = e, e = d, d = c, c = b, b = a;
        }
        return false;
    }
};