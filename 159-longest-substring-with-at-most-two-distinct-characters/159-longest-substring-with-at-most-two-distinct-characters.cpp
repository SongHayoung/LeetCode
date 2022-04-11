class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int res = 0, counts[128]{0,};
        for(int l = 0, r = 0, unique = 0; r < s.length(); r++) {
            if(!counts[s[r]]) unique++;
            counts[s[r]]++;
            while(unique > 2) {
                if(--counts[s[l]] == 0) unique--;
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};