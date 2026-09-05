



vector<int> primes;

void init() {
    const int N = 31623;
    vector<bool> isPrime(N + 1, true);
    isPrime[0] = isPrime[1] = false;

    for(int i = 2; i * i <= N; i++) {
        if(isPrime[i]) {
            for(int j = i * i; j <= N; j += i)
                isPrime[j] = false;
        }
    }

    for(int i = 2; i <= N; i++)
        if(isPrime[i])
            primes.push_back(i);
}
bool isPrime(int x) {
    if(x < 2) return false;

    for(int p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if(x == p) return true;
        if(x % p == 0) return false;
    }

    int d = x - 1, s = 0;
    while(!(d & 1))
        d >>= 1, s++;

    auto power = [&](long long a, long long b) {
        long long res = 1;

        while(b) {
            if(b & 1)
                res = res * a % x;

            a = a * a % x;
            b >>= 1;
        }

        return res;
    };

    for(int a : {2, 3, 5, 7}) {
        if(a >= x) continue;

        long long y = power(a, d);

        if(y == 1 || y == x - 1)
            continue;

        bool ok = false;

        for(int i = 1; i < s; i++) {
            y = y * y % x;

            if(y == x - 1) {
                ok = true;
                break;
            }
        }

        if(!ok)
            return false;
    }

    return true;
}
vector<pair<int,int>> factor(int x) {
    vector<pair<int,int>> res;

    if(isPrime(x)) {
        res.push_back({x, 1});
        return res;
    }

    for(int p : primes) {
        if(1LL * p * p > x)
            break;

        if(x % p == 0) {
            int c = 0;

            while(x % p == 0) {
                x /= p;
                c++;
            }

            res.push_back({p, c});

            if(x > 1 && isPrime(x)) {
                res.push_back({x, 1});
                x = 1;
                break;
            }
        }
    }

    if(x > 1)
        res.push_back({x, 1});

    return res;
}
class Solution {
public:
    long long minOperations(vector<int>& nums) {
        init();
        int n = nums.size(), res = n, base = 0;
        sort(rbegin(nums), rend(nums));
        unordered_map<int,int> freq, reach, subs;
        while(nums.size()) {
            int x = nums.back(), cnt = 0;
            while(nums.size() and nums.back() == x) {
                cnt++;
                nums.pop_back();
            }
            if(x == 1) base += cnt;
            else {
                freq[x] += cnt;
                vector<int> divisor;
                for(auto& [f,c] : factor(x)) {
                    int sz = divisor.size();
                    for(int i = 0; i < sz; i++) {
                        for(int j = 0, mul = 1; j < c; j++) {
                            mul *= f;
                            divisor.push_back(mul * divisor[i]);
                        }
                    }
                    for(int i = 0, mul = 1; i < c; i++) {
                        mul *= f;
                        divisor.push_back(mul);
                    }
                }
                for(auto& d : divisor) {
                    if(d == 1) continue;
                    reach[d] += cnt;
                    if(freq.count(d)) subs[x] += freq[d];
                }
            }
        }
        for(auto& [k,v] : freq) {
            int single = base + reach[k] - 2 * v + subs[k];
            int two = n - single - v;
            res = min(res, single + two * 2);
        }
        return res;
    }
};
