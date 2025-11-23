class Solution {
public:
    int minimumFlips(int n) {
        string bin = bitset<64>(n).to_string().substr(bitset<64>(n).to_string().find('1'));
        int res = 0, l = 0, r = bin.size() - 1;
        while(l < r) {
            if(bin[l] != bin[r]) res++;
            l++,r--;
        }
        return res<<1;
    }
};