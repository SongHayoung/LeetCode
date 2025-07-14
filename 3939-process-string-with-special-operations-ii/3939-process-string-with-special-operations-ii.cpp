
class Solution {
public:
    char processStr(string s, long long k) {
        long long len = 0, ma = 4e18;
        vector<long long> lens;
        for(auto& ch : s) {
            if(isalpha(ch)) len++;
            else if(ch == '*') len = max(len - 1, 0ll);
            else if(ch == '#') len = min(len * 2, ma);

            lens.push_back(len);
        }

        if(len <= k or len == 0) return '.';

        for(int i = s.length() - 1; i >= 0; i--) {
            if(isalpha(s[i])) {
                if(lens[i] - 1 == k) return s[i];
            } else if(s[i] == '#') {
                k = k % (lens[i] / 2);
            } else if(s[i] == '%') {
                k = lens[i] - k - 1;
            }
        }
        return '#';
    }
};