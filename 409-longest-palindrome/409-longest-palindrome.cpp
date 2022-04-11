class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> counter(128,0);
        for(auto ch : s) counter[ch]++;
        
        int res = 0;
        for(auto n : counter) {
            if(n&1 and !(res&1)) res++;
            res += n / 2 * 2;
        }
        return res;
    }
};