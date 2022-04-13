class Solution {
public:
    string decodeAtIndex(string S, int K) {
        long len = 0;
        int i = 0;
        for(;len < K; i++) {
            if('0' <= S[i] && S[i] <= '9')
                len *= (S[i] & 0b1111);
            else
                ++len;
        }
        i--;
        for(; i >= 0; i--) {
            K %= len;
            if(!K && !('0' <= S[i] && S[i] <= '9'))
                return (string)"" + S[i];
            if('0' <= S[i] && S[i] <= '9')
                len /= (S[i] & 0b1111);
            else
                --len;
        }

        return "";
    }
};