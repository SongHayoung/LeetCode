class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(k == 0) return 0;
        vector<int> counter(128);
        int l = 0, r = 0, n = s.length(), unique = 0, res = 0;
        while(r < n) {
            if(counter[s[r++]]++ == 0) unique++;
            while(unique > k) {
                if(counter[s[l++]]-- == 1) unique--;
            }
            res = max(res, r - l);
        }
        return res;
    }
};