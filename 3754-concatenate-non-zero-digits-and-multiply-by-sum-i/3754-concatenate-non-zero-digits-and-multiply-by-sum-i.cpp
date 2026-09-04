class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0, concat = 0;
        for(auto& ch : to_string(n)) {
            int x = ch - '0';
            if(x) {
                sum += x, concat = concat * 10 + x;
            }
        }
        return sum * concat;
    }
};