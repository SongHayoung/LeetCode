class Solution {
public:
    long long removeZeros(long long n) {
        return [](string s){ return accumulate(s.begin(), s.end(), 0LL, [](long long acc, char c){ return c=='0' ? acc : acc*10 + (c-'0'); }); }(to_string(n));
    }
};