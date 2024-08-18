class Solution {
    vector<int> arr{1, 3, 2, 6, 4, 5};
    bool helper(string& s, int l, int r, int sum) {
        if(l > r) return sum == 0;
        int x = arr[(s.length() - l - 1) % 6] + arr[(s.length() - r - 1) % 6];
        if(l == r) x /= 2;
        for(int i = 9; i >= 0; i--) {
            s[l] = s[r] = i + '0';
            if(helper(s,l+1,r-1,(sum + x * i) % 7)) {
                return true;
            }
        }
        return false;
    }
public:
    string largestPalindrome(int n, int k) {
        if(k == 1) return string(n,'9');
        if(k == 2) {
            if(n == 1) return "8";
            return "8" + string(n-2,'9') + "8";
        }
        if(k == 3) return string(n,'9');
        if(k == 4) {
            if(n == 1) return "8";
            if(n == 2) return "88";
            if(n == 3) return "888";
            return "88" + string(n-4,'9') + "88";
        }
        if(k == 5) {
            if(n == 1) return "5";
            return "5" + string(n-2,'9') + "5";
        }
        if(k == 6) {
            if(n == 1) return "6";
            if(n == 2) return "66";
            string res = string(n,'9');
            if(n & 1) {
                res[0] = res[n-1] = res[n/2] = '8';
            } else {
                res[0] = res[n-1] = '8';
                res[n/2] = res[n/2-1] = '7';
            }
            return res;
        }
        if(k == 7) {
            string res(n,'0');
            helper(res,0,n-1,0);
            return res;
        }
        if(k == 8) {
            if(n <= 5) return string(n,'8');
            return "888" + string(n-6,'9') + "888";
        }
        if(k == 9) return string(n,'9');
        return "-1";
    }
};