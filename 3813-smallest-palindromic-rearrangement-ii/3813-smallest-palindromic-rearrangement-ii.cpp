class Solution {
    __int128 nCr(int n, int r) {
        __int128 res = 1;
        deque<int> rs;
        for(int i = r; i > 1; i--) rs.push_back(i);
        for(int i = 1; i <= r and res < 1e15; i++) {
            res *= (n - i + 1);
            while(rs.size() and res % rs[0] == 0) {
                res /= rs[0];
                rs.pop_front();
            }
        }
        return res;
    }
    pair<bool, int> calc(vector<int>& A, int limit) {
        int tot = accumulate(begin(A), end(A), 0ll);
        __int128 res = 1;
        for(int i = 0; i < A.size() and res <= limit; i++) {
            if(!A[i] or A[i] == tot) continue;
            res *= nCr(tot, A[i]);
            tot -= A[i];
        }
        return {res <= limit, res};
    }
    string helper(vector<int>& A, int k) {
        string res = "";
        int len = accumulate(begin(A), end(A), 0);
        for(int i = 0; i < len - 1; i++) {
            bool find = false;
            for(int j = 0; j < 26; j++) {
                if(!A[j]) continue;
                A[j] -= 1;
                auto [ok, cnt] = calc(A, k);
                if(!ok) {
                    res.push_back(j + 'a');
                    find = true;
                    break;
                }
                k -= cnt;
                A[j] += 1;
            }
            if(!find)
                return "";
        }
        if(k) return "";
        for(int i = 0; i < A.size(); i++) if(A[i]) res.push_back(i + 'a');
        return res;
    }
public:
    string smallestPalindrome(string s, int k) {
        if(s.length() <= 3) return k == 1 ? s : "";
        vector<int> freq(26);
        int n = s.length();
        for(int i = 0; i < n / 2; i++) freq[s[i]-'a']++;

        string pre = helper(freq, k - 1);
        string suf = pre;
        reverse(begin(suf), end(suf));
        if(pre == "") return "";
        if(n & 1) return pre + s[n/2] + suf;
        return pre + suf;
    }
};