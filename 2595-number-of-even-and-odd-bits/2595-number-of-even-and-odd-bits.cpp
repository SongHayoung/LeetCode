class Solution {
public:
    vector<int> evenOddBit(int n) {
        long long bit = 1;
        int e = 0, o = 0;
        for(long long i = 0; i < 32; i++) {
            if(n & bit) {
                if(i % 2) o += 1;
                else e += 1;
            }
            bit *= 2;
        }
        return {e,o};
    }
};