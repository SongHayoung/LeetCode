class Solution {
public:
    int distinctPoints(string s, int k) {
        unordered_set<long long> mask;
        long long y = 0, x = 0;
        auto update = [&](int pos, int op) {
            if(s[pos] == 'U') y += op;
            if(s[pos] == 'D') y -= op;
            if(s[pos] == 'R') x += op;
            if(s[pos] == 'L') x -= op;
        };
        
        for(int i = 0; i < s.length(); i++) {
            update(i,1);
            if(i >= k) update(i-k,-1);
            if(i + 1 >= k) {
                long long bit = (abs(y)<<17) + abs(x);
                if(y < 0) bit ^= 1ll<<37;
                if(x < 0) bit ^= 1ll<<36;
                mask.insert(bit);
            }
            
        }
        return mask.size();
    }
};