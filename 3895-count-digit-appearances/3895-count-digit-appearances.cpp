class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int res = 0;
        for(auto& n : nums) {
            while(n) {
                res += digit == (n % 10);
                n /= 10;
            }
        }
        return res;
    }
};