

class Solution {
    long long res;
    vector<int> even{2,4,6,8};
    long long stoll(string& s) {
        long long res = 0;
        for(int i = 0; i < s.length(); i++) {
            res = res * 10 + s[i] - '0';
        }
        return res;
    }
    long long create(vector<int> A) {
        sort(begin(A), end(A));
        int len = accumulate(begin(A), end(A), 0);
        string res = string(len, '#');
        int odd = 0;
        for(auto& x : A) if(x & 1) odd = x;
        if(odd) {
            res[len / 2] = '0' + odd;
        }
        int l = 0, r = len - 1;
        for(auto& x : A) {
            int cnt = x;
            while(cnt >= 2) {
                res[l] = res[r] = '0' + x;
                l++, r--;
                cnt -= 2;
            }
        }
        return stoll(res);
    }
    bool test(string& s, int l, int r, string& n, vector<int>& A, vector<int>& use) {
        if(s <= n) return false;
        if(l >= r) {
            res = min(res, stoll(s));
            return true;
        }
        for(int i = 0; i < A.size(); i++) {
            if(use[i] == A[i]) continue;
            use[i] += 2;
            s[l] = s[r] = '0' + A[i];

            if(test(s,l+1,r-1,n,A,use)) return true;

            use[i] -= 2;
            s[l] = s[r] = '9';
        }
        return false;
    }
    void helper(vector<int>& A, long long n) {
        int len = to_string(n).length();
        int buildLen = accumulate(begin(A), end(A), 0);
        if(len > buildLen) return;
        if(len < buildLen) {
            if(buildLen >= 16) return;
            res = min(res, create(A));
            return;
        }
        long long best = create(A);
        if(best > n) {
            res = min(res, best);
            return;
        }
        string str = string(buildLen, '9');
        vector<int> use(A.size(), 0);
        sort(begin(A), end(A));
        int odd = -1;
        for(int i = 0; i < A.size(); i++) if(A[i] & 1) odd = i;
        if(odd >= 0) {
            str[len / 2] = '0' + A[odd];
            use[odd] = 1;
        }
        string ns = to_string(n);
        test(str,0,str.length() - 1, ns, A, use);
    }
    void use(vector<int> A, int pos, long long n) {
        if(pos == 4) {
            helper(A, n);
            return;
        }
        A.push_back(even[pos]);
        use(A,pos+1,n);
        A.pop_back();
        use(A,pos+1,n);
    }
public:
    long long specialPalindrome(long long n) {
        res = LLONG_MAX;
        for(int i = 1; i <= 9; i += 2) {
            use({},0,n);
            use({i},0,n);
        }
        return res == LLONG_MAX ? -1 : res;
    }
};