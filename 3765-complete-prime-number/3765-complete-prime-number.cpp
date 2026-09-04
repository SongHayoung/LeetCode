__int128 modpow128(__int128 n, __int128 x, __int128 mod) {
    __int128 res = 1;
    while(x) {
        if(x & 1) res = res * n % mod;
        n = n * n % mod;
        x /= 2;
    }
    return res;
}
bool millerRabin(long long n) {
    if(n == 2 or n == 3) return true;
    if(n == 1 or n % 2 == 0) return false;
    long long d = n - 1, s = 0;
    while(d % 2 == 0) s += 1, d /= 2;

    for(int _ = 0; _ < 10; _++) {
        __int128 a = 2 + rand() % (n - 3), x = modpow128(a,d,n);
        if(x == 1 or x == n - 1) continue;
        for(int r = 1; r < s; r++) {
            x = modpow128(x, 2, n);
            if (x == n - 1) break;
        }
        if (x != n - 1) return false;
    }
    return true;
}
class Solution {
public:
    bool completePrime(int num) {
        string s = to_string(num);
        for(int i = 0, x = 0; i < s.length(); i++) {
            x = x * 10 + s[i] - '0';
            if(!millerRabin(x)) return false;
        }
        for(int i = s.length() - 1, x = 0, acc = 1; i; i--, acc *= 10) {
            x += acc * (s[i] - '0');
            if(!millerRabin(x)) return false;
        }
        return true;
    }
};