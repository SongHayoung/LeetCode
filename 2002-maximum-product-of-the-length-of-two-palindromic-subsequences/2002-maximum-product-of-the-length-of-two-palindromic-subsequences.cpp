class Solution {
    bool palindrome(string s) {
        int l = 0, r = s.length() - 1;
        while(l < r) {
            if(s[l++] != s[r--]) return false;
        }
        return true;
    }
public:
    int maxProduct(string s) {
        int res = 0, n = s.length();
        vector<int> mask;
        for(int sub = 1; sub < 1<<n; sub++) {
            string now = "";
            for(int i = 0; i < n; i++) {
                if(sub & (1<<i)) now.push_back(s[i]);
            }
            if(palindrome(now)) mask.push_back(sub);
        }
        for(int i = 0; i < mask.size(); i++) {
            for(int j = i + 1; j < mask.size(); j++) {
                if(mask[i] & mask[j]) continue;
                res = max(res, __builtin_popcount(mask[i]) * __builtin_popcount(mask[j]));
            }
        }
        return res;
    }
};