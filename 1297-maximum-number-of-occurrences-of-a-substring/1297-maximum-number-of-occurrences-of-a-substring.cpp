class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> freq;
        int res = 0, n = s.length(), l = 0, r = 0, count = 0, counter[26] = {};
        while(r < n) {
            int R = s[r++] - 'a';
            if(++counter[R] == 1) count++;
            while(count > maxLetters or r - l > minSize) {
                int L = s[l++] - 'a';
                if(--counter[L] == 0) count--;
            }
            if(r - l == minSize)
                res = max(res, ++freq[s.substr(l, r - l)]);
        }
        return res;
    }
};