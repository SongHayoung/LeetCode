
class Solution {
    int helper(string& b, string& s, int l, int r) {
        if(b < s) return 0;
        if(l == r) {
            s[l] = '1';
            if(helper(b,s,l+1,r-1)) return 2;
            s[l] = '0';
            return helper(b,s,l+1,r-1);
        }
        if(l > r) return 1;
        if(b[l] == '0') return helper(b,s,l+1,r-1);
        s[l] = s[r] = '1';
        return pow(2, (r - l) / 2) + helper(b,s,l+1,r-1);
    }
public:
    int countBinaryPalindromes(long long n) {
        if(n <= 1) return 1 + n;
        string binary = "";
        while(n) {
            binary.push_back((n % 2) +'0');
            n /= 2;
        }
        reverse(begin(binary), end(binary));
        int res = 2;
        for(int len = 2; len < binary.size(); len++) {
            res += pow(2,(len - 1) / 2 );
        }
        string now = string(binary.size(), '0');
        now.front() = now.back() = '1';
        res += helper(binary, now, 1, binary.size() - 2);
        return res;
    }
};
