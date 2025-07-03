class Solution {
public:
    int countOddLetters(int n) {
        unordered_map<int,string> numbers = {
                {0, "zero"},
                {1, "one"},
                {2, "two"},
                {3, "three"},
                {4, "four"},
                {5, "five"},
                {6, "six"},
                {7, "seven"},
                {8, "eight"},
                {9, "nine"}
        };
        int res = 0;
        while(n) {
            int x = n % 10; n /= 10;
            for(auto& ch : numbers[x]) {
                res ^= 1<<(ch - 'a');
            }
        }
        
        return __builtin_popcount(res);
    }
};