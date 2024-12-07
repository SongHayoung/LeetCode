const int MAX_N = 10101;
class Solution {
    int sieve[MAX_N];
    void init() {
        memset(sieve, 0, sizeof sieve);
        sieve[0] = sieve[1] = 1;
        for(int i = 2; i < MAX_N; i++) {
            if(sieve[i]) continue;
            for(int j = i * i; j < MAX_N; j += i) sieve[j] = 1;
        }
    }
public:
    int minOperations(int n, int m) {
        init();
        vector<int> cost(MAX_N, INT_MAX);
        queue<pair<int, int>> q;
        auto push = [&](int x, int c) {
            if(!sieve[x]) return;
            if(cost[x] > c + x) {
                cost[x] = c + x;
                q.push({c + x,x});
            }
        };
        push(n,0);
        while(q.size()) {
            auto [c, val] = q.front(); q.pop();
            if(cost[val] != c) continue;
            string s = to_string(val);
            for(int i = s.length() - 1, po = 1; i >= 0; i--, po *= 10) {
                if(s[i] != '0') {
                    push(val - po, c);
                }
                if(s[i] != '9') {
                    push(val + po, c);
                }
            }
        }
        return cost[m] == INT_MAX ? -1 : cost[m];
    }
};