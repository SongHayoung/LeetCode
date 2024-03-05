class Solution {
public:
    int minimumLength(string s) {
        int l = 0, r = s.length() - 1;
        while(l < r and s[l] == s[r]) {
            char target = s[l];
            int L = l, R = r;
            while(l <= R and s[l] == target) l++;
            while(L <= r and s[r] == target) r--;
        }
        return max(0, r - l + 1);
    }
};