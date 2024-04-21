class Solution {
public:
    int numberOfSpecialChars(string word) {
        long lo = 0, up = 0;
        auto masking = [](long& mask, int bit) {
            mask |= 1ll<<bit;
        };
        for(auto& w : word) {
            if(islower(w)) masking(lo,w-'a');
            else masking(up,w-'A');
        }
        return __builtin_popcountll(lo & up);
    }
};