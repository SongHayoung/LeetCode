class Solution {
    bool bit(int x, int p) {
        return (x>>p) & 1;
    }
public:
    int getXORSum(vector<int>& A, vector<int>& B) {
        vector<int> freq(32);
        for(auto& b : B) {
            for(int i = 0; i < 32; i++) {
                if(bit(b,i)) freq[i]++;
            }
        }
        int res = 0;
        for(auto& a : A) {
            for(int i = 0; i < 32; i++) {
                if(!bit(a,i)) continue;
                if(freq[i] & 1) {
                    res ^= 1<<i;
                }
            }
        }
        
        return res;
    }
};