class Solution {
public:
    int tripletCount(vector<int>& a, vector<int>& b, vector<int>& c) {
        int res = 0;
        for(auto& x : a) {
            for(auto& y : b) {
                for(auto& z : c) {
                    int bit = x ^ y ^ z;
                    if(__builtin_popcountll(bit) % 2 == 0) res++;
                }
            }
        }
        return res;
    }
};