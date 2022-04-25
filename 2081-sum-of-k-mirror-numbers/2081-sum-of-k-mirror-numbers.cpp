#define ll unsigned long long
#define vll vector<ll>
#define all(a) begin(a), end(a)

class Solution {
    bool kRadix(ll n, ll radix) {
        string k;
        while(n) {
            k.push_back((n % radix) | 0b110000);
            n /= radix;
        }
        reverse(all(k));
        return palindrome(k);
    }
    bool kRadix(string s, ll radix) {
        return kRadix(stoll(s), radix);
    }
    bool palindrome(string s) {
        ll i = 0, j = s.length() - 1;
        while(i < j)
            if(s[i++] != s[j--])
                return false;
        return true;
    }
public:
    long long kMirror(int k, int n) {
        ll res = 0;
        queue<string> q;
        for(ll i = 1; i <= 9 and n; i++) {
            q.push(to_string(i));
            if(kRadix(i,k)) {
                n--;
                res += i;
            }
        }
        
        while(n) {
            ll sz = q.size();
            while(n and sz--) {
                auto s = q.front(); q.pop();
                auto _s = s;
                reverse(all(_s));
                auto ss = _s + s;
                if(kRadix(ss,k)) {
                    n--;
                    res += stoll(ss);
                }
                q.push(s);
            }
            
            sz = q.size();
            while(n and sz--) {
                auto s = q.front(); q.pop();
                auto _s = s;
                reverse(all(_s));
                for(ll i = 0; i <= 9 and n; i++) {
                    auto ss = _s + string(1,i + '0') + s;
                    if(kRadix(ss,k)) {
                        n--;
                        res += stol(ss);
                    }
                    q.push(string(1,i+'0') + s);
                }
            }
        }
        
        return res;
    }
};