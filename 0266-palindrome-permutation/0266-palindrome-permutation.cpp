class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char,int> freq;
        for(auto ch : s) freq[ch] += 1;
        int cnt = 0;
        for(auto [_,v] : freq) cnt += v % 2;
        return cnt <= 1;
    }
};